#include <iostream>
#include <fstream>
#include <string>

using namespace std;

#define CHARS 14

int main() {
    ifstream myfile ("input_6.txt");
    string line;

    if (myfile.is_open()) {
        while (myfile) {
            getline(myfile, line);
            if(line.empty()) {
                break;
            }
            // cout << line << endl;

            int clearCount = 0;
            int processed = 0;

            for (int pos = 0; pos < line.length(); pos++){
                string s = line.substr(pos, CHARS);
                // cout << "> " << s << endl;
                bool clear = true;

                for (int i = 1; i < CHARS; i++) {
                    char c = s.at(i-1);
                    string sub = s.substr(i, CHARS - i);
                    size_t found = sub.find(c);
                    // cout << "(" << pos << ") " << c << " :: " << sub;
                    if (found != string::npos) {
                        // cout << " >> " << found << endl;
                        clear = false;
                        break;
                    } else {
                        clearCount++;
                        // cout << " >> clear " << clearCount << endl;
                    }
                }
                if (clear) {
                    processed = pos + CHARS;
                    break;
                }
            
            }

            cout << "Processed for " << CHARS << ": " << processed << endl;
        }
    }

}
