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
using ll = long long;

int n;
int len = 1;
vector<int> tree;
vector<int> a, comp;

void update(int idx) {
	idx += len;
	tree[idx] += 1;
	while (idx > 1) {
		idx /= 2;
		tree[idx] = tree[idx * 2] + tree[idx * 2 + 1];
	}
}

ll query(int idx, int s, int e, int ts, int te) {
	if (e < ts || s > te) return 0;
	if (ts <= s && te >= e) return tree[idx];
	int mid = (s + e) / 2;
	return query(idx * 2, s, mid, ts, te) + query(idx * 2 + 1, mid + 1, e, ts, te);
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	
	cin >> n;
	a.resize(n);

	for (int i = 0; i < n; i++) {
		cin >> a[i];
		comp.push_back(a[i]);
	}

	sort(comp.begin(), comp.end());
	comp.erase(unique(comp.begin(), comp.end()), comp.end());

	int m = comp.size();

	while (len < m) {
		len <<= 1;
	}

	tree.resize(len * 2);

	ll ret = 0;

	for (int i = 0; i < n; i++) {
		int idx = lower_bound(comp.begin(), comp.end(), a[i]) - comp.begin();
	
		if (idx + 1 <= m - 1) {
			ret += query(1, 0, len - 1, idx + 1, m - 1);
		}

		update(idx);
	}

	cout << ret;
}
