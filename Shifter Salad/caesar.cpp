#include <string>
#include <vector>
#include "caesar.h"

using namespace std;

string encrypt_word(const string &text, int offset) {
    string encrypted = text;
    for(int i = 0; i < text.size(); ++i) {
        encrypted[i] = shift_letter(encrypted[i], offset);
    }
    return encrypted;
}

char shift_letter(char c, int offset) {
    // compute original letter "position"
    int pos = c - 'a';

    // adjust position by offset, mod 26
    pos = (pos + offset) % 26;

    if (pos < 0) {
        pos = pos + 26;
    }

    // convert "position" back to letter
    return 'a' + pos;
}