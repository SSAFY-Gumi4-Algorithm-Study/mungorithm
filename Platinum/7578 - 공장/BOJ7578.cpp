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
int len = 1;
vector<int> tree;
int a[500001], b[500001];
unordered_map<int, int> mp;

int get(int idx, int s, int e, int ts, int te) {
	if (e < ts || s > te) return 0;
	if (s >= ts && e <= te) return tree[idx];
	int mid = (s + e) / 2;
	return get(idx << 1, s, mid, ts, te) + get((idx << 1) + 1, mid + 1, e, ts, te);
}

void update(int idx) {
	idx += len;
	tree[idx] = 1;
	idx >>= 1;
	while (idx) {
		tree[idx] = tree[idx << 1] + tree[(idx << 1) + 1];
		idx >>= 1;
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> n;
	while (len < n) {
		len <<= 1;
	}

	tree.resize(2 * len);

	for (int i = 0; i < n; i++) {
		cin >>  a[i];
	}
	for (int i = 0; i < n; i++) {
		int x;
		cin >> x;
		mp[x] = i;
	}
	for (int i = 0; i < n; i++) {
		b[i] = mp[a[i]];
	}
	long long ret = 0;

	for (int i = 0; i < n; i++) {
		int p = b[i];
		if (p + 1 <= n - 1) {
			ret += get(1, 0, len - 1, p + 1, n - 1);
		}
		update(p);
	}
	cout << ret;
}
