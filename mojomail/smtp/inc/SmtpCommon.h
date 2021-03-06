// @@@LICENSE
//
//      Copyright (c) 2010-2012 Hewlett-Packard Development Company, L.P.
//
// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
//
// http://www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.
//
// LICENSE@@@

#ifndef SMTPCOMMON_H_
#define SMTPCOMMON_H_

#include <string>
#include <glib.h>
#include <boost/shared_ptr.hpp>
#include "core/MojCoreDefs.h"
#include "core/MojSignal.h"
#include "core/MojObject.h"
#include "core/MojRefCount.h"
#include "core/MojErr.h"

#include "exceptions/MailException.h"
#include "exceptions/MojErrException.h"

#define ErrorToException(err) \
	do { \
		if(unlikely(err)) MojErrException::CheckErr(err, __FILE__, __LINE__); \
	} while(0);

#define ResponseToException(response, err) \
	do { \
		if(unlikely(err)) MojErrException::CheckErr(response, err, __FILE__, __LINE__); \
	} while(0);

inline std::string AsJsonString(const MojObject& obj)
{
	MojString str;
	MojErr err = obj.toJson(str);
	ErrorToException(err);
	return std::string(str.data());
}

using namespace std;

#endif /*SMTPCOMMON_H_*/
