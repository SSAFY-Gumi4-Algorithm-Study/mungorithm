#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <set>
#include <unordered_set>
#include <cstring>
using namespace std;

int n, m;
int s, e;
int ind[10001];
int dist[10001];
int cnt = 0;
vector<int> parent[10001];
vector<pair<int, int>> graph[10001];
int visited[10001];

void trace(int cur) {
	visited[cur] = 1;
	for (int next : parent[cur]) {
		cnt++;
		if(!visited[next])trace(next);
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	
	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		int from, to, time;
		cin >> from >> to >> time;
		graph[from].push_back({ to, time });
		ind[to]++;
	}
	cin >> s >> e;

	queue<int> q;
	q.push(s);

	while (!q.empty()) {
		int cur = q.front();
		q.pop();
		for (auto p : graph[cur]) {
			int next = p.first;
			int ntime = dist[cur] + p.second;
			if (dist[next] < ntime) {
				dist[next] = ntime;
				parent[next].clear();
				parent[next].push_back(cur);
			}
			else if(dist[next] == ntime) {
				parent[next].push_back(cur);
			}
			ind[next]--;
			if (ind[next] == 0) q.push(next);
		}
	}
	trace(e);
	cout << dist[e] << '\n';
	cout << cnt;
}
