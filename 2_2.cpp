#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;

int main() {
    vector<string> strings;
    string line;
    int valid = 0;

    ifstream InputFile("/home/luke/Documents/advent-of-code-2020/2.txt");
    while (getline(InputFile, line)) {
        string rule = line.substr(0, line.find(":"));
        int first =  stoi(rule.substr(0, line.find("-")));
        int second = stoi(rule.substr(line.find("-")+1, rule.length()));
        char letter = rule.substr(rule.find(" ") + 1, rule.length())[0];
        string password = line.substr(line.find(":") + 2, line.length());
        if ((password[first-1] == letter && password[second-1] != letter) || (password[first-1] != letter && password[second-1] == letter)) {
            valid++;
        };
    };
    InputFile.close();
    cout << valid << endl;
    return 0;
}
