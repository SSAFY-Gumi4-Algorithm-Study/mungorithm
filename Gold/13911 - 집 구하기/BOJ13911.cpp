#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <set>
#include <unordered_set>
using namespace std;

vector<pair<int, int>> graph[10001];
vector<int> mac, star;
int macL, starL;
int macCnt, starCnt;
int n, m;
int dist1[10001], dist2[10001];
unordered_set<int> isNotHome;
const int INF = 1000000010;

void dijkstra(vector<int>& v, int dist[], int l) {
	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;
	fill(dist, dist + 10001, INF);
	for (int x : v) {
		dist[x] = 0;
		pq.push({ 0, x });
	}
	while (!pq.empty()) {
		int c = pq.top().first;
		int cur = pq.top().second;
		pq.pop();
		if (dist[cur] < c) continue;
		for (auto p : graph[cur]) {
			int next = p.first;
			int nc = c + p.second;
			if (dist[next] > nc && nc <= l) {
				pq.push({ nc, next });
				dist[next] = nc;
			}
		}
	}
}

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

	cin >> macCnt >> macL;
	for (int i = 0; i < macCnt; i++) {
		int num;
		cin >> num;
		mac.push_back(num);
		isNotHome.insert(num);
	}

	cin >> starCnt >> starL;
	for (int i = 0; i < starCnt; i++) {
		int num;
		cin >> num;
		star.push_back(num);
		isNotHome.insert(num);
	}

	dijkstra(mac, dist1, macL);
	dijkstra(star, dist2, starL);

	int ret = INF;

	for (int i = 1; i <= n; i++) {
		if (isNotHome.count(i)) continue;
		if (dist1[i] == INF || dist2[i] == INF) continue;
		ret = min(ret, (dist1[i] + dist2[i]));
	}

	if (ret == INF) cout << -1;
	else cout << ret;
}
