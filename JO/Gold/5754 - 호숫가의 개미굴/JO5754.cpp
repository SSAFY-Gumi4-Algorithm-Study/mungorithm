#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>
#include<unordered_set>
#include<unordered_map>
#include<cstring>
#include <set>
#include <map>
using namespace std;

using ll = long long;

int n;
ll a[250001];
const ll INF = (1LL << 60);

ll solve(ll dp0, ll dp1) {
	bool flag = dp1 == 1;
	for (int i = 2; i <= n; i++) {
		ll ndp0 = max(dp0, dp1) + a[i];
		ll ndp1 = dp0 + 1;

		dp0 = ndp0;
		dp1 = ndp1;
	}

	if (flag) return dp0;
	else return max(dp0, dp1);
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}

	cout << max(solve(-INF, 1), solve(a[1], -INF));
}
