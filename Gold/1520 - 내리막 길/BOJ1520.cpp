#include <iostream>
#include <algorithm>
#include <deque>
#include <vector>
#include <queue>
using namespace std;

int n, m;
int a[501][501];
int dp[501][501];
int dy[] = { -1, 0, 1, 0 };
int dx[] = { 0, 1, 0, -1 };
int ret = 0;

int dfs(int y, int x) {
	if (y == n - 1 && x == m - 1) {
		return 1;
	}
	if (dp[y][x] != -1) return dp[y][x];
	dp[y][x] = 0;
	for (int i = 0; i < 4; i++) {
		int ny = y + dy[i];
		int nx = x + dx[i];
		if (ny < 0 || nx < 0 || ny >= n || nx >= m) continue;
		if (a[ny][nx] < a[y][x]) dp[y][x] += dfs(ny, nx);
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
	fill(&dp[0][0], &dp[0][0] + 501 * 501, -1);
	cout << dfs(0, 0);
}
