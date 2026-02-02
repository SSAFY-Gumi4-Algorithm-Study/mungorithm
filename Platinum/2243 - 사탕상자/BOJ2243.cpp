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
vector<int> tree;
int len = 1;

void update(int idx, int val) {
	idx += len;
	tree[idx] += val;
	idx /= 2;
	while (idx > 0) {
		tree[idx] = tree[idx * 2] + tree[idx * 2 + 1];
		idx /= 2;
	}
}

int get(int idx, int s, int e, int val) {
	if (s == e) {
		update(s, -1);
		return s;
	}

	int l = tree[idx * 2];
	int mid = (s + e) / 2;

	if (val <= l) {
		return get(idx * 2, s, mid, val);
	}
	else {
		return get(idx * 2 + 1, mid + 1, e, val - l);
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	while (len < 1000000) {
		len <<= 1;
	}

	tree.resize(len * 2);

	cin >> n;

	for (int i = 0; i < n; i++) {
		int a, b, c;
		cin >> a;
		if (a == 1) {
			cin >> b;
			cout << get(1, 0, len - 1, b) << '\n';
		}
		else {
			cin >> b >> c;
			update(b, c);
		}
	}
}
