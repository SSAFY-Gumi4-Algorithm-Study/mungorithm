#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int n, m, d;
vector<int> v;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> n >> m >> d;
	int l = 1;

	for (int i = 0; i < n; i++) {
		int num;
		cin >> num;
		v.push_back(num);
	}
	v.push_back(0);
	v.push_back(d);
	sort(v.begin(), v.end());

	int r = d;

	int ret = 0;
	while (l <= r) {
		int mid = (l + r) / 2;
		int sum = 0;

		for (int i = 0; i < v.size() - 1; i++) {
			sum += (v[i + 1] - v[i] - 1) / mid;
		}

		if (sum <= m) {
			ret = mid;
			r = mid - 1;
		}
		else {
			l = mid + 1;
		}
	}
	cout << ret << '\n';
}
