#include<iostream>
#include<vector>
#include<algorithm>
#include<cmath>
#include<map>
#include<unordered_map>
#include<set>
#include<unordered_set>
#include<deque>
#include<queue>
#include<string>

using namespace std;

int n, m;
vector<tuple<int, int, int>> edge;
int parent[200001];

int find(int x) {
	if (parent[x] == x) return x;
	return parent[x] = find(parent[x]);
}

bool merge(int x, int y) {
	x = find(x);
	y = find(y);
	if (x != y) {
		parent[x] = y;
		return true;
	}
	return false;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	while (true) {
		edge.clear();
		cin >> n >> m;
		if (n == 0 && m == 0) return 0;
		for (int i = 0; i < n; i++) {
			parent[i] = i;
		}
		int full = 0;
		for (int i = 0; i < m; i++) {
			int a, b, c;
			cin >> a >> b >> c;
			edge.push_back({ c, a, b });
			full += c;
		}
		sort(edge.begin(), edge.end());
		int cnt = 0;
		int ret = 0;
		for (int i = 0; i < edge.size(); i++) {
			int cost = get<0>(edge[i]);
			int a = get<1>(edge[i]);
			int b = get<2>(edge[i]);
			if (merge(a, b)) {
				ret += cost;
				cnt++;
			}
			if (cnt == n - 1) break;
		}
		cout << full - ret << '\n';
	}
}
