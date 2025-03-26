#include "common/response.hpp"

Response<void> Response<void>::success()
{
    return Response<void>(OK);
}

Response<void>::Code Response<void>::getStatusCode() const
{
    return statusCode;
}

Response<void> Response<void>::failure(Code errorCode)
{
    return Response<void>(errorCode);
}

Response<void>::Response(Response<void>::Code statusCode) : statusCode { statusCode } { }