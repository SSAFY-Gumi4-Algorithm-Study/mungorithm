#include<iostream>
#include<vector>
#include<queue>
#include<unordered_set>
#include<unordered_map>
#include<cstring>
#include <set>
#include <map>
using namespace std;

int n;
int dp[20][1 << 19];
int cost[20][20];

int tsp(int cur, int mask) {
	if (mask == (1 << n) - 1) {
		if (cost[cur][0] == 0) return 987654321;
		return cost[cur][0];
	}

	if (dp[cur][mask] != -1) return dp[cur][mask];

	dp[cur][mask] = 987654321;

	for (int next = 0; next < n; next++) {
		if (mask & (1 << next)) continue;
		if (cost[cur][next] == 0) continue;
		dp[cur][mask] = min(dp[cur][mask], tsp(next, mask | (1 << next)) + cost[cur][next]);
	}

	return dp[cur][mask];
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	memset(dp, -1, sizeof(dp));

	cin >> n;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> cost[i][j];
		}
	}
	cout << tsp(0, 1);
}
