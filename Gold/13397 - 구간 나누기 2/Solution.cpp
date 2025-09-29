#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>
#include<unordered_map>
using namespace std;

int n, m;
int a[5001];

bool check(int x) {
	int cnt = 1;
	int mn = a[0];
	int mx = a[0];
	for (int i = 0; i < n; i++) {
		mx = max(mx, a[i]);
		mn = min(mn, a[i]);
		int diff = mx - mn;
		if (diff <= x) continue;
		cnt++;
		mn = a[i];
		mx = a[i];
	}
	return cnt <= m;
}

int main() {
	cin >> n >> m;
	int l = 0;
	int mx = -1;
	int mn = 10001;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
		mx = max(mx, a[i]);
		mn = min(mn, a[i]);
	}
	int r = mx - mn;
	int ret = 0;
	while (l <= r) {
		int mid = (l + r) / 2;
		if (check(mid)) {
			r = mid - 1;
			ret = mid;
		}
		else {
			l = mid + 1;
		}
	}
	cout << ret;
}