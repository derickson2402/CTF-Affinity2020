#include <iostream>
#include <string>
#include <vector>
#include <typeinfo>

using namespace std;

// partial flag AGHFXK{5ai5b1cee10z}
// normal style AFFCTF{Pr0p3r_C0ms_aR3_4lways_g00d!}

// Change a char to a Caesar letter
int char2letter(char c) {
    
    if (('0' <= c) && (c <= '9')) {
        int pos = c - '0';
        cout << "Char " << c << " converted to pos " << pos << endl;
        return pos;
    }

    if ('a' <= c && c <= 'z') {
        int pos = c - 'a' + 10;
        cout << "Char " << c << " converted to pos " << pos << endl;
        return pos;
    }

    // ignore the brackets
    int pos = c;
    cout << "Char " << c << " converted to pos " << pos << endl;
    return pos;
}

// Change a Caesar letter to a char
char letter2char(int c) {
    
    if (0 <= c && c <= 9) {
        char letter = '0' + c;
        cout << "Changed int " << c << " to char " << letter << endl;
        return letter;
    }

    if (10 <= c && c <= 35) {
        char letter = 'a' + c - 10;
        cout << "Changed int " << c << " to char " << letter << endl;
        return letter;
    }
    
    // ignore the brackets
    char letter = c;
    cout << "Changed int " << c << " to char " << letter << endl;
    return letter;
}

// Encode a Caesar letter
int caesarShiftEncode(int l, int offset) {
    // ignore the brackets
    if (l > 36) {return l;}

    int position = (l + offset) % 36;
    if (position < 0) {
        position = position + 36;
    }
    return position;
}

// Decode a Caesar letter
int caesarShiftDecode(int l, int offset) {
    // ignore the brackets
    if (l > 36) {return l;}
    
    int position = (l - offset);
    
    if (position < 0) {
        cout << "Position " << l << " shifted to " << position << endl;
        return position + 35;
    }
    cout << "Position " << l << " shifted to " << position << endl;
    return position;
}

int main() {
    
    cout << "Enter string to decrypt: ";
    string cryptFlag = ""; cin >> cryptFlag;
    
    vector<char> vectorCryptFlag;
    for (int c = 0; c < cryptFlag.size(); ++c) {
        vectorCryptFlag.push_back(cryptFlag[c]);
    }

    vector<char> vectorFlag = vectorCryptFlag;
    
    string Flag = "";

    // Change all the chars to Caesar letters
    for (int n = 0; n < vectorCryptFlag.size(); ++n) {
        vectorFlag[n] = char2letter(vectorFlag[n]);
        vectorFlag[n] = caesarShiftDecode(vectorFlag[n], n);
        vectorFlag[n] = letter2char(vectorFlag[n]);
        Flag = Flag + vectorFlag[n];
    }
    
    cout << Flag << endl;
}

