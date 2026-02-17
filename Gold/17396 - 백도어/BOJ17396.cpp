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
int a[100001];
vector<pair<int, int>> graph[100001];
const long long INF = 10000000002;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}

	for (int i = 0; i < m; i++) {
		int from, to, cost;
		cin >> from >> to >> cost;
		graph[from].push_back({ to, cost });
		graph[to].push_back({ from, cost });
	}

	vector<long long> dist(n, INF);
	priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<>> pq;
	pq.push({ 0, 0 });
	dist[0] = 0;

	while (!pq.empty()) {
		long long c = pq.top().first;
		int cur = pq.top().second;
		pq.pop();
		if (dist[cur] < c) continue;
		for (auto p : graph[cur]) {
			int next = p.first;
			int cost = p.second;
			if (a[next] && next != n - 1) continue;
			long long nc = c + cost;
			if (dist[next] > nc) {
				dist[next] = nc;
				pq.push({ nc, next });
			}
		}
	}

	cout << (dist[n - 1] == INF ? -1 : dist[n - 1]);
}
