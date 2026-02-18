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
#include <tuple>
#include <climits>
using namespace std;

int n, m;
int sy, sx, ey, ex;
int dy[] = { -1, 1, 0, 0 };
int dx[] = { 0, 0, -1, 1 };
int a[101][101];
int dist[101][101][3];

struct Node {
	int y, x;
	int mod;
	int cost;
	
	bool operator>(const Node& other) const {
		return cost > other.cost;
	}
};

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> n >> m;
	cin >> sy >> sx >> ey >> ex;

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			cin >> a[i][j];
		}
	}
	
	fill(&dist[0][0][0], &dist[0][0][0] + 101 * 101 * 3, 987654321);

	priority_queue<Node, vector<Node>, greater<>> pq;

	dist[sy][sx][1] = 0;
	pq.push({ sy, sx, 1, 0 });

	while (!pq.empty()) {
		auto cn = pq.top();
		pq.pop();
		int y = cn.y;
		int x = cn.x;
		int mod = cn.mod;
		int cost = cn.cost;
		if (dist[y][x][mod] < cost) continue;

		if (y == ey && x == ex) {
			cout << cost;
			return 0;
		}

		int nmod = (mod + 1) % 3;

		for (int i = 0; i < 4; i++) {
			if (mod == 1 && i >= 2) continue;
			if (mod == 2 && i <= 1) continue;
			
			int ny = y + dy[i];
			int nx = x + dx[i];
			if (ny < 1 || nx < 1 || ny > n || nx > m) continue;
			if (a[ny][nx] == -1) continue;

			int ncost = cost + a[ny][nx];
			if (dist[ny][nx][nmod] > ncost) {
				dist[ny][nx][nmod] = ncost;
				pq.push({ ny, nx, nmod, ncost });
			}
		}
	}
	cout << -1;
}
