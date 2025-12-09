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

int n;
int a[21][21];
vector<int> dp;

int bit_count(int x) {
	int cnt = 0;
	while (x) {
		x &= (x - 1);
		cnt++;
	}
	return cnt;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	
	cin >> n;
	dp.assign(1 << n, 987654321);

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> a[i][j];
		}
	}
	dp[0] = 0;

	for (int mask = 0; mask < (1 << n); mask++) {
		int i = bit_count(mask);
		if (i >= n) continue;
		for (int j = 0; j < n; j++) {
			if (mask & (1 << j)) continue;
			int nmask = mask | (1 << j);
			dp[nmask] = min(dp[nmask], dp[mask] + a[i][j]);
		}
	}
	cout << dp[(1 << n) - 1];
}
