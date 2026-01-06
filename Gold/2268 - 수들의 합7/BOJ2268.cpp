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

int n, m;
int len = 1;
vector<long long> tree;

void update(int idx, int val) {
	idx += len;
	tree[idx] = val;
	idx /= 2;
	while (idx >= 1) {
		tree[idx] = tree[2 * idx] + tree[2 * idx + 1];
		idx /= 2;
	}
}

long long get(int idx, int s, int e, int ts, int te) {
	if (s > te || e < ts) return 0;
	else if (ts <= s && te >= e) return tree[idx];
	int mid = (s + e) / 2;
	long long l = get(2 * idx, s, mid, ts, te);
	long long r = get(2 * idx + 1, mid + 1, e, ts, te);
	return l + r;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> n >> m;

	while (len < n) {
		len <<= 1;
	}
	tree.assign(2 * len, 0);

	for (int i = 0; i < m; i++) {
		int cmd, a, b;
		cin >> cmd >> a >> b;
		if (cmd) {
			update(a - 1, b);
		}
		else {
			if (a > b) swap(a, b);
			cout << get(1, 0, len - 1, a - 1, b - 1) << '\n';
		}
	}
}
