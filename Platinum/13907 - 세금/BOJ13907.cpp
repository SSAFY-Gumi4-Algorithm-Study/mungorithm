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
int s, e;
long long dist[1001][1001];
vector<pair<int, int>> graph[1001];
const long long INF = 10e12;

struct Node {
	int cur;
	int cost;
	int cnt;

	bool operator>(const Node& other) const {
		return cost > other.cost;
	}
};

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> n >> m >> k;
	cin >> s >> e;
	for (int i = 0; i < m; i++) {
		int a, b, c;
		cin >> a >> b >> c;
		graph[a].push_back({ b, c });
		graph[b].push_back({ a, c });
	}

	fill(&dist[0][0], &dist[0][0] + 1001 * 1001, INF);

	priority_queue<Node, vector<Node>, greater<>> pq;
	pq.push({ s, 0, 0 });
	dist[s][0] = 0;
	while (!pq.empty()) {
		Node cn = pq.top();
		pq.pop();
		if (dist[cn.cur][cn.cnt] < cn.cost) continue;
		if (cn.cnt >= n - 1) continue;
		for (auto p : graph[cn.cur]) {
			int next = p.first;
			int nc = cn.cost + p.second;
			int ncnt = cn.cnt + 1;
			if (ncnt >= n) continue;

			long long best = INF;
			for (int i = 0; i <= ncnt; i++) {
				best = min(best, dist[next][i]);
			}
			if (best <= nc) continue;

			if (dist[next][ncnt] > nc) {
				dist[next][ncnt] = nc;
				pq.push({ next, nc, ncnt });
			}
		}
	}
	long long ret = INF;
	for (int i = 1; i < n; i++) {
		if (dist[e][i] == INF) continue;
		ret = min(dist[e][i], ret);
	}
	cout << ret << '\n';
	for (int i = 0; i < k; i++) {
		int up;
		cin >> up;
		ret = INF;
		for (int i = 1; i < n; i++) {
			if (dist[e][i] == INF) continue;
			dist[e][i] += i * up;
			ret = min(dist[e][i], ret);
		}
		cout << ret << '\n';
	}
}
