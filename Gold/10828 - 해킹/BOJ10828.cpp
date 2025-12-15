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
using namespace std;

int T;
int n, d, c;
vector<vector<pair<int,int>>> v;
int dist[10001];

void init() {
	v.clear();
	v.resize(n + 1);
	fill(dist, dist + 10001, 987654321);
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	
	cin >> T;
	for (int t = 1; t <= T; t++) {
		cin >> n >> d >> c;
		init();
		for (int i = 0; i < d; i++) {
			int a, b, s;
			cin >> a >> b >> s;
			v[b].push_back({ a, s });
		}
		priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
		pq.push({0, c});
		dist[c] = 0;
		while (!pq.empty()) {
			int cur = pq.top().second;
			int cost = pq.top().first;
			pq.pop();
			if (dist[cur] < cost) continue;
			for (auto p : v[cur]) {
				int next = p.first;
				int nc = cost + p.second;
				if (dist[next] > nc) {
					dist[next] = nc;
					pq.push({ nc, next });
				}
			}
		}
		int cnt = 0;
		int ret = 0;
		for (int i = 1; i <= n; i++) {
			if (dist[i] != 987654321) {
				cnt++;
				ret = max(ret, dist[i]);
			}
		}
		cout << cnt << ' ' << ret << '\n';
	}	
}
