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
int sy, sx, ey, ex;
int dp[51][101][101];
int mv;
int dy[] = { -1, -1, -1, 0, 1, 1, 1, 0, -2, -2, -1, 1, 2, 2, 1, -1 };
int dx[] = { -1, 0, 1, 1, 1, 0, -1, -1, -1, 1, 2, 2, 1, -1, -2, -2 };

int dfs(int y, int x, int cnt) {
    if (cnt == mv) {
        return (y == ey && x == ex);
    }
    if (dp[cnt][y][x] != -1) return dp[cnt][y][x];
    dp[cnt][y][x] = 0;
    for (int i = 0; i < 16; i++) {
        int ny = y + dy[i];
        int nx = x + dx[i];
        if (ny < 0 || nx < 0 || ny >= n || nx >= n) continue;
        dp[cnt][y][x] += dfs(ny, nx, cnt + 1);
    }
    return dp[cnt][y][x];
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> sy >> sx >> ey >> ex >> mv;
    memset(dp, -1, sizeof(dp));
    dfs(sy, sx, 0);
    cout << dp[0][sy][sx];
}
