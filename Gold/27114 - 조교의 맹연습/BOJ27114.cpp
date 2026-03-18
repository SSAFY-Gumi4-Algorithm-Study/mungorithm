#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <set>
#include <unordered_set>
#include <cstring>
using namespace std;

int a, b, c, k;
int dp[1000001][4];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    cin >> a >> b >> c >> k;
    fill(&dp[0][0], &dp[0][0] + 1000001 * 4, 987654321);
    dp[0][0] = 0;
    for (int i = 0; i <= k - 1; i++) {
        for (int j = 0; j < 4; j++) {
            if (dp[i][j] == 987654321) continue;
            if (i + a <= k) {
                dp[i + a][(j + 1) % 4] = min(dp[i + a][(j + 1) % 4], dp[i][j] + 1);
            }
            if (i + b <= k) {
                dp[i + b][(j + 3) % 4] = min(dp[i + b][(j + 3) % 4], dp[i][j] + 1);
            }
            if (i + c <= k) {
                dp[i + c][(j + 2) % 4] = min(dp[i + c][(j + 2) % 4], dp[i][j] + 1);
            }
        }
    }
    if (dp[k][0] == 987654321) {
        cout << -1;
    }
    else cout << dp[k][0];
}
