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

#ifndef EMAILHEADERPARSER_H_
#define EMAILHEADERPARSER_H_

#include <map>
#include <stdexcept>
#include "data/CommonData.h"

class Rfc822StringTokenizer;

class HeaderParseException : public std::runtime_error
{
public:
	explicit HeaderParseException (const std::string& what_arg) : std::runtime_error(what_arg) {}
};

class EmailHeaderFieldParser
{
public:
	typedef std::map<std::string, std::string> ParameterMap;

	void ParseTextField(const std::string& line, std::string& outValue);
	void ParseContentTypeField(const std::string& line, std::string& outType, std::string& outSubType, ParameterMap& outParameters);
	void ParseContentDispositionField(const std::string& line, std::string& outDisposition, ParameterMap& outParameters);
	void ParseAddressListField(const std::string& line, EmailAddressList& outAddressList);
	void ParseDateField(const std::string& line, time_t& time);

	bool ParseEmailHeaderField(Email& email, const std::string& fieldNameLower, const std::string& fieldValue);
	bool ParsePartHeaderField(EmailPart& part, const std::string& fieldNameLower, const std::string& fieldValue);

protected:
	void ParseFieldParameters(Rfc822StringTokenizer& tokenizer, ParameterMap& outParameters);
	void ParseAddressList(Rfc822StringTokenizer& tokenizer, EmailAddressList& outAddressList, bool mailboxOnly);
	void ParseAddress(Rfc822StringTokenizer& tokenizer, EmailAddressList& outAddressList, bool mailboxOnly);
};

#endif /* EMAILHEADERPARSER_H_ */
