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
int a[501][501];
int dp[501][501];
int dy[] = { -1, 0, 1, 0 };
int dx[] = { 0, 1, 0, -1 };

int dfs(int y, int x) {
    if (y == n - 1 && x == m - 1) return 1;
    if (dp[y][x] != -1) return dp[y][x];
    dp[y][x] = 0;
    for (int i = 0; i < 4; i++) {
        int ny = y + dy[i];
        int nx = x + dx[i];
        if (ny < 0 || nx < 0 || ny >= n || nx >= m) continue;
        if (a[y][x] <= a[ny][nx]) continue;
        dp[y][x] += dfs(ny, nx);
    }
    return dp[y][x];
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> a[i][j];
        }
    }

    memset(dp, -1, sizeof(dp));

    cout << dfs(0, 0);
}
