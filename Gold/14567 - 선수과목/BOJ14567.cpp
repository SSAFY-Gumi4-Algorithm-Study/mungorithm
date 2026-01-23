#include <iostream>
#include <algorithm>
#include <deque>
#include <vector>
#include <queue>
#include <cmath>
#include <stack>
#include <unordered_set>
#include <unordered_map>
#include <map>
#include <set>
#include <string>
#include <tuple>
#include <climits>
using namespace std;

int n, m;
int ind[1001];
vector<int> v[1001];
int ret[1001];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		int a, b;
		cin >> a >> b;
		v[a].push_back(b);
		ind[b]++;
	}
	queue<int> q;
	for (int i = 1; i <= n; i++) {
		if (ind[i] == 0) {
			q.push(i);
		}
	}
	while (!q.empty()) {
		int cur = q.front();
		q.pop();
		for (int next : v[cur]) {
			ret[next] = max(ret[next], ret[cur] + 1);
			ind[next]--;
			if (ind[next] == 0) {
				q.push(next);
			}
		}
	}
	for (int i = 1; i <= n; i++) {
		cout << ret[i] + 1 << ' ';
	}
}
