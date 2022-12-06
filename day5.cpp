#include <iostream>
#include <fstream>
#include <string>
#include <stack>
#include <vector>

using namespace std;

#define STACKS 9
#define PART 2

void printStack(stack<char> s, int stackNum) {
    cout << "stack " << stackNum << endl;
    stack<char> toPrint(s);
    while(toPrint.size() > 0) {
        cout << toPrint.top() << endl;
        toPrint.pop();
    }
}

int main() {
    ifstream myfile ("input_5.txt");
    string line;

    stack<char> s1;
    stack<char> s2;
    stack<char> s3;
    stack<char> s4;
    stack<char> s5;
    stack<char> s6;
    stack<char> s7;
    stack<char> s8;
    stack<char> s9;

    vector<stack <char> > stacks(9);
    stacks.push_back(s1);
    stacks.push_back(s2);
    stacks.push_back(s3);
    stacks.push_back(s4);
    stacks.push_back(s5);
    stacks.push_back(s6);
    stacks.push_back(s7);
    stacks.push_back(s8);
    stacks.push_back(s9);

    bool firstSection = true;
    string delim = "[";

    if (myfile.is_open()) {
        while (myfile) {
            getline(myfile, line);

            if (line.empty()) {
                if (firstSection) {
                    firstSection = false;

                    // Reverse order of read stacks
                    for(int s = 0; s < STACKS; s++) {
                        stack<char> temp;
                        while(stacks[s].size() > 0) {
                            temp.push(stacks[s].top());
                            stacks[s].pop();
                        }
                        stacks[s].swap(temp);

                        // printStack(stacks[s], s+1);
                    }
                } else {
                    break;
                }
            } else {
                // cout << line << endl;

                if (firstSection) {
                    // Read starting stacks
                    size_t found = line.find(delim);
                    while (found != string::npos) {
                        string crate = line.substr(found, 3);
                        char letter = crate.at(1);
                        int stack = found / 4;
                        // cout << found << " (" << stack << "): " << crate << " >> "  << letter << endl;
                        stacks[stack].push(letter);
                        size_t start = found + 2;
                        found = line.find(delim, start);
                    }
                } else {
                    // Execute move instructions
                    int num, stackA, stackB;
                    sscanf(line.c_str(), "move %d from %d to %d", &num, &stackA, &stackB);
                    // cout << num << ":" << stackA << ":" << stackB << endl;


                    // Part 1 or Part 2 of puzzel
                    if (PART == 1) {
                        // Move crates 1 at a time
                        for (int i = 0; i < num; i++) {
                            char c = stacks[stackA-1].top();
                            stacks[stackB-1].push(c);
                            stacks[stackA-1].pop();
                        }
                    } else if (PART == 2) {
                        // Move all crates at same time
                        stack<char> temp;
                        for (int i = 0; i < num; i++) {
                            char c = stacks[stackA-1].top();
                            temp.push(c);
                            stacks[stackA-1].pop();
                        }
                        while(temp.size() > 0) {
                            stacks[stackB-1].push(temp.top());
                            temp.pop();
                        }
                    }
                }
            }
        }
    }

    string result = "";
    for(int s = 0; s < STACKS; s++) {
        // printStack(stacks[s], s+1);
        result += stacks[s].top();
    }

    cout << "Part " << PART << " RESULT: " << result << endl;

}
