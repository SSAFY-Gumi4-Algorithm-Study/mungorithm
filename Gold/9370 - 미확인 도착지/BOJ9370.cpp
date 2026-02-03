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

int T;
int n, m, k;
int s, g, h;
vector<pair<int, int>> graph[2001];

void dijkstra(int cur, vector<int> &dist) {
	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;
	pq.push({ 0, cur });
	dist[cur] = 0;

	while (!pq.empty()) {
		int cur = pq.top().second;
		int cost = pq.top().first;
		pq.pop();
		if (cost > dist[cur]) continue;
		for (auto p : graph[cur]) {
			int next = p.first;
			int ncost = p.second + cost;
			if (dist[next] > ncost) {
				dist[next] = ncost;
				pq.push({ ncost, next });
			}
		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> T;
	for (int t = 1; t <= T; t++) {
		cin >> n >> m >> k;
		cin >> s >> g >> h;

		int y = 0;

		for (int i = 0; i <= n; i++) {
			graph[i].clear();
		}

		for (int i = 0; i < m; i++) {
			int a, b, c;
			cin >> a >> b >> c;
			graph[a].push_back({ b, c });
			graph[b].push_back({ a, c });
			if ((a == g && b == h) || (a == h && b == g)) y = c;
		}

		vector<int> dist_s(n + 1, 987654321);
		vector<int> dist_g(n + 1, 987654321);
		vector<int> dist_h(n + 1, 987654321);

		dijkstra(s, dist_s);
		dijkstra(g, dist_g);
		dijkstra(h, dist_h);

		vector<int> v;

		for (int i = 0; i < k; i++) {
			int x;
			cin >> x;
			v.push_back(x);
		}
		sort(v.begin(), v.end());
		for (int x : v) {
			int a = min(dist_s[g] + y + dist_h[x], dist_s[h] + y + dist_g[x]);
			if (a == dist_s[x]) cout << x << ' ';
		}
		cout << '\n';
	}
}
