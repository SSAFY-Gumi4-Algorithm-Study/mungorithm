#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

int n, m;
vector<pair<int, int>> graph[5001];

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	
	cin >> n >> m;

	for (int i = 0; i < m; i++) {
		int a, b, c;
		cin >> a >> b >> c;
		graph[a].push_back({ b, c });
		graph[b].push_back({ a, c });
	}
	int s, e;
	cin >> s >> e;

	vector<int> dist(n + 1, 987654321);
	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;
	pq.push({ 0, s });
	dist[s] = 0;
	while (!pq.empty()) {
		int cur = pq.top().second;
		int c = pq.top().first;
		pq.pop();
		if (cur == e) break;
		if (dist[cur] < c) continue;
		for (auto p : graph[cur]) {
			int next = p.first;
			int nc = c + p.second;
			if (dist[next] > nc) {
				dist[next] = nc;
				pq.push({ nc, next });
			}
		}
	}
	cout << dist[e];
}
