#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <set>
#include <unordered_set>
#include <cstring>
using namespace std;

int n, m;
char a[101][101];
int dist[101][101][4];
vector<pair<int, int>> v;
int dy[] = { -1, 0, 1, 0 };
int dx[] = { 0, 1, 0, -1 };

struct State {
	int y, x, dir;
};
deque<State> dq;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> m >> n;
	for (int i = 0; i < n; i++) {
		string s;
		cin >> s;
		for (int j = 0; j < m; j++) {
			a[i][j] = s[j];
			if (s[j] == 'C') {
				v.push_back({ i, j });
			}
		}
	}
	
	fill(&dist[0][0][0], &dist[0][0][0] + 101 * 101 * 4, 987654321);
	
	for (int i = 0; i < 4; i++) {
		dist[v[0].first][v[0].second][i] = 0;
		dq.push_back({ v[0].first, v[0].second, i });
	}

	while (!dq.empty()) {
		State cur = dq.front();
		int y = cur.y;
		int x = cur.x;
		int dir = cur.dir;
		dq.pop_front();
		if (y == v[1].first && x == v[1].second) {
			cout << dist[y][x][dir];
			break;
		}
		for (int i = 0; i < 4; i++) {
			if ((dir + 2) % 4 == i) continue;
			int ny = y + dy[i];
			int nx = x + dx[i];

			if (ny < 0 || nx < 0 || ny >= n || nx >= m) continue;
			if (a[ny][nx] == '*') continue;

			int cost = dist[y][x][dir];
			if (dir != i) {
				cost++;
			}
			if (dist[ny][nx][i] > cost) {
				dist[ny][nx][i] = cost;
				if (dir == i) {
					dq.push_front({ ny, nx, i });
				}
				else {
					dq.push_back({ ny, nx, i });
				}
			}
		}
	}
}
