#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

int n, m;
vector<int> v;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> n >> m;
	v.resize(m);
	for (int i = 0; i < m; i++) {
		cin >> v[i];
	}
	sort(v.begin(), v.end());

	int l = 1;
	int r = v[m - 1];

	int ret = 0;

	while (l <= r) {
		int mid = (l + r) / 2;
		int cnt = 0;
		for (int i = 0; i < m; i++) {
			cnt += v[i] / mid;
			if (v[i] % mid != 0) cnt++;
		}
		if (cnt <= n) {
			r = mid - 1;
			ret = mid;
		}
		else {
			l = mid + 1;
		}
	}
	cout << ret;
}