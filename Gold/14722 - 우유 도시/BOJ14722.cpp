#include <iostream>
#include <algorithm>
#include <deque>
#include <vector>
#include <queue>
#include <cmath>
#include <stack>
#include <unordered_set>
#include <unordered_map>
#include <map>
#include <set>
#include <string>
#include <tuple>
#include <climits>
using namespace std;

int n;
int a[1001][1001];
int dp[1001][1001][3];
int ret = 0;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> n;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> a[i][j];
		}
	}

	if (a[0][0] == 0) dp[0][0][0] = 1;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (i == 0 && j == 0) continue;
			for (int k = 0; k < 3; k++) {
				int best = 0;

				if (i > 0) best = max(best, dp[i - 1][j][k]);

				if (j > 0) best = max(best, dp[i][j - 1][k]);

				dp[i][j][k] = best;

				if (a[i][j] == k) {
					int prev = (k + 2) % 3;
					int pbest = 0;

					if (i > 0) pbest = max(pbest, dp[i - 1][j][prev]);

					if (j > 0) pbest = max(pbest, dp[i][j - 1][prev]);

					if (k == 0 || pbest > 0)dp[i][j][k] = max(dp[i][j][k], pbest + 1);
				}
			}
		}
	}
	for (int i = 0; i < 3; i++) {
		ret = max(ret, dp[n - 1][n - 1][i]);
	}
	cout << ret;
}
