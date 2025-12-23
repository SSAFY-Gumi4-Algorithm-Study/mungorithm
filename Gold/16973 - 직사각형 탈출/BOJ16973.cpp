#include <iostream>
#include <algorithm>
#include <deque>
#include <vector>
#include <queue>
#include <cmath>
#include <unordered_set>
#include <unordered_map>
#include <map>
#include <set>
#include <string>
using namespace std;

int n, m;
int a[1001][1001], psum[1001][1001], visited[1001][1001];
int sy, sx, ey, ex, szy, szx;
int dy[] = { -1, 0, 1, 0 };
int dx[] = { 0, 1, 0, -1 };

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			cin >> a[i][j];
			psum[i][j] = psum[i - 1][j] + psum[i][j - 1] - psum[i - 1][j - 1] + a[i][j];
		}
	}

	cin >> szy >> szx >> sy >> sx >> ey >> ex;

	queue<pair<int, int>> q;
	q.push({ sy, sx });
	visited[sy][sx] = 1;

	while (!q.empty()) {
		int y = q.front().first;
		int x = q.front().second;
		if (y == ey && x == ex) break;
		q.pop();
		for (int i = 0; i < 4; i++) {
			int ny = y + dy[i];
			int nx = x + dx[i];
			int ney = ny + szy - 1;
			int nex = nx + szx - 1;
			if (ny < 1 || nx < 1 || ny > n || nx > m) continue;
			if (ney < 1 || nex < 1 || ney > n || nex > m) continue;
			if (psum[ney][nex] - psum[ny - 1][nex] - psum[ney][nx - 1] + psum[ny - 1][nx - 1]) continue;
			if (visited[ny][nx]) continue;
			q.push({ ny, nx });
			visited[ny][nx] = visited[y][x] + 1;
		}
	}
	if (visited[ey][ex] == 0) cout << -1;
	else cout << visited[ey][ex] - 1;
}
