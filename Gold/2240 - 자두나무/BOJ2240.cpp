#include<iostream>
#include<vector>
#include<algorithm>
#include<tuple>
#include<string>
#include<unordered_set>
#include<stack>
#include<cmath>
#include<queue>
using namespace std;

int t, w;
int dp[3][1001][32];
int a[1001];

int main() {
    cin >> t >> w;
    for (int i = 1; i <= t; i++) {
        cin >> a[i];
    }

    if (a[1] == 1) {
        dp[1][1][w] = 1;
    }
    else dp[2][1][w-1] = 1;

    for (int i = 2; i <= t; i++) {
        for (int j = w; j >= 0; j--) {
            if (a[i] == 1) {
                dp[1][i][j] = max(dp[1][i - 1][j], dp[2][i - 1][j + 1]) + 1;
                dp[2][i][j] = max(dp[1][i - 1][j + 1], dp[2][i - 1][j]);
            }
            else {
                dp[1][i][j] = max(dp[1][i - 1][j], dp[2][i - 1][j + 1]);
                dp[2][i][j] = max(dp[1][i - 1][j + 1], dp[2][i - 1][j]) + 1;
            }
        }
    }
    int ret = -1;
    for (int i = w; i >= 0; i--) {
        ret = max(ret, max(dp[1][t][i], dp[2][t][i]));
    }
    cout << ret;
}



