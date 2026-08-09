#include<iostream>
#include<queue>
using namespace std;

class Stack {
    queue<int> q;

public:

    Stack() {

    }

    void push(int x) {
        q.push(x);
    }

    void pop() {
        if(q.empty()) {
            return;
        }

        queue<int> temp;

        while(q.size() > 1) {
            temp.push(q.front());
            q.pop();
        }

        q.pop();

        while(!temp.empty()) {
            q.push(temp.front());
            temp.pop();
        }
    }

    bool empty() {
        return q.empty();
    }

    int top() {
        if(q.empty()) {
            return -1;
        }

        queue<int> temp;

        while(q.size() > 1) {
            temp.push(q.front());
            q.pop();
        }

        int res = q.front();

        q.pop();

        while(!temp.empty()) {
            q.push(temp.front());
            temp.pop();
        }

        q.push(res);

        return res;
    }
};

int main() {

    Stack s;

    s.push(10);
    s.push(20);
    s.push(30);
    s.push(40);

    s.pop();
    s.pop();

    while(!s.empty()) {
        cout << s.top() << " ";
        s.pop();
    }

    return 0;
}