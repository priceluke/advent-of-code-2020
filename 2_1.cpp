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
        int lower_bound =  stoi(rule.substr(0, line.find("-")));
        int upper_bound = stoi(rule.substr(line.find("-")+1, rule.length()));
        char letter = rule.substr(rule.find(" ") + 1, rule.length())[0];
        string password = line.substr(line.find(":") + 2, line.length());
        int count = 0;
        for (auto i = 0; i < password.length(); i++) {
            if (password[i] == letter){
                count++;
            };
        };
        if (lower_bound <= count && count <= upper_bound) {
            valid++;
            cout << lower_bound << " <= " << count << " <= " << upper_bound << "  " << line << endl;
        } else {
            cout << "!!" << lower_bound << " <= " << count << " <= " << upper_bound << "  " << line << endl;
        };
    };
    InputFile.close();
    cout << valid << endl;
    return 0;
}
