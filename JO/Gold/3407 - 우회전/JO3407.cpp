#include<iostream>
#include<vector>
#include<queue>
#include<unordered_set>
#include<unordered_map>
#include<cstring>
#include <set>
#include <map>
using namespace std;

int n, m;
char a[101][101]; 
int visited[101][101][4];
int dy[] = { -1, 0, 1, 0 };
int dx[] = { 0, 1, 0, -1 };
int sy, sx, ey, ex;

struct State {
	int y, x, d;
};

bool check(int y, int x) {
	return !(y < 0 || x < 0 || y >= n || x >= m);
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> n >> m;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> a[i][j];
			if (a[i][j] == 'A') {
				sy = i;
				sx = j;
			}
			else if (a[i][j] == 'B') {
				ey = i;
				ex = j;
			}
		}
	}

	memset(visited, -1, sizeof(visited));

	queue<State> q;
	for (int i = 0; i < 4; i++) {
		visited[sy][sx][i] = 0;
		int ny = sy + dy[i];
		int nx = sx + dx[i];
		if (!check(ny, nx)) continue;
		if (a[ny][nx] == 'X') continue;
		visited[ny][nx][i] = 1;
		q.push({ ny, nx, i });
	}

	while (!q.empty()) {
		State now = q.front();
		q.pop();
		int y = now.y;
		int x = now.x;
		int d = now.d;
		if (y == ey && x == ex) {
			cout << visited[y][x][d];
			return 0;
		}
		int ny = y + dy[d];
		int nx = x + dx[d];
		if (check(ny, nx)) {
			if (a[ny][nx] != 'X') {
				if (visited[ny][nx][d] == -1) {
					visited[ny][nx][d] = visited[y][x][d] + 1;
					q.push({ ny, nx, d });
				}
			}
		}
		int nd = (d + 1) % 4;
		ny = y + dy[nd];
		nx = x + dx[nd];
		if (check(ny, nx)) {
			if (a[ny][nx] != 'X') {
				if (visited[ny][nx][nd] == -1) {
					visited[ny][nx][nd] = visited[y][x][d] + 1;
					q.push({ ny, nx, nd });
				}
			}
		}
	}
	cout << -1;
}
