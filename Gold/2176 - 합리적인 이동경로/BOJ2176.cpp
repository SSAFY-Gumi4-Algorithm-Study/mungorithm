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
vector<int> dist(1001, 987654321);
vector<int> dp(1001, -1);
int ret = 0;

int dfs(int cur) {
	if (cur == 2) return 1;
	if (dp[cur] != -1) return dp[cur];
	dp[cur] = 0;
	for (auto p : graph[cur]) {
		int next = p.first;
		if (dist[next] < dist[cur]) {
			dp[cur] += dfs(next);
		}
	}
	return dp[cur];
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	
	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		int from, to, c;
		cin >> from >> to >> c;
		graph[from].push_back({ to, c });
		graph[to].push_back({ from, c });
	}

	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;
	
	pq.push({ 0, 2 });
	dist[2] = 0;
	while (!pq.empty()) {
		int cost = pq.top().first;
		int cur = pq.top().second;
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

	dfs(1);
	cout << dp[1];
}
