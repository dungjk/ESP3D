#ifndef __REQUEST_H__
#define __REQUEST_H__

#include <map>
#include <WiFi.h>

class HTTPRequest
{
public:
    HTTPRequest(WiFiClient &client)
    {
        _wifiClient = client;
    }
    ~HTTPRequest() {}

    std::map<String, String> &headers() { return _headers; }

    String header(String key)
    {
        auto elm = _headers.find(key);
        if (elm != _headers.end())
        {
            return elm->first;
        }
        return "";
    }

private:
    WiFiClient _wifiClient;
    std::map<String, String> _headers;
};

#endif