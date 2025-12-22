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
using namespace std;

int n, m, k;
vector<int> graph[2001];
unordered_set<int> st;
vector<int> ret;
int check[2001];

void boom(int cur) {
	for (int next : graph[cur]) {
		if (!st.count(next)) return;
	}
	check[cur] = 1;
	for (int next : graph[cur]) {
		check[next] = 1;
	}
	ret.push_back(cur);
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		int from, to;
		cin >> from >> to;
		graph[from].push_back(to);
		graph[to].push_back(from);
	}

	cin >> k;
	for (int i = 0; i < k; i++) {
		int n;
		cin >> n;
		st.insert(n);
	}

	for (int i = 1; i <= n; i++) {
		if (!st.count(i)) continue;
		boom(i);
	}
	for (int num : st) {
		if (!check[num]) {
			cout << -1;
			return 0;
		}
	}
	cout << ret.size() << '\n';
	for (int num : ret) {
		cout << num << ' ';
	}
}
