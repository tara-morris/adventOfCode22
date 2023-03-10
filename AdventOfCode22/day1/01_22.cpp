#include <iostream>
#include <string>
#include <fstream>

using namespace std;

int main() {
    ifstream infile("01_22_input.txt");

    int top[3];
    int cur = 0;
    string line;
    while(getline(infile, line)) {
        if (line.empty()) {
            if (top[0] < cur) {
                top[2] = top[1];
                top[1] = top[0];
                top[0] = cur;
            } else if (top[1] < cur) {
                top[2] = top[1];
                top[1] = cur;
            } else if (top[2] < cur) {
                top[2] = cur;
            }
            cur = 0;
            continue;
        }
        cur += stoi(line);
    }
    cout << "Answer1: " << top[0] << endl;
    cout << "Answer2: " << top[0] + top[1] + top[2] << endl;
}