// Copyright (c) 2012 The WebM project authors. All Rights Reserved.
//
// Use of this source code is governed by a BSD-style license
// that can be found in the LICENSE file in the root of the source
// tree. An additional intellectual property rights grant can be found
// in the file PATENTS.  All contributing project authors may
// be found in the AUTHORS file in the root of the source tree.


//======================================================================
// Copyright (c) 2012 The WebM project authors. All Rights Reserved.
//
// Use of this source code is governed by a BSD-style license
// that can be found in the LICENSE file in the root of the source
// tree. An additional intellectual property rights grant can be found
// in the file PATENTS.  All contributing project authors may
// be found in the AUTHORS file in the root of the source tree.

#ifndef COMMON_WEBMIDS_H_
#define COMMON_WEBMIDS_H_

namespace libwebm {

enum MkvId {
  kMkvEBML = 0x1A45DFA3,
  kMkvEBMLVersion = 0x4286,
  kMkvEBMLReadVersion = 0x42F7,
  kMkvEBMLMaxIDLength = 0x42F2,
  kMkvEBMLMaxSizeLength = 0x42F3,
  kMkvDocType = 0x4282,
  kMkvDocTypeVersion = 0x4287,
  kMkvDocTypeReadVersion = 0x4285,
  kMkvVoid = 0xEC,
  kMkvSignatureSlot = 0x1B538667,
  kMkvSignatureAlgo = 0x7E8A,
  kMkvSignatureHash = 0x7E9A,
  kMkvSignaturePublicKey = 0x7EA5,
  kMkvSignature = 0x7EB5,
  kMkvSignatureElements = 0x7E5B,
  kMkvSignatureElementList = 0x7E7B,
  kMkvSignedElement = 0x6532,
  // segment
  kMkvSegment = 0x18538067,
  // Meta Seek Information
  kMkvSeekHead = 0x114D9B74,
  kMkvSeek = 0x4DBB,
  kMkvSeekID = 0x53AB,
  kMkvSeekPosition = 0x53AC,
  // Segment Information
  kMkvInfo = 0x1549A966,
  kMkvTimecodeScale = 0x2AD7B1,
  kMkvDuration = 0x4489,
  kMkvDateUTC = 0x4461,
  kMkvTitle = 0x7BA9,
  kMkvMuxingApp = 0x4D80,
  kMkvWritingApp = 0x5741,
  // Cluster
  kMkvCluster = 0x1F43B675,
  kMkvTimecode = 0xE7,
  kMkvPrevSize = 0xAB,
  kMkvBlockGroup = 0xA0,
  kMkvBlock = 0xA1,
  kMkvBlockDuration = 0x9B,
  kMkvReferenceBlock = 0xFB,
  kMkvLaceNumber = 0xCC,
  kMkvSimpleBlock = 0xA3,
  kMkvBlockAdditions = 0x75A1,
  kMkvBlockMore = 0xA6,
  kMkvBlockAddID = 0xEE,
  kMkvBlockAdditional = 0xA5,
  kMkvDiscardPadding = 0x75A2,
  // Track
  kMkvTracks = 0x1654AE6B,
  kMkvTrackEntry = 0xAE,
  kMkvTrackNumber = 0xD7,
  kMkvTrackUID = 0x73C5,
  kMkvTrackType = 0x83,
  kMkvFlagEnabled = 0xB9,
  kMkvFlagDefault = 0x88,
  kMkvFlagForced = 0x55AA,
  kMkvFlagLacing = 0x9C,
  kMkvDefaultDuration = 0x23E383,
  kMkvMaxBlockAdditionID = 0x55EE,
  kMkvName = 0x536E,
  kMkvLanguage = 0x22B59C,
  kMkvCodecID = 0x86,
  kMkvCodecPrivate = 0x63A2,
  kMkvCodecName = 0x258688,
  kMkvCodecDelay = 0x56AA,
  kMkvSeekPreRoll = 0x56BB,
  // video
  kMkvVideo = 0xE0,
  kMkvFlagInterlaced = 0x9A,
  kMkvStereoMode = 0x53B8,
  kMkvAlphaMode = 0x53C0,
  kMkvPixelWidth = 0xB0,
  kMkvPixelHeight = 0xBA,
  kMkvPixelCropBottom = 0x54AA,
  kMkvPixelCropTop = 0x54BB,
  kMkvPixelCropLeft = 0x54CC,
  kMkvPixelCropRight = 0x54DD,
  kMkvDisplayWidth = 0x54B0,
  kMkvDisplayHeight = 0x54BA,
  kMkvDisplayUnit = 0x54B2,
  kMkvAspectRatioType = 0x54B3,
  kMkvFrameRate = 0x2383E3,
  // end video
  // colour
  kMkvColour = 0x55B0,
  kMkvMatrixCoefficients = 0x55B1,
  kMkvBitsPerChannel = 0x55B2,
  kMkvChromaSubsamplingHorz = 0x55B3,
  kMkvChromaSubsamplingVert = 0x55B4,
  kMkvCbSubsamplingHorz = 0x55B5,
  kMkvCbSubsamplingVert = 0x55B6,
  kMkvChromaSitingHorz = 0x55B7,
  kMkvChromaSitingVert = 0x55B8,
  kMkvRange = 0x55B9,
  kMkvTransferCharacteristics = 0x55BA,
  kMkvPrimaries = 0x55BB,
  kMkvMaxCLL = 0x55BC,
  kMkvMaxFALL = 0x55BD,
  // mastering metadata
  kMkvMasteringMetadata = 0x55D0,
  kMkvPrimaryRChromaticityX = 0x55D1,
  kMkvPrimaryRChromaticityY = 0x55D2,
  kMkvPrimaryGChromaticityX = 0x55D3,
  kMkvPrimaryGChromaticityY = 0x55D4,
  kMkvPrimaryBChromaticityX = 0x55D5,
  kMkvPrimaryBChromaticityY = 0x55D6,
  kMkvWhitePointChromaticityX = 0x55D7,
  kMkvWhitePointChromaticityY = 0x55D8,
  kMkvLuminanceMax = 0x55D9,
  kMkvLuminanceMin = 0x55DA,
  // end mastering metadata
  // end colour
  // audio
  kMkvAudio = 0xE1,
  kMkvSamplingFrequency = 0xB5,
  kMkvOutputSamplingFrequency = 0x78B5,
  kMkvChannels = 0x9F,
  kMkvBitDepth = 0x6264,
  // end audio
  // ContentEncodings
  kMkvContentEncodings = 0x6D80,
  kMkvContentEncoding = 0x6240,
  kMkvContentEncodingOrder = 0x5031,
  kMkvContentEncodingScope = 0x5032,
  kMkvContentEncodingType = 0x5033,
  kMkvContentCompression = 0x5034,
  kMkvContentCompAlgo = 0x4254,
  kMkvContentCompSettings = 0x4255,
  kMkvContentEncryption = 0x5035,
  kMkvContentEncAlgo = 0x47E1,
  kMkvContentEncKeyID = 0x47E2,
  kMkvContentSignature = 0x47E3,
  kMkvContentSigKeyID = 0x47E4,
  kMkvContentSigAlgo = 0x47E5,
  kMkvContentSigHashAlgo = 0x47E6,
  kMkvContentEncAESSettings = 0x47E7,
  kMkvAESSettingsCipherMode = 0x47E8,
  kMkvAESSettingsCipherInitData = 0x47E9,
  // end ContentEncodings
  // Cueing Data
  kMkvCues = 0x1C53BB6B,
  kMkvCuePoint = 0xBB,
  kMkvCueTime = 0xB3,
  kMkvCueTrackPositions = 0xB7,
  kMkvCueTrack = 0xF7,
  kMkvCueClusterPosition = 0xF1,
  kMkvCueBlockNumber = 0x5378,
  // Chapters
  kMkvChapters = 0x1043A770,
  kMkvEditionEntry = 0x45B9,
  kMkvChapterAtom = 0xB6,
  kMkvChapterUID = 0x73C4,
  kMkvChapterStringUID = 0x5654,
  kMkvChapterTimeStart = 0x91,
  kMkvChapterTimeEnd = 0x92,
  kMkvChapterDisplay = 0x80,
  kMkvChapString = 0x85,
  kMkvChapLanguage = 0x437C,
  kMkvChapCountry = 0x437E,
  // Tags
  kMkvTags = 0x1254C367,
  kMkvTag = 0x7373,
  kMkvSimpleTag = 0x67C8,
  kMkvTagName = 0x45A3,
  kMkvTagString = 0x4487
};

}  // namespace libwebm

