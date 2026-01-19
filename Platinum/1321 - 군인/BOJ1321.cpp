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
vector<long long> tree;
int len = 1;

void update(int idx, int val) {
	idx += len;
	tree[idx] += val;
	idx /= 2;
	while (idx > 0) {
		tree[idx] = tree[idx << 1] + tree[idx << 1 | 1];
		idx /= 2;
	}
}

int find(int idx, int s, int e, long long k) {
	if (s == e) return s;

	int mid = (s + e) / 2;
	long long lsum = tree[idx << 1];

	if (k <= lsum) return find(idx * 2, s, mid, k);
	return find(idx * 2 + 1, mid + 1, e, k - lsum);
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
		cin >> tree[len + i];
	}

	for (int i = len - 1; i > 0; i--) {
		tree[i] = tree[i << 1] + tree[(i << 1) | 1];
	}

	cin >> m;
	for (int i = 0; i < m; i++) {
		int cmd;
		cin >> cmd;
		if (cmd == 1) {
			int a, b;
			cin >> a >> b;
			update(a - 1, b);
		}
		else {
			int x;
			cin >> x;
			cout << find(1, 0, len - 1, x) + 1 << '\n';
		}
	}
}
