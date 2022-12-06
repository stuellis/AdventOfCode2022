#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int priority(char c) {
    int num = 0;
    if ( c >= 'a') {
        num = c - 'a' + 1;
    } else {
        num = c - 'A' + 27;
    }
    // cout << c << " -> " << num << endl;
    return num;
}

int partOne() {
    ifstream myfile ("input_3.txt");
    string line;

    int sum = 0;

    if (myfile.is_open()) {
        while (myfile) {
            getline(myfile, line);
            if (line.empty()) {
                break;
            }

            int halfLen = line.length() / 2;
            string a = line.substr(0, halfLen);
            string b = line.substr(halfLen, halfLen);
            // cout << "(" << line.length() << ") " << a << " || " << b << endl;

            for (char c : a) {
                size_t found = b.find(c);
                if (found != string::npos) {
                    sum += priority(c);
                    break;
                }
            }
        }
    }

    return sum;
}

int partTwo() {
    ifstream myfile ("input_3.txt");
    string elf1;
    string elf2;
    string elf3;

    int sum = 0;

    if (myfile.is_open()) {
        while (myfile) {
            getline(myfile, elf1);
            if (elf1.empty()) {
                break;
            }
            getline(myfile, elf2);
            getline(myfile, elf3);

            for (char c : elf1) {
                size_t found = elf2.find(c);
                if (found != string::npos) {
                    found = elf3.find(c);
                    if (found != string::npos) {
                        sum += priority(c);
                        break;
                    }
                }
            }
        }
    }

    return sum;
}

int main() {

    int sum1 = partOne();
    int sum2 = partTwo();

    cout << "Part 1 SUM:" << sum1 << endl;
    cout << "Part 2 SUM:" << sum2 << endl;

}
