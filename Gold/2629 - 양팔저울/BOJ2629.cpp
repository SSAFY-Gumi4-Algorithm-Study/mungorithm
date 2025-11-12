#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
#include<tuple>
#include<string>
#include<unordered_map>
#include<unordered_set>

using namespace std;

int n, m;
int a[31];
int dp[31][40001];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	dp[0][0] = 1;

	for (int i = 1; i <= n; i++) {
		for (int j = 0; j <= 40000; j++) {
			if (!dp[i - 1][j]) continue;
			dp[i][j] = 1;
			if (j + a[i] <= 40000) dp[i][j + a[i]] = 1;
			dp[i][abs(a[i] - j)] = 1;
		}
	}
	cin >> m;
	for (int i = 0; i < m; i++) {
		int num;
		cin >> num;
		if (dp[n][num]) cout << "Y ";
		else cout << "N ";
	}
}
