#include <iostream>
#include <vector>
#include <string>
using namespace std;

char map[128];

void initMap() {
    int idx = 0;

    for (int i = 'A'; i <= 'Z'; i++) {
        map[i] = idx++;
    }
    for (int i = 'a'; i <= 'z'; i++) {
        map[i] = idx++;
    }
    for (int i = '0'; i <= '9'; i++) {
        map[i] = idx++;
    }
    map['+'] = idx++;
    map['-'] = idx;
}

string decode(string& enc) {
    string dec = "";

    for (int i = 0; i < enc.length(); i+=4) {
        int buffer = 0;

        for (int j = 0; j < 3; j++) {
            buffer += map[enc[i+j]];
            buffer = buffer << 6;
        }
        buffer += map[enc[i+3]];

        for (int j = 2; j >= 0; j--) {
            char ch = (buffer & 255 << (j*8)) >> j*8;
            dec.push_back(ch);
        }
    }

    return dec;
}

int main() {
    initMap();

    int T;
    cin >> T;
    for (int t=1;t<=T;t++) {
        string enc;
        cin >> enc;
        cout << '#' << t << ' ' << decode(enc) << endl;
    }
}