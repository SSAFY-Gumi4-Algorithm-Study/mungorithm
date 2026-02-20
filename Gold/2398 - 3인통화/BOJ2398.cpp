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
int d1, d2, d3;
int pre1[1001], pre2[1001], pre3[1001];
int dist1[1001], dist2[1001], dist3[1001];
int idx;
set<pair<int, int>> edge;

void dijkstra(int start, int dist[], int pre[]) {
	fill(dist, dist + 1001, 987654321);
	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;
	dist[start] = 0;
	pre[start] = -1;
	pq.push({ 0, start });
	while (!pq.empty()) {
		int c = pq.top().first;
		int cur = pq.top().second;
		pq.pop();
		if (dist[cur] < c) continue;
		for (auto p : graph[cur]) {
			int next = p.first;
			int cost = p.second;
			int nc = cost + c;
			if (dist[next] > nc) {
				dist[next] = nc;
				pre[next] = cur;
				pq.push({ nc, next });
			}
		}
	}
}

void insert_path(int start, int pre[]) {
	int cur = idx;
	while (cur != start) {
		int prev = pre[cur];
		int a = min(cur, prev);
		int b = max(cur, prev);
		edge.insert({ a, b });
		cur = prev;
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	
	cin >> n >> m;

	for (int i = 0; i < m; i++) {
		int from, to, cost;
		cin >> from >> to >> cost;
		graph[from].push_back({ to, cost });
		graph[to].push_back({ from, cost });
	}

	cin >> d1 >> d2 >> d3;

	dijkstra(d1, dist1, pre1);
	dijkstra(d2, dist2, pre2);
	dijkstra(d3, dist3, pre3);

	int ret = 987654321;
	for (int i = 1; i <= n; i++) {
		int total = dist1[i] + dist2[i] + dist3[i];
		if (ret > total) {
			ret = total;
			idx = i;
		}
	}

	insert_path(d1, pre1);
	insert_path(d2, pre2);
	insert_path(d3, pre3);

	cout << ret << " " << edge.size() << '\n';
	for (auto p : edge) {
		cout << p.first << " " << p.second << '\n';
	}
}
