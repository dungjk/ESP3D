#ifndef __HTTPHANDLEFUNCTION_H__
#define __HTTPHANDLEFUNCTION_H__

#include <functional>

#include "HTTPRequest.h"
#include "HTTPResponse.h"

/**
 * \brief A function that use to handle HTTP request
 */
typedef void(HTTPHandleFunction)(HTTPRequest &req, HTTPResponse& resp);

/**
 * \brief A middleware function that use to handle HTTP request
 */
typedef void(HTTPMiddlewareFunction)(HTTPRequest &req, HTTPResponse& resp, std::function<void()> next);

#endif
