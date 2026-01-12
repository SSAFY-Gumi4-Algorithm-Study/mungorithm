#include <iostream>
#include <algorithm>
#include <deque>
#include <vector>
#include <queue>
#include <cmath>
#include <unordered_set>
#include <unordered_map>
#include <map>
#include <set>
#include <string>
#include <tuple>
#include <climits>
using namespace std;

int n;
int a[100001], psum[100001];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
		psum[i] = psum[i - 1] + a[i];
	}

	int ret = -987654321;
	for (int i = 2; i < n; i++) {
		int val1 = psum[n] - psum[1] - a[i] + psum[n] - psum[i];
		ret = max(ret, val1);
		int val2 = psum[n - 1] - a[i] + psum[i - 1];
		ret = max(ret, val2);
		int val3 = psum[i] - psum[1] + psum[n - 1] - psum[i - 1];
		ret = max(ret, val3);
	}

	cout << ret;
}
