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
vector<pair<int, int>> graph[1001];

vector<int> dijkstra(int a, int b) {
	vector<int> dist(n + 1, 987654321);
	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;
	pq.push({ 0, 1 });
	dist[1] = 0;
	while (!pq.empty()) {
		int cur = pq.top().second;
		int cost = pq.top().first;
		pq.pop();

		if (cost > dist[cur]) continue;

		for (auto p : graph[cur]) {
			int next = p.first;
			int ncost = cost + p.second;

			if ((cur == a && next == b) || (cur == b && next == a)) continue;

			if (dist[next] > ncost) {
				dist[next] = ncost;
				pq.push({ dist[next], next });
			}
		}
	}
	return dist;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		int a, b, t;
		cin >> a >> b >> t;
		graph[a].push_back({ b, t });
		graph[b].push_back({ a, t });
	}

	vector<int> parent(n + 1, -1);
	vector<int> dist(n + 1, 987654321);
	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;
	pq.push({ 0, 1 });
	dist[1] = 0;
	while (!pq.empty()) {
		int cur = pq.top().second;
		int cost = pq.top().first;
		pq.pop();

		if (cost > dist[cur]) continue;

		for (auto p : graph[cur]) {
			int next = p.first;
			int ncost = cost + p.second;

			if (dist[next] > ncost) {
				dist[next] = ncost;
				parent[next] = cur;
				pq.push({ dist[next], next });
			}
		}
	}

	vector<pair<int, int>> path;
	int ret = 0;
	int cur = n;
	while (parent[cur] != -1) {
		path.push_back({ cur, parent[cur] });
		cur = parent[cur];
	}

	for (auto p : path) {
		vector<int> ndist = dijkstra(p.first, p.second);

		if (ndist[n] == 987654321) {
			cout << -1;
			return 0;
		}

		ret = max(ret, ndist[n] - dist[n]);
	}
	cout << ret;
}
