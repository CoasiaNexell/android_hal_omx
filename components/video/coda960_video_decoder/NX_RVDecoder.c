#define	LOG_TAG				"NX_RVDEC"

#include <assert.h>
#include <OMX_AndroidTypes.h>
#include <system/graphics.h>

#include "NX_OMXVideoDecoder.h"
#include "NX_DecoderUtil.h"

int NX_DecodeRVFrame(NX_VIDDEC_VIDEO_COMP_TYPE *pDecComp, NX_QUEUE *pInQueue, NX_QUEUE *pOutQueue)
{
	OMX_BUFFERHEADERTYPE* pInBuf = NULL, *pOutBuf = NULL;
	int inSize = 0;
	OMX_BYTE inData;
	NX_V4L2DEC_IN decIn;
	NX_V4L2DEC_OUT decOut;
	int ret = 0;

	UNUSED_PARAM(pOutQueue);

	memset(&decIn,  0, sizeof(decIn)  );

	if( pDecComp->bFlush )
	{
		flushVideoCodec( pDecComp );
		pDecComp->bFlush = OMX_FALSE;
		pDecComp->inFlushFrameCount = 0;
		pDecComp->bIsFlush = OMX_TRUE;
		pDecComp->tmpInputBufferIndex = 0;
	}

	NX_PopQueue( pInQueue, (void**)&pInBuf );
	if( pInBuf == NULL ){
		return 0;
	}

	inData = pInBuf->pBuffer;
	inSize = pInBuf->nFilledLen;
	pDecComp->inFrameCount++;

	TRACE("pInBuf->nFlags = 0x%08x, size = %ld, timeStamp = %lld\n", (int)pInBuf->nFlags, pInBuf->nFilledLen, pInBuf->nTimeStamp );

	if( pInBuf->nFlags & OMX_BUFFERFLAG_EOS )
	{
		DbgMsg("=========================> Receive Endof Stream Message (%ld)\n", pInBuf->nFilledLen);

		pDecComp->bStartEoS = OMX_TRUE;
		if( inSize <= 0)
		{
			pInBuf->nFilledLen = 0;
			pDecComp->pCallbacks->EmptyBufferDone(pDecComp->hComp, pDecComp->hComp->pApplicationPrivate, pInBuf);
			return 0;
		}
	}

	//	Step 1. Found Sequence Information
	if( OMX_FALSE == pDecComp->bInitialized )
	{
		if( pDecComp->codecSpecificData )
		{
			free(pDecComp->codecSpecificData);
			pDecComp->codecSpecificData = NULL;
		}
		//	RV Sequence Need Addtional 26 bytes but we allocate 128 bytes additionally.
		pDecComp->codecSpecificData = malloc(pDecComp->nExtraDataSize);
		memcpy(pDecComp->codecSpecificData, pDecComp->pExtraData, pDecComp->nExtraDataSize);
		pDecComp->codecSpecificDataSize = pDecComp->nExtraDataSize;
	}

	//{
	//	OMX_U8 *buf = pInBuf->pBuffer;
	//	DbgMsg("pInBuf->nFlags(%7d) = 0x%08x, 0x%02x%02x%02x%02x, 0x%02x%02x%02x%02x, 0x%02x%02x%02x%02x, 0x%02x%02x%02x%02x, 0x%02x%02x%02x%02x, 0x%02x%02x%02x%02x\n", pInBuf->nFilledLen, pInBuf->nFlags,
	//		buf[ 0],buf[ 1],buf[ 2],buf[ 3],buf[ 4],buf[ 5],buf[ 6],buf[ 7],
	//		buf[ 8],buf[ 9],buf[10],buf[11],buf[12],buf[13],buf[14],buf[15],
	//		buf[16],buf[17],buf[18],buf[19],buf[20],buf[21],buf[22],buf[23] );
	//}

	//	Push Input Time Stamp
	PushVideoTimeStamp(pDecComp, pInBuf->nTimeStamp, pInBuf->nFlags );


	//	Step 2. Find First Key Frame & Do Initialize VPU
	if( OMX_FALSE == pDecComp->bInitialized )
	{
		int32_t size = pDecComp->codecSpecificDataSize;
		memcpy( pDecComp->tmpInputBuffer, pDecComp->codecSpecificData, pDecComp->codecSpecificDataSize );
		memcpy( pDecComp->tmpInputBuffer + size, inData, inSize );
		size += inSize;

		//	Initialize VPU
		ret = InitializeCodaVpu(pDecComp, pDecComp->tmpInputBuffer, size );
		if( 0 != ret )
		{
			ErrMsg("VPU initialized Failed!!!!\n");
			goto Exit;
		}

		pDecComp->bNeedKey = OMX_FALSE;
		pDecComp->bInitialized = OMX_TRUE;

		//decIn.strmBuf = pDecComp->tmpInputBuffer;
		//decIn.strmSize = 0;
		//decIn.timeStamp = pInBuf->nTimeStamp;
		//decIn.eos = 0;
		//ret = NX_V4l2DecDecodeFrame( pDecComp->hVpuCodec, &decIn, &decOut );
		decOut.dispIdx = -1;
	}
	else
	{

		if( pDecComp->bIsFlush )
		{
			if( pInBuf->nFlags & OMX_BUFFERFLAG_CODECCONFIG )
			{
				goto Exit;
			}
			memcpy( pDecComp->tmpInputBuffer + pDecComp->tmpInputBufferIndex, inData, inSize );
			pDecComp->tmpInputBufferIndex = pDecComp->tmpInputBufferIndex + inSize;
			pDecComp->inFlushFrameCount++;
			if( FLUSH_FRAME_COUNT == pDecComp->inFlushFrameCount)
			{
				pDecComp->inFlushFrameCount = 0;
				pDecComp->bIsFlush = OMX_FALSE;
				inData = pDecComp->tmpInputBuffer;
				inSize = pDecComp->tmpInputBufferIndex;
				pDecComp->tmpInputBufferIndex = 0;
			}
			else
			{
				goto Exit;
			}
		}

		decIn.strmBuf = inData;
		decIn.strmSize = inSize;
		decIn.timeStamp = pInBuf->nTimeStamp;
		decIn.eos = 0;
		ret = NX_V4l2DecDecodeFrame( pDecComp->hVpuCodec, &decIn, &decOut );
	}

	TRACE(">>> [%06ld/%06ld] decOut : dispIdx(%d) decIdx(%d) \n",
		pDecComp->inFrameCount, pDecComp->outFrameCount, decOut.dispIdx, decOut.decIdx );


	if( ret==VID_ERR_NONE && decOut.dispIdx >= 0 && ( decOut.dispIdx < NX_OMX_MAX_BUF ) )
	{
		if( OMX_TRUE == pDecComp->bEnableThumbNailMode )
		{
			//	Thumbnail Mode
			OMX_U8 *plu = NULL;
			OMX_U8 *pcb = NULL;
			OMX_U8 *pcr = NULL;
			OMX_S32 luStride = 0;
			OMX_S32 luVStride = 0;
			OMX_S32 cStride = 0;
			OMX_S32 cVStride = 0;

			NX_VID_MEMORY_INFO *pImg = &decOut.hImg;
			NX_PopQueue( pOutQueue, (void**)&pOutBuf );

			luStride = ALIGN(pDecComp->width, 32);
			luVStride = ALIGN(pDecComp->height, 16);
			cStride = luStride/2;
			cVStride = ALIGN(pDecComp->height/2, 16);
			plu = (OMX_U8 *)pImg->pBuffer[0];
			pcb = plu + luStride * luVStride;
			pcr = pcb + cStride * cVStride;

			CopySurfaceToBufferYV12( (OMX_U8*)plu, (OMX_U8*)pcb, (OMX_U8*)pcr,
				pOutBuf->pBuffer, luStride, cStride, pDecComp->width, pDecComp->height );

			NX_V4l2DecClrDspFlag( pDecComp->hVpuCodec, NULL, decOut.dispIdx );
			pOutBuf->nFilledLen = pDecComp->width * pDecComp->height * 3 / 2;
			if( 0 != PopVideoTimeStamp(pDecComp, &pOutBuf->nTimeStamp, &pOutBuf->nFlags )  )
			{
				pOutBuf->nTimeStamp = pInBuf->nTimeStamp;
				pOutBuf->nFlags     = pInBuf->nFlags;
			}
			TRACE("ThumbNail Mode : pOutBuf->nAllocLen = %ld, pOutBuf->nFilledLen = %ld\n", pOutBuf->nAllocLen, pOutBuf->nFilledLen );
			pDecComp->outFrameCount++;
			pDecComp->pCallbacks->FillBufferDone(pDecComp->hComp, pDecComp->hComp->pApplicationPrivate, pOutBuf);
		}
		else
		{
			//	Native Window Buffer Mode
			//	Get Output Buffer Pointer From Output Buffer Pool
			pOutBuf = pDecComp->pOutputBuffers[decOut.dispIdx];

			if( pDecComp->outBufferUseFlag[decOut.dispIdx] == 0 )
			{
				OMX_TICKS timestamp;
				OMX_U32 flag;
				PopVideoTimeStamp(pDecComp, &timestamp, &flag );
				NX_V4l2DecClrDspFlag( pDecComp->hVpuCodec, NULL, decOut.dispIdx );
				ErrMsg("Unexpected Buffer Handling!!!! Goto Exit\n");
				goto Exit;
			}
			pDecComp->outBufferValidFlag[decOut.dispIdx] = 1;
			pDecComp->outBufferUseFlag[decOut.dispIdx] = 0;
			pDecComp->curOutBuffers --;

			pOutBuf->nFilledLen = sizeof(struct private_handle_t);
			if( 0 != PopVideoTimeStamp(pDecComp, &pOutBuf->nTimeStamp, &pOutBuf->nFlags )  )
			{
				pOutBuf->nTimeStamp = pInBuf->nTimeStamp;
				pOutBuf->nFlags     = pInBuf->nFlags;
			}
			TRACE("nTimeStamp = %lld\n", pOutBuf->nTimeStamp/1000);
			pDecComp->outFrameCount++;
			pDecComp->pCallbacks->FillBufferDone(pDecComp->hComp, pDecComp->hComp->pApplicationPrivate, pOutBuf);
		}
	}

Exit:
	pInBuf->nFilledLen = 0;
	pDecComp->pCallbacks->EmptyBufferDone(pDecComp->hComp, pDecComp->hComp->pApplicationPrivate, pInBuf);

	return ret;
}
