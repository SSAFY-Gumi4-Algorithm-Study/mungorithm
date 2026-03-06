#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <set>
#include <unordered_set>
using namespace std;

int n, m;
vector<pair<int, int>> graph[1001];
int parent[1001];
int dist[1001];
const int INF = 987654321;

void dijkstra(int start, int s, int e) {
	fill(dist, dist + 1001, INF);
	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;
	dist[start] = 0;
	pq.push({ 0, start });
	while (!pq.empty()) {
		int c = pq.top().first;
		int cur = pq.top().second;
		pq.pop();
		if (cur == n) return;
		if (dist[cur] < c) continue;
		for (auto p : graph[cur]) {
			int next = p.first;
			int nc = c + p.second;
			if ((cur == s && next == e) || (cur == e && next == s)) continue;
			if (dist[next] > nc) {
				dist[next] = nc;
				parent[next] = cur;
				pq.push({ nc, next });
			}
		}
	}
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	
	cin >> n >> m;

	for (int i = 0; i < m; i++) {
		int a, b, c;
		cin >> a >> b >> c;
		graph[a].push_back({ b, c });
		graph[b].push_back({ a, c });
	}
	fill(parent, parent + 1001, -1);
	dijkstra(1, -1, -1);
	int ret = dist[n];
	vector<pair<int, int>> path;
	int cur = n;
	while (cur != -1) {
		path.push_back({ cur, parent[cur] });
		cur = parent[cur];
	}
	for (int i = 0; i < path.size(); i++) {
		dijkstra(1, path[i].first, path[i].second);
		ret = max(ret, dist[n]);
	}
	cout << ret;
}
