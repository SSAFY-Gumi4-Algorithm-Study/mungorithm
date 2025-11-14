#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
#include<tuple>
#include<string>
#include<unordered_map>
#include<unordered_set>

using namespace std;

int n, m;
vector<int> tree;
vector<int> a;
int len;

void update(int idx, int val) {
	a[idx] = val;
	idx += len;
	while (idx > 0) {
		idx /= 2;
		if (a[tree[idx * 2]] <= a[tree[idx * 2 + 1]]) {
			tree[idx] = tree[idx * 2];
		}
		else tree[idx] = tree[idx * 2 + 1];
	}
}

int get(int idx, int s, int e, int ts, int te) {
	if (s > te || e < ts) return -1;
	else if (s >= ts && e <= te) return tree[idx];
	int mid = (s + e) / 2;
	int l = get(idx * 2, s, mid, ts, te);
	int r = get(idx * 2 + 1, mid + 1, e, ts, te);
	if (l == -1) return r;
	if (r == -1) return l;
	if (a[l] > a[r]) {
		return r;
	}
	return l;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> n;
	len = 1;
	while (len < n) {
		len <<= 1;
	}
	tree.resize(len * 2);
	a.resize(len * 2);

	for (int i = 0; i < n; i++) {
		cin >> a[i];
		tree[i + len] = i;
	}

	for (int i = len - 1; i >= 0; i--) {
		if (a[tree[i * 2]] <= a[tree[i * 2 + 1]]) {
			tree[i] = tree[i * 2];
		}
		else tree[i] = tree[i * 2 + 1];
	}

	cin >> m;
	for (int i = 0; i < m; i++) {
		int cmd, b, c;
		cin >> cmd >> b >> c;
		if (cmd == 1) {
			update(b - 1, c);
		}
		else cout << get(1, 0, len - 1, b - 1, c - 1) + 1 << '\n';
	}
}
