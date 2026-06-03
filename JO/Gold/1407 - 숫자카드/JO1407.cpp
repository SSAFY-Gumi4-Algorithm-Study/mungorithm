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

string s;
int dp[41];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> s;
    int n = s.size();

    dp[0] = 1;
    dp[1] = 1;
    int prev = s[0] - '0';

    for (int i = 1; i < n; i++) {
        int cur = s[i] - '0';
        int num = prev * 10 + cur;
        if (cur != 0) dp[i + 1] += dp[i];
        if (num >= 10 && num <= 34) {
            dp[i + 1] += dp[i - 1];
        }
        prev = cur;
    }

    cout << dp[n];
}
