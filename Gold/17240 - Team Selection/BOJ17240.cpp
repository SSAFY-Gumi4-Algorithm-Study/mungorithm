#include <iostream>
#include <algorithm>
#include <deque>
#include <vector>
#include <queue>
#include <cmath>
#include <unordered_set>
#include <map>
using namespace std;

int n;
int a[20001][5];
vector<int> dp(1 << 5, -1), ndp(1 << 5, -1);

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> a[i][0] >> a[i][1] >> a[i][2] >> a[i][3] >> a[i][4];
	}

	dp[0] = 0;

	for (int i = 0; i < n; i++) {
		ndp = dp;
		for (int mask = 0; mask < (1 << 5); mask++) {
			if (dp[mask] == -1) continue;
			for (int j = 0; j < 5; j++) {
				if (mask & (1 << j)) continue;
				int nmask = mask | (1 << j);
				ndp[nmask] = max(ndp[nmask], dp[mask] + a[i][j]);
			}
		}
		dp = ndp;
	}
	cout << dp[(1 << 5) - 1];
}
