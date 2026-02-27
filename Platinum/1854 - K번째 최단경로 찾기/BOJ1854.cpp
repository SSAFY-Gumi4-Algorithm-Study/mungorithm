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

int n, m, k;
vector<pair<int, int>> graph[1001];
priority_queue<int> dist[1001];

void kth_dijkstra() {
	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;
	pq.push({ 0, 1 });
	dist[1].push(0);
	while (!pq.empty()) {
		int d = pq.top().first;
		int cur = pq.top().second;
		pq.pop();
		for (auto p : graph[cur]) {
			int next = p.first;
			int nd = d + p.second;
			if (dist[next].size() < k) {
				dist[next].push(nd);
				pq.push({ nd, next });
			}
			else {
				if (dist[next].top() > nd) {
					dist[next].pop();
					dist[next].push(nd);
					pq.push({ nd, next });
				}
			}
		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> n >> m >> k;
	
	for (int i = 0; i < m; i++) {
		int a, b, c;
		cin >> a >> b >> c;
		graph[a].push_back({ b, c });
	}

	kth_dijkstra();
	for (int i = 1; i <= n; i++) {
		if (dist[i].size() < k) cout << -1 << '\n';
		else cout << dist[i].top() << '\n';
	}
}
