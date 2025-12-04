#include <iostream>
#include <algorithm>
#include <deque>
#include <vector>
#include <queue>
using namespace std;

int n;
int a[2001], dp[2002][2002];

int dfs(int l, int r, int cnt) {
	if (l > r) return 0;
	if (dp[l][r]) return dp[l][r];

	dp[l][r] = max(dfs(l + 1, r, cnt + 1) + a[l] * cnt , dfs(l, r - 1, cnt + 1) + a[r] * cnt);

	return dp[l][r];
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	cout << dfs(1, n, 1);
}
