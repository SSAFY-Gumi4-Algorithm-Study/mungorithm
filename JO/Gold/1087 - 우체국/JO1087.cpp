#include<iostream>
#include<vector>
#include<queue>
#include<unordered_set>
#include<unordered_map>
#include<cstring>
#include <set>
#include <map>
using namespace std;

int n, k;
int a[301];
int cost[301][301];
int dp[31][301];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> n >> k;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}

	for (int l = 1; l <= n; l++) {
		for (int r = l; r <= n; r++) {
			int mid = (l + r) / 2;
			for (int i = l; i <= r; i++) {
				cost[l][r] += abs(a[i] - a[mid]);
			}
		}
	}

	fill(&dp[0][0], &dp[0][0] + 31 * 301, 987654321);

	dp[0][0] = 0;

	for (int p = 1; p <= k; p++) {
		for (int i = 1; i <= n; i++) {
			for (int j = 0; j < i; j++) {
				dp[p][i] = min(dp[p][i], dp[p - 1][j] + cost[j + 1][i]);
			}
		}
	}

	cout << dp[k][n];
}
