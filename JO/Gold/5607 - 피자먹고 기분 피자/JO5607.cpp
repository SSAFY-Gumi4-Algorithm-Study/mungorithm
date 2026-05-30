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

int m, k, n;
int p[5001], f[5001];
int dp[5001];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> m >> k;
    cin >> n;

    fill(dp, dp + 5001, -1);
    dp[0] = 0;
    for (int i = 0; i < n; i++) {
        cin >> p[i] >> f[i];
    }
    for (int i = 0; i < n; i++) {
        for (int j = m; j >= p[i]; j--) {
            dp[j] = max(dp[j], dp[j - p[i]] + f[i]);
        }
    }

    for (int i = 0; i <= m; i++) {
        if (dp[i] >= k) {
            cout << i;
            return 0;
        }
    }

    cout << ":(";
}
