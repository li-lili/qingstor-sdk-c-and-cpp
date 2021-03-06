// +-------------------------------------------------------------------------
// | Copyright (C) 2017 Yunify, Inc.
// +-------------------------------------------------------------------------
// | Licensed under the Apache License, Version 2.0 (the "License");
// | you may not use this work except in compliance with the License.
// | You may obtain a copy of the License in the LICENSE file, or at:
// |
// | http://www.apache.org/licenses/LICENSE-2.0
// |
// | Unless required by applicable law or agreed to in writing, software
// | distributed under the License is distributed on an "AS IS" BASIS,
// | WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// | See the License for the specific language governing permissions and
// | limitations under the License.
// +-------------------------------------------------------------------------

#pragma once

#include  "QsSdkOption.h"
#include  "QsErrors.h"
#include  "HttpCommon.h"
#include  <string>
#include  <vector>
#include  <memory>
#include  "types/ACLType.h"
#include  "types/BucketType.h"
#include  "types/ConditionType.h"
#include  "types/CORSRuleType.h"
#include  "types/GranteeType.h"
#include  "types/IPAddressType.h"
#include  "types/IsNullType.h"
#include  "types/KeyType.h"
#include  "types/KeyDeleteErrorType.h"
#include  "types/NotIPAddressType.h"
#include  "types/ObjectPartType.h"
#include  "types/OwnerType.h"
#include  "types/StatementType.h"
#include  "types/StringLikeType.h"
#include  "types/StringNotLikeType.h"
#include  "types/UploadsType.h"

namespace QingStor
{

struct ResponseErrorInfo
{
    std::string code;
    std::string message;
    std::string requestID;
    std::string url;
};

typedef QsBaseType QsInput;

class QS_SDK_API QsOutput:public QsBaseType
{
public:
    QsOutput():m_responseCode(Http::REQUEST_NOT_MADE)
    {
    };

    QsOutput(QsError err,
             Http::
             HttpResponseCode responseCode):m_responseCode(responseCode)
    {
    };

    virtual ~ QsOutput()
    {
    };

    virtual bool IsVaild()
    {
        return true;
    };

    inline std::string GetRequestID() const
    {
        return m_requestID;
    };

    inline Http::HttpResponseCode GetResponseCode() const
    {
        return m_responseCode;
    };

    inline ResponseErrorInfo GetResponseErrInfo() const
    {
        return m_errorInfo;
    };

    inline void SetRequestID(const std::string & requestID)
    {
        m_requestID = requestID;
    };

    inline void SetResponseCode(Http::HttpResponseCode responseCode)
    {
        m_responseCode = responseCode;
    };

    inline void SetResponseErrInfo(const ResponseErrorInfo & errorInfo)
    {
        m_errorInfo = errorInfo;
    };

protected:
    std::string m_requestID;

    Http::HttpResponseCode m_responseCode;

    ResponseErrorInfo m_errorInfo;
};

// Properties presents the service properties.
struct Properties
{

    // Bucket name
    std::string BucketName;	// Required

    // Object key
    std::string ObjectKey;	// Required

    // QingCloud Zone ID
    std::string Zone;

};

}								// namespace QingStor
