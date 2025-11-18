#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <unordered_set>
using namespace std;

int n;
int ind[501], a[501];
int dp[501];
vector<int> v[501];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
		while (true) {
			int num;
			cin >> num;
			if (num == -1) break;
			v[num].push_back(i);
			ind[i]++;
		}
	}

	queue<int> q;
	for (int i = 1; i <= n; i++) {
		if (ind[i] == 0) q.push(i);
	}

	while (!q.empty()) {
		int cur = q.front();
		q.pop();
		dp[cur] += a[cur];
		for (int next : v[cur]) {
			ind[next]--;
			dp[next] = max(dp[next], dp[cur]);
			if (ind[next] == 0) q.push(next);
		}
	}

	for (int i = 1; i <= n; i++) {
		cout << dp[i] << '\n';
	}
}
