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

int n, m, a, b, c;
vector<pair<int, int>> graph[100001];

bool check(int val) {
	vector<int> dist(n + 1, 987654321);
	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;
	dist[a] = 0;
	pq.push({ 0, a });

	while (!pq.empty()) {
		int cost = pq.top().first;
		int cur = pq.top().second;
		pq.pop();

		if (dist[cur] < cost) continue;

		for (auto p : graph[cur]) {
			if (p.second > val) continue;
			int next = p.first;
			int nc = cost + p.second;
			if (dist[next] > nc) {
				dist[next] = nc;
				pq.push({ nc, next });
			}
		}
	}

	return dist[b] <= c;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> n >> m >> a >> b >> c;
	for (int i = 0; i < m; i++) {
		int from, to, cost;
		cin >> from >> to >> cost;
		graph[from].push_back({ to, cost });
		graph[to].push_back({ from, cost });
	}

	int l = 1, r = 20;
	int ret = -1;

	while (l <= r) {
		int mid = (l + r) / 2;
		if (check(mid)) {
			ret = mid;
			r = mid - 1;
		}
		else {
			l = mid + 1;
		}
	}

	cout << ret;
}
