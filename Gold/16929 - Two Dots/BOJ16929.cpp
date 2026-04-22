#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <set>
#include <unordered_set>
#include <cstring>
using namespace std;

int n, m;
char a[51][51];
int dy[] = { -1, 0, 1, 0 };
int dx[] = { 0, 1, 0, -1 };
int visited[51][51];

bool dfs(int y, int x, int py, int px, char cur) {
	visited[y][x] = 1;
	for (int i = 0; i < 4; i++) {
		int ny = y + dy[i];
		int nx = x + dx[i];
		if (ny == py && nx == px) continue;
		if (ny < 0 || nx < 0 || ny >= n || nx >= m) continue;
		if (a[ny][nx] != cur) continue;
		if (visited[ny][nx]) return true;
		if (dfs(ny, nx, y, x, cur)) return true;
	}
	return false;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		string s;
		cin >> s;
		for (int j = 0; j < m; j++) {
			a[i][j] = s[j];
		}
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (!visited[i][j]) {
				if (dfs(i, j, -2, -2, a[i][j])) {
					cout << "Yes";
					return 0;
				}
			}
		}
	}

	cout << "No";
}
