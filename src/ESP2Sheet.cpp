#include <ESP2Sheet.h>
#include "ESP2Sheet.h"

ESP2Sheet::ESP2Sheet(const char* sheetId) {
    _sheetId = sheetId;
}

String ESP2Sheet::urlEncode(const char* str) {
    String encodedText = "";
    char c;
    while ((c = *str++)) {
        if (isalnum(c) || c == '-' || c == '_' || c == '.' || c == '~' || c == '=') {
            encodedText += c;
        } else if (c == ' ') {
            encodedText += '+';
        } else {
            encodedText += '%';
            char hex[3];
            sprintf(hex, "%02X", c);
            encodedText += hex;
        }
    }
    return encodedText;
}

void ESP2Sheet::send(const char* data) {
    if (WiFi.status() == WL_CONNECTED) {
        HTTPClient http;

        // Clean the Data
        String encodedData = urlEncode(data);
        String url = "https://script.google.com/macros/s/" + String(_sheetId) + "/exec?" + encodedData;

        http.addHeader("Content-Type", "application/x-www-form-urlencoded");

        Serial.println("Making a request");

        http.begin(url.c_str()); // Specify the URL and certificate
        http.setFollowRedirects(HTTPC_STRICT_FOLLOW_REDIRECTS);
        int httpCode = http.GET();
        String payload;
        if (httpCode > 0) { // Check for the returning code
            payload = http.getString();
            Serial.println(httpCode);
            // Serial.println(payload);
        } else {
            Serial.println("Error on HTTP request");
        }
        http.end();
    } else {
        Serial.println("WiFi Disconnected");
    }
}