#include<iostream>
#include<vector>
#include<queue>
#include<unordered_set>
#include<cstring>
using namespace std;

int n;
int a[50001];
int k;
int dp[4][50001];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> n;
	for (int i = 1; i <= n; i++) {
		int x;
		cin >> x;
		a[i] = a[i - 1] + x;
	} 
	cin >> k;

	for (int i = 1; i <= 3; i++) {
		for (int j = i * k; j <= n; j++) {
			dp[i][j] = max(dp[i][j - 1], dp[i - 1][j - k] + (a[j] - a[j - k]));
		}
	}

	cout << dp[3][n];
}
