#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
#include<tuple>
#include<string>
#include<map>
#include<unordered_map>
#include<unordered_set>
#include<cmath>
using namespace std;

int n, m, k;
int a[30001], parent[30001], cnt[30001], sum[30001];
int dp[3001];
vector<int> graph[30001];
vector<int> v;

int find(int x) {
	if (x == parent[x]) return x;
	return parent[x] = find(parent[x]);
}

void merge(int x, int y) {
	x = find(x);
	y = find(y);
	if (x == y) return;
	parent[y] = x;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> n >> m >> k;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	for (int i = 1; i <= n; i++) {
		parent[i] = i;
	}
	for (int i = 0; i < m; i++) {
		int from, to;
		cin >> from >> to;
		graph[from].push_back(to);
		graph[to].push_back(from);
		merge(from, to);
	}

	for (int i = 1; i <= n; i++) {
		find(i);
	}
	unordered_set<int> st;
	for (int i = 1; i <= n; i++) {
		cnt[parent[i]]++;
		sum[parent[i]] += a[i];
		if (!st.count(parent[i])) {
			v.push_back(i);
		}
	}

	dp[0] = 0;
	for (int i = 0; i < v.size(); i++) {
		for (int j = k - 1; j >= cnt[v[i]]; j--) {
			dp[j] = max(dp[j], dp[j - cnt[v[i]]] + sum[v[i]]);
		}
	}
	
	int ret = -1;
	for (int i = 0; i < k; i++) {
		ret = max(ret, dp[i]);
	}
	cout << ret;
}
