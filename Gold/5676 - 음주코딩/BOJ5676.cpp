#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <set>
#include <unordered_set>
using namespace std;

int len = 1;
vector<int> tree;
int n, m;

void init() {
	len = 1;
	tree.clear();
}

void update(int idx, int val) {
	if (val > 0) val = 1;
	else if (val < 0) val = -1;
	else val = 0;
	if (val == tree[idx + len]) return;
	idx += len;
	tree[idx] = val;
	idx /= 2;
	while (idx > 0) {
		tree[idx] = tree[idx * 2] * tree[idx * 2 + 1];
		idx /= 2;
	}
}

int get(int idx, int s, int e, int ts, int te) {
	if (ts > e || te < s) return 1;
	else if (ts <= s && te >= e) return tree[idx];
	int mid = (s + e) / 2;
	int l = get(idx * 2, s, mid, ts, te);
	int r = get(idx * 2 + 1, mid + 1, e, ts, te);
	return l * r;
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	
	while (cin >> n >> m) {
		init();
		
		while (len < n) len <<= 1;
		tree.assign(len * 2, 1);
		for (int i = 0; i < n; i++) {
			int num;
			cin >> num;
			if (num > 0) tree[i + len] = 1;
			else if (num < 0) tree[i + len] = -1;
			else tree[i + len] = 0;
		}
		for (int i = len - 1; i > 0; i--) {
			tree[i] = tree[i * 2] * tree[i * 2 + 1];
		}
		for (int i = 0; i < m; i++) {
			char cmd;
			int a, b;
			cin >> cmd >> a >> b;
			if (cmd == 'C') {
				update(a - 1, b);
			}
			else if (cmd == 'P') {
				int x = get(1, 0, len - 1, a - 1, b - 1);
				if (x == 1) cout << '+';
				else if (x == -1) cout << '-';
				else cout << '0';
			}
		}
		cout << '\n';
	}
}
