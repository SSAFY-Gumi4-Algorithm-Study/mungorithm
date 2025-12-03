#include <iostream>
#include <algorithm>
#include <deque>
#include <vector>
#include <queue>
using namespace std;

int n, m;
int a[501][501];
int visited[501][501][2];
int dy1[] = { -1, 0, 1, 0 };
int dx1[] = { 0, 1, 0, -1 };
int dy2[] = { -1, 1, 1, -1 };
int dx2[] = { 1, -1, 1, -1 };

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		string s;
		cin >> s;
		for (int j = 0; j < m; j++) {
			a[i][j] = s[j] == '/' ? 0 : 1;
		}
	}

	fill(&visited[0][0][0], &visited[0][0][0] + 501 * 501 * 2, 987654321);
	deque<vector<int>> dq;
	if (a[0][0] == 0) {
		visited[0][0][1] = 1;
	}
	else visited[0][0][1] = 0;
	dq.push_back({ 0, 0, 1 });

	while (!dq.empty()) {
		int y = dq.front()[0];
		int x = dq.front()[1];
		int s = dq.front()[2];
		dq.pop_front();
		for (int i = 0; i < 4; i++) {
			int ny = y + dy1[i];
			int nx = x + dx1[i];
			if (ny < 0 || nx < 0 || ny >= n || nx >= m) continue;
			if (s == a[ny][nx]) {
				int ns = (s + 1) % 2;
				if (visited[ny][nx][ns] > visited[y][x][s] + 1) {
					visited[ny][nx][ns] = visited[y][x][s] + 1;
					dq.push_back({ ny, nx, ns });
				}
			}
			else {
				int ns = a[ny][nx];
				if (visited[ny][nx][ns] > visited[y][x][s]) {
					visited[ny][nx][ns] = visited[y][x][s];
					dq.push_front({ ny, nx, ns });
				}
			}
		}
		if (s == 0) {
			
			for (int i = 0; i < 2; i++) {
				int ny = y + dy2[i];
				int nx = x + dx2[i];
				if (ny < 0 || nx < 0 || ny >= n || nx >= m) continue;
				int ns = s;
				if (s != a[ny][nx]) {
					if (visited[ny][nx][ns] > visited[y][x][s] + 1) {
						visited[ny][nx][ns] = visited[y][x][s] + 1;
						dq.push_back({ ny, nx, ns });
					}
				}
				else {
					if (visited[ny][nx][ns] > visited[y][x][s]) {
						visited[ny][nx][ns] = visited[y][x][s];
						dq.push_front({ ny, nx, ns });
					}
				}
			}
		}
		else {
			for (int i = 2; i < 4; i++) {
				int ny = y + dy2[i];
				int nx = x + dx2[i];
				if (ny < 0 || nx < 0 || ny >= n || nx >= m) continue;
				int ns = s;
				if (s != a[ny][nx]) {
					if (visited[ny][nx][ns] > visited[y][x][s] + 1) {
						visited[ny][nx][ns] = visited[y][x][s] + 1;
						dq.push_back({ ny, nx, ns });
					}
				}
				else {
					if (visited[ny][nx][ns] > visited[y][x][s]) {
						visited[ny][nx][ns] = visited[y][x][s];
						dq.push_front({ ny, nx, ns });
					}
				}
			}
		}
	}
	if (visited[n - 1][m - 1][1] == 987654321) cout << "NO SOLUTION";
	else cout << visited[n - 1][m - 1][1];
}
