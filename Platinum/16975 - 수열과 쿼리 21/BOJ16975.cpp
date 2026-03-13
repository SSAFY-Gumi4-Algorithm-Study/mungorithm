#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <set>
#include <unordered_set>
using namespace std;

int n, m;
int a[100001];
long long tree[100001];

void update(int idx, long long val) {
	while (idx <= n) {
		tree[idx] += val;
		idx += idx & -idx;
	}
}

long long query(int idx) {
	long long sum = 0;
	while (idx > 0) {
		sum += tree[idx];
		idx -= idx & -idx;
	}
	return sum;
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}

	update(1, a[1]);
	for (int i = 2; i <= n; i++) {
		update(i, a[i] - a[i - 1]);
	}

	cin >> m;
	for (int i = 0; i < m; i++) {
		int cmd;
		cin >> cmd;
		if (cmd == 1) {
			int a, b, val;
			cin >> a >> b >> val;
			update(a, val);
			if (b + 1 <= n) {
				update(b + 1, -val);
			}
		}
		else {
			int idx;
			cin >> idx;
			cout << query(idx) << '\n';
		}
	}
}
          
