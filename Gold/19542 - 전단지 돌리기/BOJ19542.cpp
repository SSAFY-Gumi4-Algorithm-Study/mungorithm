#include <iostream>
#include <algorithm>
#include <deque>
#include <vector>
#include <queue>
#include <cmath>
#include <unordered_set>
#include <map>
#include <set>
using namespace std;

int n, s, d;
vector<int> tree[100001];
int dp[100001];

int dfs(int cur, int parent) {
	dp[cur] = 0;
	for (int next : tree[cur]) {
		if (next == parent) continue;
		dp[cur] = max(dfs(next, cur) + 1, dp[cur]);
	}
	return dp[cur];
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	
	cin >> n >> s >> d;
	for (int i = 0; i < n - 1; i++) {
		int from, to;
		cin >> from >> to;
		tree[from].push_back(to);
		tree[to].push_back(from);
	}

	dfs(s, -1);
	int ret = 0;
	int cnt = 0;
	for (int i = 1; i <= n; i++) {
		if (dp[i] >= d) cnt++;
	}
	if (cnt == 0) cout << 0;
	else cout << (cnt - 1) * 2;
}
