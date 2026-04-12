#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <set>
#include <unordered_set>
#include <cstring>
using namespace std;

int n;
int a[51];
vector<int> tree[51];

int dfs(int cur) {
	vector<int> v;
	for (int next : tree[cur]) {
		v.push_back(dfs(next));
	}

	if (v.size() == 0) return 0;

	sort(v.rbegin(), v.rend());

	int ret = 0;
	for (int i = 0; i < v.size(); i++) {
		ret = max(ret, v[i] + i + 1);
	}

	return ret;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
		if (i == 0) continue;
		tree[a[i]].push_back(i);
	}

	cout << dfs(0);
}
