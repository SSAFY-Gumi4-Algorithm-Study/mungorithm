#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <set>
#include <map>
#include <unordered_set>
#include <cstring>
#include <stack>
using namespace std;

string cur = "http://www.acm.org/";
stack<string> back, front;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    string cmd;
    while (cin >> cmd && cmd != "QUIT") {
        if (cmd == "VISIT") {
            string adr;
            cin >> adr;
            back.push(cur);
            cur = adr;
            stack<string> tmp;
            swap(front, tmp);
            cout << cur << '\n';
        }
        else if (cmd == "BACK") {
            if (back.empty()) {
                cout << "Ignored\n";
                continue;
            }
            front.push(cur);
            cur = back.top();
            back.pop();
            cout << cur << '\n';
        }
        else if (cmd == "FORWARD") {
            if (front.empty()) {
                cout << "Ignored\n";
                continue;
            }
            back.push(cur);
            cur = front.top();
            front.pop();
            cout << cur << '\n';
        }
    }
}
