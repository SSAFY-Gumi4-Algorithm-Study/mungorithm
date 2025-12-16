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
using namespace std;

int n, m;
int a[501][501];
int dp[501][501];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			cin >> a[i][j];
		}
	}

	fill(&dp[0][0], &dp[0][0] + 501 * 501, 987654321);

	for (int i = 1; i <= m; i++) {
		dp[1][i] = a[1][i];
	}

	for (int i = 2; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			for (int k = 1; k <= m; k++) {
				if (j == k) continue;
				dp[i][j] = min(dp[i - 1][k], dp[i][j]);
			}
			dp[i][j] += a[i][j];
		}
	}
	int ret = 987654321;
	for (int i = 1; i <= m; i++) {
		ret = min(ret, dp[n][i]);
	}
	cout << ret;
}
