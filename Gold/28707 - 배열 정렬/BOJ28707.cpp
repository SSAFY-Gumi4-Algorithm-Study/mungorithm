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
using namespace std;

int n, m;
int a[10];
vector<tuple<int,int,int>> graph;
string s = "", target = "";
unordered_map<string, int> mp;
int ret = 987654321;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
		s += char('0' + (a[i] - 1));
	}

	sort(a, a + n);
	for (int i = 0; i < n; i++) {
		target += char('0' + (a[i] - 1));
	}
	
	cin >> m;
	for (int i = 0; i < m; i++) {
		int a, b, c;
		cin >> a >> b >> c;
		graph.push_back({ a - 1, b - 1, c });
	}

	mp[s] = 0;
	priority_queue<pair<int, string>, vector<pair<int, string>>, greater<pair<int, string>>> pq;
	pq.push({ 0, s });
	while (!pq.empty()) {
		int cost = pq.top().first;
		string cur = pq.top().second;
		if (cur == target) {
			ret = min(ret, cost);
		}
		pq.pop();
		if (cost > mp[cur]) continue;
		for (int i = 0; i < m; i++) {
			string tmp = cur;
			int a = get<0>(graph[i]);
			int b = get<1>(graph[i]);
			int c = get<2>(graph[i]);
			swap(tmp[a], tmp[b]);
			if (!mp.count(tmp) || mp[tmp] > cost + c) {
				mp[tmp] = cost + c;
				pq.push({ cost + c, tmp });
			}
		}
	}
	if (mp.count(target)) cout << mp[target];
	else cout << -1;
}
