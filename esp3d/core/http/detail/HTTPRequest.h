#ifndef __REQUEST_H__
#define __REQUEST_H__

#include <WiFi.h>

class HTTPRequest {
public:
    HTTPRequest(WiFiClient &client){
        _client = client;
    }
    ~HTTPRequest(){}
private:
    WiFiClient _client;
};

#endif