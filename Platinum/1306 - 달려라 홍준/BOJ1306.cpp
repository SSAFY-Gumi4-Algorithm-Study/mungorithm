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
vector<int> tree;
int len = 1;

int get(int idx, int s, int e, int ts, int te) {
	if (s > te || e < ts) return -987654321;
	if (s >= ts && e <= te) return tree[idx];
	int mid = (s + e) / 2;
	int l = get(idx * 2, s, mid, ts, te);
	int r = get(idx * 2 + 1, mid + 1, e, ts, te);
	return max(l, r);
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> n >> m;

	while (len < n) {
		len <<= 1;
	}

	tree.resize(2 * len);
	for (int i = 0; i < n; i++) {
		cin >> tree[len + i];
	}

	for (int i = len - 1; i > 0; i--) {
		tree[i] = max(tree[i * 2], tree[i * 2 + 1]);
	}

	for (int i = m; i <= n - m + 1; i++) {
		cout << get(1, 0, len - 1, i - m, i + m - 2) << ' ';
	}
}
