# ESP2Sheet
Simple Library for EPS32 to send data to Google Sheet
</hr>
# Usage

```js
function doGet(e) {
    // Create your attribute for receiving data
    var text = e.parameter.text;

    // Call the function to send data to Google Sheets
    var urls="https://docs.google.com/spreadsheets/d/XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX/edit?gid=0";
    var ss=SpreadsheetApp.openByUrl(urls);
    var ws=ss.getSheetByName("YOUR_SHEET_NAME");
    ws.appendRow([new Date(),text]);
}
```
