#include<iostream>
#include<vector>
#include<queue>
#include<unordered_set>
#include<unordered_map>
#include<cstring>
#include <set>
#include <map>
using namespace std;

int n, a, b;
vector<pair<int,int>> graph[100001];
bool flag = false;
int ret = 0;

void dfs(int cur, int prev, int mx, int dist) {
	if (flag) return;
	if (cur == b) {
		ret = dist - mx;
		flag = true;
	}
	for (auto p : graph[cur]) {
		if (p.first == prev) continue;
		dfs(p.first, cur, max(mx, p.second), dist + p.second);
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> n >> a >> b;
	for (int i = 0; i < n - 1; i++) {
		int from, to, c;
		cin >> from >> to >> c;
		graph[from].push_back({ to, c });
		graph[to].push_back({ from, c });
	}

	dfs(a, -1, 0, 0);
	cout << ret;
}
