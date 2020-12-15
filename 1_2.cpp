#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;

int main() {
    vector<int> numbers;
    string line;
    ifstream InputFile("/home/luke/Documents/advent-of-code-2020/1.txt");
    while (getline(InputFile, line)) {
        numbers.push_back(stoi(line));
    };
    for (auto h = numbers.cbegin(); h != numbers.cend(); h++) {
        for (auto i = numbers.cbegin(); i != numbers.cend(); i++) {
            for (auto j = numbers.cbegin(); j != numbers.cend(); j++) {
                if (*h + *j + *i == 2020) {
                    cout << (*h * *j * *i) << std::endl;
                    return 0;
                }
            }
        }
    }
    InputFile.close();
    return 0;
}
