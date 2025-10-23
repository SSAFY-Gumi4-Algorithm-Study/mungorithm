#include<iostream>
#include<vector>
#include<algorithm>
#include<tuple>
#include<string>
#include<unordered_set>
#include<stack>
#include<cmath>
#include<queue>
using namespace std;

typedef long long ll;

int n;
int len;
vector<int> tree, h;

int findIdx(int idx, int s, int e, int ts, int te) {
	if (s > te || e < ts) return -1;
	else if (s >= ts && e <= te) return tree[idx];
	int mid = (s + e) / 2;
	int l = findIdx(idx * 2, s, mid, ts, te);
	int r = findIdx(idx * 2 + 1, mid + 1, e, ts, te);

	if (l == -1) return r;
	if (r == -1) return l;

	if (h[l] > h[r]) return r;
	else return l;
}

ll findSquare(int s, int e) {
	int idx = findIdx(1, 0, len - 1, s, e);
	ll ret = (ll)(e - s + 1) * (ll)h[idx];

	if (s < idx) {
		ret = max(ret, findSquare(s, idx - 1));
	}

	if (e > idx) {
		ret = max(ret, findSquare(idx + 1, e));
	}
	return ret;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	while(true){
		cin >> n;
		if (n == 0) return 0;
		len = 1;
		while (len < n) len <<= 1;
		tree.assign(2 * len, 0);
		h.assign(n + 1, 0);

		for (int i = 0; i < n; i++) {
			cin >> h[i];
			tree[i + len] = i;
		}
		for (int i = len - 1; i > 0; i--) {
			if (h[tree[i * 2]] > h[tree[i * 2 + 1]]) {
				tree[i] = tree[i * 2 + 1];
			}
			else tree[i] = tree[i * 2];
		}
		cout << findSquare(0, n - 1) << '\n';
	}
}
