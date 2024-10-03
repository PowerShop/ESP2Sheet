#ifndef ESP2SHEET_H
#define ESP2SHEET_H

#include <Arduino.h>
#include <WiFi.h>
#include <HTTPClient.h>

class ESP2Sheet {
public:
    ESP2Sheet(const char* sheetId);
    String urlEncode(const char *str);
    void send(const char *data);

private:
    const char* _sheetId;
};

#endif // ESP2SHEET_H