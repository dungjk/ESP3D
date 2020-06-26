#ifndef REQUESTHANDLER_H
#define REQUESTHANDLER_H

#include <vector>
#include <assert.h>

#include "HTTPHandlerFunction.h"

class RequestHandler
{
public:
    virtual ~RequestHandler() {}
    virtual bool canHandle(HTTPMethod method, String uri)
    {
        (void)method;
        (void)uri;
        return false;
    }
    virtual bool canUpload(String uri)
    {
        (void)uri;
        return false;
    }
    virtual bool handle(WebServer &server, HTTPMethod requestMethod, String requestUri)
    {
        (void)server;
        (void)requestMethod;
        (void)requestUri;
        return false;
    }
    virtual void upload(WebServer &server, String requestUri, HTTPUpload &upload)
    {
        (void)server;
        (void)requestUri;
        (void)upload;
    }

    RequestHandler &use(const HTTPMiddlewareFunction *middleware)
    {
        _middlewares.push_back(middleware);
        return *this;
    }

    RequestHandler *next() { return _next; }
    void next(RequestHandler *r) { _next = r; }

private:
    RequestHandler *_next = nullptr;

protected:
    std::vector<String> pathArgs;
    std::vector<HTTPMiddlewareFunction *> _middlewares;
    HTTPHandleFunction* _handleFunc;

public:
    const String &pathArg(unsigned int i)
    {
        assert(i < pathArgs.size());
        return pathArgs[i];
    }
};

#endif //REQUESTHANDLER_H
