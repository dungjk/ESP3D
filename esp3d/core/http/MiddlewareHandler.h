#ifndef __MIDDLEWAREHANDLER_H__
#define __MIDDLEWAREHANDLER_H__

#include <vector>
#include <algorithm>

#include "HTTPHandlerFunction.h"
#include "HTTPRequest.h"
#include "HTTPResponse.h"

std::function<void()> BuildMiddlewareHandleChain(std::vector<HTTPHandleFunction*> &middlewares, HTTPRequest &req, HTTPResponse &resp, std::function<void()> &next) {
    std::function<void()> newNext = next;
    if(middlewares.size()){
        auto itMw = middlewares.rbegin();
        while(itMw != middlewares.rend()){
            newNext = std::function<void()>(std::bind((*itMw), &req, &resp, next));
            itMw++;
        }
    }
    return next;
}

class RequestHandler {
public:
  RequestHandler(){}
  ~RequestHandler(){
    _middleware.clear();
  }

  RequestHandler* use(const HTTPHandleFunction* middleware){
    _middleware.push_back(middleware);
    return this;
  }

private:
  std::vector<const HTTPHandleFunction*> _middleware;
};

#endif