#endif  // COMMON_WEBMIDS_H_
//=======================================================================

#define E_FILE_FORMAT_INVALID -2
#define E_BUFFER_NOT_FULL     -3

#include "mkvebmlparser.h"

namespace android {

typedef struct EBMLHeaderSt {
  long long m_version;
  long long m_readVersion;
  long long m_maxIdLength;
  long long m_maxSizeLength;
  char* m_docType;
  long long m_docTypeVersion;
  long long m_docTypeReadVersion;
} EBMLHeaderSt;

static void EBMLHeaderParser_Init(EBMLHeaderSt *pEBMLHeader)
{
  pEBMLHeader->m_version = 1;
  pEBMLHeader->m_readVersion = 1;
  pEBMLHeader->m_maxIdLength = 4;
  pEBMLHeader->m_maxSizeLength = 8;

  if (pEBMLHeader->m_docType) {
    delete[] pEBMLHeader->m_docType;
    pEBMLHeader->m_docType = NULL;
  }

  pEBMLHeader->m_docTypeVersion = 1;
  pEBMLHeader->m_docTypeReadVersion = 1;
}

static void EBMLHeaderParser_Close(EBMLHeaderSt *pEBMLHeader)
{
  if (pEBMLHeader->m_docType) {
    delete[] pEBMLHeader->m_docType;
    pEBMLHeader->m_docType = NULL;
  }
}

template <typename Type>
static Type* EBMLHeaderParser_SafeArrayAlloc(unsigned long long num_elements,
                     unsigned long long element_size)
{

  if (num_elements == 0 || element_size == 0)
    return NULL;

  const size_t kMaxAllocSize = 0x80000000;  // 2GiB
  const unsigned long long num_bytes = num_elements * element_size;
  if (element_size > (kMaxAllocSize / num_elements))
    return NULL;
  if (num_bytes != static_cast<size_t>(num_bytes))
    return NULL;

  return new (std::nothrow) Type[static_cast<size_t>(num_bytes)];
}

static int EBMLHeaderParser_GetRead(DataSourceBase* pSource, long long position, long length, unsigned char* buffer)
{
  CHECK(position >= 0);
  CHECK(length >= 0);

  if (length == 0) {
      return 0;
  }

  ssize_t n = pSource->readAt(position, buffer, length);

  if (n <= 0) {
    return -1;
  }

  return 0;
}

static int EBMLHeaderParser_GetLength(DataSourceBase* pSource, long long* total, long long* available)
{
  off64_t size;
  if (pSource->getSize(&size) != OK) {
    *total = -1;
    *available = (long long)((1ull << 63) - 1);

    return 0;
  }

  if (total) {
    *total = size;
  }

  if (available) {
    *available = size;
  }

  return 0;
} 

static long long EBMLHeaderParser_ReadUInt(DataSourceBase* pSource, long long pos, long& len)
{
  if (!pSource || pos < 0)
    return E_FILE_FORMAT_INVALID;

  len = 1;
  unsigned char b;
  int status = EBMLHeaderParser_GetRead(pSource, pos, 1, &b);

  if (status < 0)  // error or underflow
    return status;

  if (status > 0)  // interpreted as "underflow"
    return E_BUFFER_NOT_FULL;

  if (b == 0)  // we can't handle u-int values larger than 8 bytes
    return E_FILE_FORMAT_INVALID;

  unsigned char m = 0x80;

  while (!(b & m)) {
    m >>= 1;
    ++len;
  }

  long long result = b & (~m);
  ++pos;

  for (int i = 1; i < len; ++i) {
    status = EBMLHeaderParser_GetRead(pSource, pos, 1, &b);

    if (status < 0) {
      len = 1;
      return status;
    }

    if (status > 0) {
      len = 1;
      return E_BUFFER_NOT_FULL;
    }

    result <<= 8;
    result |= b;

    ++pos;
  }

  return result;
}

// Reads an EBML ID and returns it.
// An ID must at least 1 byte long, cannot exceed 4, and its value must be
// greater than 0.
// See known EBML values and EBMLMaxIDLength:
// http://www.matroska.org/technical/specs/index.html
// Returns the ID, or a value less than 0 to report an error while reading the
// ID.
static long long EBMLHeaderParser_ReadID(DataSourceBase* pSource, long long pos, long& len)
{
  if (pSource == NULL || pos < 0)
    return E_FILE_FORMAT_INVALID;

  // Read the first byte. The length in bytes of the ID is determined by
  // finding the first set bit in the first byte of the ID.
  unsigned char temp_byte = 0;
  int read_status = EBMLHeaderParser_GetRead(pSource, pos, 1, &temp_byte);

  if (read_status < 0)
    return E_FILE_FORMAT_INVALID;
  else if (read_status > 0)  // No data to read.
    return E_BUFFER_NOT_FULL;

  if (temp_byte == 0)  // ID length > 8 bytes; invalid file.
    return E_FILE_FORMAT_INVALID;

  int bit_pos = 0;
  const int kMaxIdLengthInBytes = 4;
  const int kCheckByte = 0x80;

  // Find the first bit that's set.
  bool found_bit = false;
  for (; bit_pos < kMaxIdLengthInBytes; ++bit_pos) {
    if ((kCheckByte >> bit_pos) & temp_byte) {
      found_bit = true;
      break;
    }
  }

  if (!found_bit) {
    // The value is too large to be a valid ID.
    return E_FILE_FORMAT_INVALID;
  }

  // Read the remaining bytes of the ID (if any).
  const int id_length = bit_pos + 1;
  long long ebml_id = temp_byte;
  for (int i = 1; i < id_length; ++i) {
    ebml_id <<= 8;
    read_status = EBMLHeaderParser_GetRead(pSource, pos + i, 1, &temp_byte);

    if (read_status < 0)
      return E_FILE_FORMAT_INVALID;
    else if (read_status > 0)
      return E_BUFFER_NOT_FULL;

    ebml_id |= temp_byte;
  }

  len = id_length;
  return ebml_id;
}

static long long EBMLHeaderParser_GetUIntLength(DataSourceBase* pSource, long long pos, long& len)
{
  if (!pSource || pos < 0)
    return E_FILE_FORMAT_INVALID;

  long long total, available;

  int status = EBMLHeaderParser_GetLength(pSource, &total, &available);
  if (status < 0 || (total >= 0 && available > total))
    return E_FILE_FORMAT_INVALID;

  len = 1;

  if (pos >= available)
    return pos;  // too few bytes available

  unsigned char b;

  status = EBMLHeaderParser_GetRead(pSource, pos, 1, &b);

  if (status != 0)
    return status;

  if (b == 0)  // we can't handle u-int values larger than 8 bytes
    return E_FILE_FORMAT_INVALID;

  unsigned char m = 0x80;

  while (!(b & m)) {
    m >>= 1;
    ++len;
  }

  return 0;  // success
}

static long EBMLHeaderParser_UnserializeString(DataSourceBase* pSource, long long pos, long long size,
                       char*& str)
{
  delete[] str;
  str = NULL;

  if (size >= LONG_MAX || size < 0)
    return E_FILE_FORMAT_INVALID;

  // +1 for '\0' terminator
  const long required_size = static_cast<long>(size) + 1;

  str = EBMLHeaderParser_SafeArrayAlloc<char>(1, required_size);
  if (str == NULL)
    return E_FILE_FORMAT_INVALID;

  unsigned char* const buf = reinterpret_cast<unsigned char*>(str);

  const long status = EBMLHeaderParser_GetRead(pSource, pos, static_cast<long>(size), buf);

  if (status) {
    delete[] str;
    str = NULL;

    return status;
  }

  str[required_size - 1] = '\0';
  return 0;
}

static long EBMLHeaderParser_ParseElementHeader(DataSourceBase* pSource, long long& pos, long long stop,
                        long long& id, long long& size)
{
  if (stop >= 0 && pos >= stop)
    return E_FILE_FORMAT_INVALID;

  long len;

  id = EBMLHeaderParser_ReadID(pSource, pos, len);

  if (id < 0)
    return E_FILE_FORMAT_INVALID;

  pos += len;  // consume id

  if (stop >= 0 && pos >= stop)
    return E_FILE_FORMAT_INVALID;

  size = EBMLHeaderParser_ReadUInt(pSource, pos, len);

  if (size < 0 || len < 1 || len > 8) {
    // Invalid: Negative payload size, negative or 0 length integer, or integer
    // larger than 64 bits (libwebm cannot handle them).
    return E_FILE_FORMAT_INVALID;
  }

  // Avoid rolling over pos when very close to LLONG_MAX.
  const unsigned long long rollover_check =
      static_cast<unsigned long long>(pos) + len;
  if (rollover_check > LLONG_MAX)
    return E_FILE_FORMAT_INVALID;

  pos += len;  // consume length of size

  // pos now designates payload

  if (stop >= 0 && pos > stop)
    return E_FILE_FORMAT_INVALID;

  return 0;  // success
}

// TODO(vigneshv): This function assumes that unsigned values never have their
// high bit set.
static long long EBMLHeaderParser_UnserializeUInt(DataSourceBase* pSource, long long pos, long long size)
{
  if (!pSource || pos < 0 || (size <= 0) || (size > 8))
    return E_FILE_FORMAT_INVALID;

  long long result = 0;

  for (long long i = 0; i < size; ++i) {
    unsigned char b;

    const long status = EBMLHeaderParser_GetRead(pSource, pos, 1, &b);

    if (status < 0)
      return status;

    result <<= 8;
    result |= b;

    ++pos;
  }

  return result;
}

long long EBMLHeaderParser_Parse(DataSourceBase* pSource, long long& pos)
{
  if (!pSource)
    return E_FILE_FORMAT_INVALID;

  long long total, available;
  EBMLHeaderSt EBMLHeaderStructure;
  memset(&EBMLHeaderStructure, 0x00, sizeof(EBMLHeaderSt));

  long status = EBMLHeaderParser_GetLength(pSource, &total, &available);

  if (status < 0)  // error
    return status;

  pos = 0;

  // Scan until we find what looks like the first byte of the EBML header.
  const long long kMaxScanBytes = (available >= 1024) ? 1024 : available;
  const unsigned char kEbmlByte0 = 0x1A;
  unsigned char scan_byte = 0;

  while (pos < kMaxScanBytes) {
    status = EBMLHeaderParser_GetRead(pSource, pos, 1, &scan_byte);

    if (status < 0)  // error
      return status;
    else if (status > 0)
      return E_BUFFER_NOT_FULL;

    if (scan_byte == kEbmlByte0)
      break;

    ++pos;
  }

  long len = 0;
  const long long ebml_id = EBMLHeaderParser_ReadID(pSource, pos, len);

  if (ebml_id == E_BUFFER_NOT_FULL)
    return E_BUFFER_NOT_FULL;

  if (len != 4 || ebml_id != libwebm::kMkvEBML)
    return E_FILE_FORMAT_INVALID;

  // Move read pos forward to the EBML header size field.
  pos += 4;

  // Read length of size field.
  long long result = EBMLHeaderParser_GetUIntLength(pSource, pos, len);

  if (result < 0)  // error
    return E_FILE_FORMAT_INVALID;
  else if (result > 0)  // need more data
    return E_BUFFER_NOT_FULL;

  if (len < 1 || len > 8)
    return E_FILE_FORMAT_INVALID;

  if ((total >= 0) && ((total - pos) < len))
    return E_FILE_FORMAT_INVALID;

  if ((available - pos) < len)
    return pos + len;  // try again later

  // Read the EBML header size.
  result = EBMLHeaderParser_ReadUInt(pSource, pos, len);

  if (result < 0)  // error
    return result;

  pos += len;  // consume size field

  // pos now designates start of payload

  if ((total >= 0) && ((total - pos) < result))
    return E_FILE_FORMAT_INVALID;

  if ((available - pos) < result)
    return pos + result;

  const long long end = pos + result;

  EBMLHeaderParser_Init(&EBMLHeaderStructure);

  while (pos < end) {
    long long id, size;

    status = EBMLHeaderParser_ParseElementHeader(pSource, pos, end, id, size);

    if (status < 0)  // error
    {
      EBMLHeaderParser_Close(&EBMLHeaderStructure);
      return status;
    }

    if (size == 0)
    {
      EBMLHeaderParser_Close(&EBMLHeaderStructure);
      return E_FILE_FORMAT_INVALID;
    }

    if (id == libwebm::kMkvEBMLVersion) {
      EBMLHeaderStructure.m_version = EBMLHeaderParser_UnserializeUInt(pSource, pos, size);

      if (EBMLHeaderStructure.m_version <= 0)
      {
        EBMLHeaderParser_Close(&EBMLHeaderStructure);
        return E_FILE_FORMAT_INVALID;
      }
    } else if (id == libwebm::kMkvEBMLReadVersion) {
      EBMLHeaderStructure.m_readVersion = EBMLHeaderParser_UnserializeUInt(pSource, pos, size);

      if (EBMLHeaderStructure.m_readVersion <= 0)
      {
        EBMLHeaderParser_Close(&EBMLHeaderStructure);
        return E_FILE_FORMAT_INVALID;
      }
    } else if (id == libwebm::kMkvEBMLMaxIDLength) {
      EBMLHeaderStructure.m_maxIdLength = EBMLHeaderParser_UnserializeUInt(pSource, pos, size);

      if (EBMLHeaderStructure.m_maxIdLength <= 0)
      {
        EBMLHeaderParser_Close(&EBMLHeaderStructure);
        return E_FILE_FORMAT_INVALID;
      }
    } else if (id == libwebm::kMkvEBMLMaxSizeLength) {
      EBMLHeaderStructure.m_maxSizeLength = EBMLHeaderParser_UnserializeUInt(pSource, pos, size);

      if (EBMLHeaderStructure.m_maxSizeLength <= 0)
      {
        EBMLHeaderParser_Close(&EBMLHeaderStructure);
        return E_FILE_FORMAT_INVALID;
      }
    } else if (id == libwebm::kMkvDocType) {
      if (EBMLHeaderStructure.m_docType)
      {
        EBMLHeaderParser_Close(&EBMLHeaderStructure);
        return E_FILE_FORMAT_INVALID;
      }

      status = EBMLHeaderParser_UnserializeString(pSource, pos, size, EBMLHeaderStructure.m_docType);

      if (status)  // error
      {
        EBMLHeaderParser_Close(&EBMLHeaderStructure);
        return status;
      }
    } else if (id == libwebm::kMkvDocTypeVersion) {
      EBMLHeaderStructure.m_docTypeVersion = EBMLHeaderParser_UnserializeUInt(pSource, pos, size);

      if (EBMLHeaderStructure.m_docTypeVersion <= 0)
      {
        EBMLHeaderParser_Close(&EBMLHeaderStructure);
        return E_FILE_FORMAT_INVALID;
      }
    } else if (id == libwebm::kMkvDocTypeReadVersion) {
      EBMLHeaderStructure.m_docTypeReadVersion = EBMLHeaderParser_UnserializeUInt(pSource, pos, size);

      if (EBMLHeaderStructure.m_docTypeReadVersion <= 0)
      {
        EBMLHeaderParser_Close(&EBMLHeaderStructure);
        return E_FILE_FORMAT_INVALID;
      }
    }

    pos += size;
  }

  if (pos != end)
  {
    EBMLHeaderParser_Close(&EBMLHeaderStructure);
    return E_FILE_FORMAT_INVALID;
  }

  // Make sure DocType, DocTypeReadVersion, and DocTypeVersion are valid.
  if (EBMLHeaderStructure.m_docType == NULL || EBMLHeaderStructure.m_docTypeReadVersion <= 0 || EBMLHeaderStructure.m_docTypeVersion <= 0)
  {
    EBMLHeaderParser_Close(&EBMLHeaderStructure);
    return E_FILE_FORMAT_INVALID;
  }

  // Make sure EBMLMaxIDLength and EBMLMaxSizeLength are valid.
  if (EBMLHeaderStructure.m_maxIdLength <= 0 || EBMLHeaderStructure.m_maxIdLength > 4 || EBMLHeaderStructure.m_maxSizeLength <= 0 ||
      EBMLHeaderStructure.m_maxSizeLength > 8)
  {
    EBMLHeaderParser_Close(&EBMLHeaderStructure);
    return E_FILE_FORMAT_INVALID;
  }

  EBMLHeaderParser_Close(&EBMLHeaderStructure);

  return 0;
}

} // namespace android