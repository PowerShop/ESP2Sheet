#include <ESP2Sheet.h>

ESP2Sheet::ESP2Sheet(const char *sheetId)
{
    _sheetId = sheetId;
}

void ESP2Sheet::send(const char *data)
{
    if (WiFi.status() == WL_CONNECTED)
    {
        HTTPClient http;

        String url = "https://script.google.com/macros/s/" + String(_sheetId) + "/exec?" + String(data);

        http.addHeader("Content-Type", "application/x-www-form-urlencoded");

        http.begin(url.c_str()); // Specify the URL and certificate
        http.setFollowRedirects(HTTPC_STRICT_FOLLOW_REDIRECTS);
        int httpCode = http.GET();
        String payload;
        if (httpCode > 0)
        { // Check for the returning code
            payload = http.getString();
        }
        else
        {
            Serial.println("Error on HTTP request");
        }
        http.end();
    }
    else
    {
        Serial.println("WiFi Disconnected");
    }
}