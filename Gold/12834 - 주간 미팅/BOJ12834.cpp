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

int n, v, e;
int a, b;
vector<int> h;
vector <pair<int, int>> graph[1001];
int ret = 0;

int dijkstra(int start) {
	vector<int> dist(v + 1, 987654321);
	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
	pq.push({ 0, start });
	dist[start] = 0;
	while (!pq.empty()) {
		int cur = pq.top().second;
		int cost = pq.top().first;
		pq.pop();
		if (dist[cur] < cost) continue;
		for (auto p : graph[cur]) {
			int next = p.first;
			int ncost = cost + p.second;
			if (dist[next] > ncost) {
				dist[next] = ncost;
				pq.push({ ncost, next });
			}
		}
	}
	if (dist[a] == 987654321) dist[a] = -1;
	if (dist[b] == 987654321) dist[b] = -1;
	return dist[a] + dist[b];
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> n >> v >> e;
	cin >> a >> b;
	for (int i = 0; i < n; i++) {
		int num;
		cin >> num;
		h.push_back(num);
	}
	for (int i = 0; i < e; i++) {
		int from, to, c;
		cin >> from >> to >> c;
		graph[from].push_back({ to, c });
		graph[to].push_back({ from, c });
	}
	for (int i : h) {
		ret += dijkstra(i);
	}
	cout << ret;
}
