# ESP2Sheet 📊
A lightweight library to easily send data from an ESP32 to Google Sheets.

## 🚀 Quick Start

1. **Create a Google Sheet**  
   Head over to [Google Sheets](https://docs.google.com/spreadsheets) and create your own spreadsheet.

2. **Setup Google Apps Script**  
   - Open the Google Sheet you created.
   - Go to **Extensions** > **Apps Script**.
   - Replace the default code with the following script:

   ```js
   function doGet(e) {
       // Create a variable for receiving data
       var text = e.parameter.text;

       // Call the function to send data to Google Sheets
       var sheetUrl = "https://docs.google.com/spreadsheets/d/XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX/edit?gid=0";
       var ss = SpreadsheetApp.openByUrl(sheetUrl);
       var ws = ss.getSheetByName("YOUR_SHEET_NAME");
       ws.appendRow([new Date(), text]);
   }
- Deploy this script as a Web App and note down your YOUR_GOOGLE_SHEETS_SCRIPT_ID

## ⚙️ Configuration
Update the following credentials in your ESP32 code:
```cpp
const char *WIFI_SSID = "YOUR_WIFI_SSID";
const char *WIFI_PASS = "YOUR_WIFI_PASSWORD";
const char* sheetId = "YOUR_GOOGLE_SHEETS_SCRIPT_ID";
```
- WIFI_SSID: Your WiFi network name.
- WIFI_PASS: Your WiFi password.
- sheetId: Your Google Sheets script ID obtained from the Web App deployment.

# 🛠️ Usage
Example code to send data from an ESP32 to your Google Sheet:
```cpp
#include <ESP2Sheet.h>

const char *WIFI_SSID = "YOUR_WIFI_SSID";
const char *WIFI_PASS = "YOUR_WIFI_PASSWORD";
const char *sheetId = "YOUR_GOOGLE_SHEETS_SCRIPT_ID";

ESP2Sheet esp2Sheet(sheetId);

void setup() {
    Serial.begin(115200);
    WiFi.begin(WIFI_SSID, WIFI_PASS);

    while (WiFi.status() != WL_CONNECTED) {
        delay(1000);
        Serial.println("Connecting to WiFi...");
    }
    Serial.println("Connected to WiFi");
}

void loop() {
    esp2Sheet.send("text=TestESP2Sheet");
    delay(10000); // Wait 10 seconds before sending again
}
```
---
## 📞 Contact

If you have any questions or need further assistance, feel free to reach out!

- **Facebook**: [Min Sakmueng](https://www.facebook.com/Min.Sakmueng)
- **Email**: [aaaxcvg@gmail.com](mailto:aaaxcvg@gmail.com)
