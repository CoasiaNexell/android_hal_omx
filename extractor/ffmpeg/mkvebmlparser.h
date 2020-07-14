// Copyright (c) 2012 The WebM project authors. All Rights Reserved.
//
// Use of this source code is governed by a BSD-style license
// that can be found in the LICENSE file in the root of the source
// tree. An additional intellectual property rights grant can be found
// in the file PATENTS.  All contributing project authors may
// be found in the AUTHORS file in the root of the source tree.
#ifndef MKVPARSER_EVMLPARSER_H_
#define MKVPARSER_EVMLPARSER_H_

#include <media/MediaSource.h>
#include <media/DataSourceBase.h>
#include <media/ExtractorUtils.h>
#include <media/MediaTrack.h>
#include <media/stagefright/foundation/ADebug.h>
#include <media/stagefright/foundation/AUtils.h>
#include <media/stagefright/foundation/ABuffer.h>

long long EBMLHeaderParser_Parse(android::DataSourceBase* pSource, long long& pos);

#endif  // MKVPARSER_EVMLPARSER_H_
