#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <unordered_set>
using namespace std;

int n;
int a[10001], ind[10001];
int dp[10001][2];
vector<int> tree[10001];
vector<int> ret;

void dfs(int cur, int parent) {
	dp[cur][0] = 0;
	dp[cur][1] = a[cur];
	for (int next : tree[cur]) {
		if (next == parent) continue;
		dfs(next, cur);
		dp[cur][0] += max(dp[next][1], dp[next][0]);
		dp[cur][1] += dp[next][0];
	}
}

void redfs(int cur, int parent, int idx) {
	if (idx == 1) {
		ret.push_back(cur);
	}
	for (int next : tree[cur]) {
		if (next == parent) continue;
		if (idx == 1) {
			redfs(next, cur, 0);
		}
		else {
			if (dp[next][1] > dp[next][0]) {
				redfs(next, cur, 1);
			}
			else {
				redfs(next, cur, 0);
			}
		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	
	for (int i = 0; i < n - 1; i++) {
		int from, to;
		cin >> from >> to;
		tree[from].push_back(to);
		tree[to].push_back(from);
	}

	dfs(1, -1);
	int mx = 0;
	int mx_idx = -1;
	if (dp[1][0] > dp[1][1]) {
		mx = dp[1][0];
		mx_idx = 0;
	}
	else {
		mx = dp[1][1];
		mx_idx = 1;
	}
	redfs(1, -1, mx_idx);
	sort(ret.begin(), ret.end());
	cout << mx << '\n';
	for (int i : ret) {
		cout << i << ' ';
	}
}
