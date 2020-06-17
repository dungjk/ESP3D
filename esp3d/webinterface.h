/*
  webinterface.h - ESP3D configuration class

  Copyright (c) 2014 Luc Lebosse. All rights reserved.

  This library is free software; you can redistribute it and/or
  modify it under the terms of the GNU Lesser General Public
  License as published by the Free Software Foundation; either
  version 2.1 of the License, or (at your option) any later version.

  This library is distributed in the hope that it will be useful,
  but WITHOUT ANY WARRANTY; without even the implied warranty of
  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
  Lesser General Public License for more details.

  You should have received a copy of the GNU Lesser General Public
  License along with this library; if not, write to the Free Software
  Foundation, Inc., 51 Franklin St, Fifth Floor, Boston, MA  02110-1301  USA
*/

#ifndef WEBINTERFACE_h
#define WEBINTERFACE_h
#include <Arduino.h>
#include <WiFiClient.h>
#include <WiFiServer.h>
#ifndef FS_NO_GLOBALS
#define FS_NO_GLOBALS
#endif
#include <FS.h>
#include "core/http/WebServer.h"

struct auth_ip
{
  IPAddress ip;
  level_authenticate_type level;
  char userID[17];
  char sessionID[17];
  uint32_t last_time;
  auth_ip *_next;
};

class WEBINTERFACE_CLASS
{
public:
  WEBINTERFACE_CLASS(int port = 80);
  ~WEBINTERFACE_CLASS();
  WebServer web_server;
  bool restartmodule;
  String getContentType(String filename);
  level_authenticate_type is_authenticated();
  bool AddAuthIP(auth_ip *item);
  bool blockserial;
#ifdef AUTHENTICATION_FEATURE
  level_authenticate_type ResetAuthIP(IPAddress ip, const char *sessionID);
  auth_ip *GetAuth(IPAddress ip, const char *sessionID);
  bool ClearAuthIP(IPAddress ip, const char *sessionID);
  char *create_session_ID();
#endif
  uint8_t _upload_status;

private:
  auth_ip *_head;
  uint8_t _nb_ip;
};

extern WEBINTERFACE_CLASS *web_interface;

#endif
