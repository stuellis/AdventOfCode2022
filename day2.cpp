#include <iostream>
#include <fstream>
#include <string>

using namespace std;

#define WIN 6
#define DRAW 3
#define LOOSE 0

int outcomeScore(char elf, char me) {
    // ROCK     A   X
    // PAPER    B   Y
    // SCISSORS C   Z
    switch (elf)
    {
    case 'A':
        if (me == 'X') { return DRAW; }
        if (me == 'Y') { return WIN; }
        if (me == 'Z') { return LOOSE; }
        break;
    case 'B':
        if (me == 'X') { return LOOSE; }
        if (me == 'Y') { return DRAW; }
        if (me == 'Z') { return WIN; }
        break;
    case 'C':
        if (me == 'X') { return WIN; }
        if (me == 'Y') { return LOOSE; }
        if (me == 'Z') { return DRAW; }
        break;
    }
    return 0;
}

int partOne(char a, char b) {
    int shapeScore = b - 'X' + 1;
    int score = outcomeScore(a, b);
    // cout << "# " << shapeScore << " .. " << score << " || " << shapeScore + score << endl;
    return shapeScore + score;
}

char shapeForResult(char elf, char outcome) {
    switch (elf)
    {
    case 'A':
        if (outcome == 'X') { return 'C'; }
        if (outcome == 'Y') { return 'A'; }
        if (outcome == 'Z') { return 'B'; }
        break;
    case 'B':
        if (outcome == 'X') { return 'A'; }
        if (outcome == 'Y') { return 'B'; }
        if (outcome == 'Z') { return 'C'; }
        break;
    case 'C':
        if (outcome == 'X') { return 'B'; }
        if (outcome == 'Y') { return 'C'; }
        if (outcome == 'Z') { return 'A'; }
        break;
    }
    return 'D';
}

int partTwo(char a, char b) {
    int score = b == 'X' ? LOOSE : (b == 'Y' ? DRAW : WIN);
    int shapeScore = shapeForResult(a, b) - 'A' + 1;
    // cout << "# " << shapeScore << " .. " << score << " || " << shapeScore + score << endl;
    return score + shapeScore;
}

int main() {
    ifstream myfile ("input_2.txt");
    string line;

    int totalScoreP1 = 0;
    int totalScoreP2 = 0;

    if (myfile.is_open()) {
        while (myfile) {
            getline(myfile, line);
            if (line.empty()) {
                break;
            }
            // cout << line << endl;

            char a, b;
            sscanf(line.c_str(), "%c %c", &a, &b);
            
            totalScoreP1 += partOne(a, b);
            totalScoreP2 += partTwo(a, b);
        }
    }

    cout << "Part 1 SCORE: " << totalScoreP1 << endl;
    cout << "Part 1 SCORE: " << totalScoreP2 << endl;
}
