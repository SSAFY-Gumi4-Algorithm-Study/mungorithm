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
int l, r;
int sy, sx;
int a[1001][1001];
int leftDist[1001][1001];
int dy[] = { -1, 1, 0, 0 };
int dx[] = { 0, 0, -1, 1 };

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> n >> m;
	cin >> l >> r;
	
	for (int i = 0; i < n; i++) {
		string s;
		cin >> s;
		for (int j = 0; j < m; j++) {
			a[i][j] = s[j] - '0';
			if (a[i][j] == 2) {
				sy = i;
				sx = j;
			}
			leftDist[i][j] = 987654321;
		}
	}

	priority_queue<tuple<int, int, int>, vector<tuple<int, int, int>>, greater<>> pq;
	pq.push({ 0, sy, sx });
	leftDist[sy][sx] = 0;

	while (!pq.empty()) {
		int cur = get<0>(pq.top());
		int y = get<1>(pq.top());
		int x = get<2>(pq.top());
		pq.pop();

		if (cur > leftDist[y][x]) continue;

		for (int i = 0; i < 4; i++) {
			int ny = y + dy[i];
			int nx = x + dx[i];

			if (ny < 0 || nx < 0 || ny >= n || nx >= m) continue;
			if (a[ny][nx] == 1) continue;

			int next = cur;
			if (i == 2) next++;
			
			int right = next + (nx - sx);
			if (next > l || right > r) continue;

			if (leftDist[ny][nx] > next) {
				leftDist[ny][nx] = next;
				pq.push({ next, ny, nx });
			}
		}
	}

	int ret = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (leftDist[i][j] == 987654321) continue;

			int left = leftDist[i][j];
			int right = left + (j - sx);
			if (left <= l && right <= r) {
				ret++;
			}
		}
	}
	cout << ret;
}
