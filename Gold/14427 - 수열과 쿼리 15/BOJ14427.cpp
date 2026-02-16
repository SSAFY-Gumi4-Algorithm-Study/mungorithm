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
int a[100001];
vector<int> tree;

void update(int idx, int val) {
	a[idx] = val;
	idx += len - 1;
	while (idx /= 2) {
		if (a[tree[idx * 2]] <= a[tree[idx * 2 + 1]]) tree[idx] = tree[idx * 2];
		else tree[idx] = tree[idx * 2 + 1];
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> n;

	while (len < n) len <<= 1;
	tree.resize(len * 2);

	a[0] = 987654321;
	for (int i = 0; i < n; i++) {
		cin >> a[i + 1];
		tree[len + i] = i + 1;
	}
	for (int i = len - 1; i > 0; i--) {
		if (a[tree[i * 2]] <= a[tree[i * 2 + 1]]) tree[i] = tree[i * 2];
		else tree[i] = tree[i * 2 + 1];
	}

	cin >> m;

	for (int i = 0; i < m; i++) {
		int cmd;
		cin >> cmd;
		if (cmd == 1) {
			int idx, val;
			cin >> idx >> val;
			update(idx, val);
		}
		else cout << tree[1] << '\n';
	}
}
