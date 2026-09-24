#include <iostream>
#include <vector>
using namespace std;

bool stirngConc(string s, vector<string>& words, int index = 0) {

    if (index == s.size()) {
        return true;
    }

    for (int i = index; i < s.size(); i++) {

        string part = s.substr(index, i - index + 1);

        bool found = false;

        for (string word : words) {
            if (word == part) {
                found = true;
                break;
            }
        }

        if (found) {
            if (stirngConc(s, words, i + 1)) {
                return true;
            }
        }
    }

    return false;
}

int main() {

    string s = "catsanddog";

    vector<string> words = {
        "cat", "cats", "and", "sand", "dog"
    };

    if (stirngConc(s, words)) {
        cout << "true";
    }
    else {
        cout << "false";
    }

    return 0;
}