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

int n, m;
int w[1001], p[1001];
int dp[10001];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        cin >> w[i] >> p[i];
    }

    for (int i = 0; i < n; i++) {
        for (int j = m; j >= w[i]; j--) {
            dp[j - w[i]] = max(dp[j - w[i]], dp[j] + p[i]);
        }
    }
    int ret = 0;
    for (int i = 0; i < m; i++) {
        ret = max(ret, dp[i]);
    }

    cout << ret;
}
