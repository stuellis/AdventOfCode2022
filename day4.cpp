#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main() {
    ifstream myfile ("input_4.txt");
    string line;

    int countContained = 0;
    int countOverlap = 0;

    if (myfile.is_open()) {
        while (myfile) {
            getline(myfile, line);
            if(line.empty()) {
                break;
            }
            // cout << line << endl;

            int a1, a2, b1, b2;
            sscanf(line.c_str(), "%d-%d,%d-%d", &a1, &a2, &b1, &b2);

            // Part 1: one assignment fully contains the other
            if ((b1 >= a1 && b2 <= a2) || (a1 >= b1 && a2 <= b2)) {
                // cout << "contained" << endl;
                countContained++;
            }

            // Part 2: the assignments have any overlap
            if ((b1 >= a1 && b1 <= a2) || (a1 >= b1 && a1 <= b2)) {
                // cout << "overlap" << endl;
                countOverlap++;
            }
        }
    }

    cout << "Part 1 COUNT: " << countContained << endl;
    cout << "Part 2 COUNT: " << countOverlap << endl;
}
