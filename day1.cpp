#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;

bool cmp (int i, int j) { return (i>j); }

int main() {
    ifstream myfile ("input_1.txt");
    string line;

    vector<int> calories;
    int currentElfTotal = 0;

    if (myfile.is_open()) {
        while (myfile) {
            getline(myfile, line);
            // cout << line << endl;

            if (line.length() < 1) {
                calories.push_back(currentElfTotal);
                currentElfTotal = 0;
            } else {
                int num = stoi(line);
                currentElfTotal += num;
            }
        }
    }

    sort(calories.begin(), calories.end(), cmp);

    cout << "Part 1 (top 1): " << calories.at(0) << endl;
    cout << "Part 2 (top 3): " << calories.at(0) + calories.at(1) + calories.at(2) << endl;
}
