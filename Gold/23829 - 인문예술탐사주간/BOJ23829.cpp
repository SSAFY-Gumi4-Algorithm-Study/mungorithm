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
using namespace std;

int n, q;
int a[100001];
long long psum[100001];
long long ret = 0;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	
	cin >> n >> q;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	sort(a + 1, a + n + 1);
	for (int i = 1; i <= n; i++) {
		psum[i] = psum[i - 1] + a[i];
	}
	for (int i = 0; i < q; i++) {
		ret = 0;
		int x;
		cin >> x;
		int idx = upper_bound(a + 1, a + n + 1, x) - a;
		ret += (long long)(idx - 1) * x - psum[idx - 1];
		ret += (psum[n] - psum[idx - 1]) - (long long)(n - idx + 1) * x;
		cout << ret << '\n';
	}
}
