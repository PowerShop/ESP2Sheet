#include <ESP2Sheet.h>

const char *WIFI_SSID = "YOUR_WIFI_SSID";
const char *WIFI_PASS = "YOUR_WIFI_PASSWORD";

// Replace with your Google Sheets script ID
const char* sheetId = "YOUR_GOOGLE_SHEETS_SCRIPT_ID";

ESP2Sheet esp2Sheet(sheetId);

void setup()
{
    Serial.begin(115200);
    WiFi.begin(WIFI_SSID, WIFI_PASS);

    while (WiFi.status() != WL_CONNECTED)
    {
        delay(1000);
        Serial.println("Connecting to WiFi...");
    }
    Serial.println("Connected to WiFi");
}

void loop()
{
    esp2Sheet.send("text=TestESP2Sheet");
    delay(10000); // Wait for 10 seconds
}


