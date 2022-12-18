#include <iostream>
#include <fstream>
#include <string>
#include "AdventDay4.h"
#include "AdventDay5.h"
#include "AdventDay6.h"
#include "AdventDay7.h"
#include "AdventDay8.h"
#include "AdventDay9.h"
using namespace std;

void RunDay7(fstream file, string line) {

    //part 7
    vector<tuple<string, string, string>> lines;
    string string1;
    string string2;
    string string3;

    while (getline(file, line)) {
        string1 = "";
        string2 = "";
        string3 = "";

        vector<string> words;
        string word = "";
        for (char c : line) {
            if (c == ' ') {
                words.push_back(word);
                word = "";
            }
            else {
                word += c;
            }
        }
        words.push_back(word);

        string1 = words[0];
        string2 = words[1];
        if (words.size() == 3) {
            string3 = words[2];
        }

        lines.push_back(tuple<string, string, string>{string1, string2, string3});
    }

    cout << AdventDay7::ProcessLine(lines);;
}

int main()
{
    fstream file;
    string input = "C:/Users/Lisa/source/repos/AdventOfCode2022/AdventOfCode2022/Text/AdventDay9.txt";
    file.open(input);
    
    //part 1-6
    /*string line;
    int total = 0;
    while (getline(file, line)) {
        total += AdventDay6::ProcessLine(line);
    }*/
    //cout << AdventDay8::Solve(file);

    cout << AdventDay9::Solve(file);
}
