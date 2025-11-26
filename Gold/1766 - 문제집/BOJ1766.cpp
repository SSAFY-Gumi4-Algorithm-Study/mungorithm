#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
#include<tuple>
#include<string>
#include<unordered_map>
#include<unordered_set>
#include<cmath>

using namespace std;

int n, m;
int a[32001], ind[32001];
vector<int> v[32001];
vector<int> ret;


int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		int from, to;
		cin >> from >> to;
		v[from].push_back(to);
		ind[to]++;
	}
	priority_queue<int, vector<int>, greater<int>> pq;
	for (int i = 1; i <= n; i++) {
		if (ind[i] == 0) pq.push(i);
	}

	while (!pq.empty()) {
		int cur = pq.top();
		ret.push_back(cur);
		pq.pop();
		for (int next : v[cur]) {
			ind[next]--;
			if (ind[next] == 0) {
				pq.push(next);
			}
		}
	}
	for (int num : ret) {
		cout << num << ' ';
	}
}
