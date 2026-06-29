#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>
#include<unordered_set>
#include<unordered_map>
#include<cstring>
#include <set>
#include <map>
using namespace std;

int n;
int a[10][10];
bool visited[10][10];
int dy[4] = { -1, 0, 1, 0 };
int dx[4] = { 0, 1, 0, -1 };
int ret = 0;

void dfs(int y, int x, int cnt) {
	if (y == n - 1 && x == n - 1) {
		ret = max(ret, cnt);
		return;
	}

	for (int i = 0; i < 4; i++) {
		int ny = y + dy[i];
		int nx = x + dx[i];

		if (ny < 0 || nx < 0 || ny >= n || nx >= n) continue;
		if (a[ny][nx] == 1) continue;
		if (visited[ny][nx]) continue;

		visited[ny][nx] = true;
		if (a[ny][nx] == 2) dfs(ny, nx, cnt + 1);
		else dfs(ny, nx, cnt);
		visited[ny][nx] = false;
	}
}

int main() {
	cin >> n;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> a[i][j];
		}
	}

	visited[0][0] = true;
	if (a[0][0] == 2) dfs(0, 0, 1);
	else dfs(0, 0, 0);
	cout << ret;
}
