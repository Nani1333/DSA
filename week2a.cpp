#include <iostream>
#include <string>
using namespace std;

// Define special characters as strings
const string FLAG = "flag";   // Frame delimiter
const string ESC = "esc";     // Escape character

string characterStuffing(const string& data) {
    string stuffedData;
    stuffedData += FLAG;  // Start frame with FLAG

    size_t pos = 0;
    while (pos < data.length()) {
        if (data.substr(pos, FLAG.length()) == FLAG || data.substr(pos, ESC.length()) == ESC) {
            stuffedData += ESC;  // Add escape character before special strings
        }
        stuffedData += data[pos++];
    }

    stuffedData += FLAG;  // End frame with FLAG
    return stuffedData;
}

string characterDestuffing(const string& stuffedData) {
    string destuffedData;
    bool inEscape = false;
    size_t pos = 0;

    while (pos < stuffedData.length()) {
        if (inEscape) {
            if (stuffedData.substr(pos, FLAG.length()) == FLAG || stuffedData.substr(pos, ESC.length()) == ESC) {
                destuffedData += stuffedData.substr(pos, FLAG.length());  // Add the escaped string as is
                pos += FLAG.length();
            } else {
                destuffedData += ESC;  // Add the ESC string back if needed
                destuffedData += stuffedData[pos++];
            }
            inEscape = false;  // Reset the escape flag
        } else if (stuffedData.substr(pos, ESC.length()) == ESC) {
            inEscape = true;  // Set the escape flag
            pos += ESC.length();
        } else if (stuffedData.substr(pos, FLAG.length()) == FLAG) {
            // Handle frame delimiters if needed
            // You might want to ignore FLAG strings here
            pos += FLAG.length();
        } else {
            destuffedData += stuffedData[pos++];  // Normal character
        }
    }

    return destuffedData;
}

int main() {
    string data;
    cout << "Enter the data to be framed (use special strings like 'flag' or 'esc'): ";
    getline(cin, data);

    string stuffed = characterStuffing(data);
    string destuffed = characterDestuffing(stuffed);

    cout << "Original Data: " << data << endl;
    cout << "Stuffed Data: " << stuffed << endl;
    cout << "Destuffed Data: " << destuffed << endl;

    return 0;
}
