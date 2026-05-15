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
int dp[1000001];
const int MOD = 1000000007;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n;

    dp[0] = 1;
    for (int i = 1; i <= n; i <<= 1) {
        for (int j = i; j <= n; j++) {
            dp[j] = (dp[j] + dp[j - i]) % MOD;
        }
    }
    cout << dp[n];
}
