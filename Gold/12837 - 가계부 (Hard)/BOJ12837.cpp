#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <set>
#include <unordered_set>
using namespace std;

int n, m;
long long tree[1000001];

void update(int idx, int val) {
	while (idx < n + 1) {
		tree[idx] += val;
		idx += idx & -idx;
	}
}

long long get(int idx) {
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
	
	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		int cmd, a, b;
		cin >> cmd >> a >> b;
		if (cmd == 1) {
			update(a, b);
		}
		else {
			cout << get(b) - get(a - 1) << '\n';
		}
	}
}
          
