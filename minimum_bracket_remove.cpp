#include <iostream>
#include <stack>
#include <string>
using namespace std;

int main() {
    string s;
    cout << "Enter the bracket sequence: ";
    cin >> s;

    stack<char> st;
    int remove = 0;

    for (char ch : s) {
        if (ch == '(') {
            st.push(ch);
        }
        else if (ch == ')') {
            if (!st.empty())
                st.pop();
            else
                remove++;
        }
    }

    remove += st.size();

    cout << "Minimum brackets to remove = " << remove << endl;

    return 0;
}