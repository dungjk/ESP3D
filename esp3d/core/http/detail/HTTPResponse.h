#ifndef __RESPONSE_H__
#define __RESPONSE_H__

#include <map>
#include <Arduino.h>
#include <WiFi.h>

class HTTPResponse
{
public:
    HTTPResponse(WiFiClient &wifiClient)
        : _wifiClient(wifiClient)
    {
    }
    ~HTTPResponse() {}

    /**
     * Get headers
     **/
    std::map<String, String> &headers() { return _headers; }

    /**
     * Set response header
     **/
    HTTPResponse &header(String key, String value)
    {
        _headers.insert({key, value});
        return *this;
    }

    /**
     * Get header value
     **/
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

    size_t write(const char *c, size_t l)
    {
        return _wifiClient.write(c, l);
    }

    size_t write(String &b, size_t l)
    {
        return _wifiClient.write(b.c_str(), l);
    }
};

#endif