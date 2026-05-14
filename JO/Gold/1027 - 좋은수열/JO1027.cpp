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

int n;
unordered_set<string> st;

bool check(string s) {
    int len = s.size();

    for (int i = 1; i <= len / 2; i++) {
        string a = s.substr(len - i, i);
        string b = s.substr(len - 2 * i, i);
        if (a == b)return false;
    }
    return true;
}

bool dfs(string s) {
    if (s.size() == n) {
        cout << s;
        return true;
    }

    for (char c = '1'; c <= '3'; c++) {
        string next = s + c;
        if (check(next)) {
            if (dfs(next)) return true;
        }
    }
    return false;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n;
    dfs("");
}
