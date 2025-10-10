#include<iostream> 
#include<algorithm> 
#include<vector> 
#include<tuple>
#include<unordered_map>
#include<map>
#include<string>
#include<unordered_set>
#include<cmath>
using namespace std;

int n, m;
vector<pair<int, int>> v;
vector<tuple<double, int, int>> graph;
int parent[1001];

int find(int x) {
	if (parent[x] == x) return x;
	return parent[x] = find(parent[x]);
}

bool merge(int x, int y) {
	x = find(x);
	y = find(y);
	if (x == y) return false;
	parent[x] = y;
	return true;
}

int main() {
	cin >> n >> m;
	v.resize(n + 1);
	for (int i = 1; i <= n; i++) {
		cin >> v[i].first >> v[i].second;
	}
	for (int i = 1; i <= n; i++) {
		for (int j = i + 1; j <= n; j++) {
			graph.push_back({ sqrt(pow(v[i].first - v[j].first, 2) + pow(v[i].second - v[j].second, 2)), i, j });
		}
	}
	sort(graph.begin(), graph.end());
	for (int i = 1; i <= n; i++) {
		parent[i] = i;
	}
	int cnt = 0;
	for (int i = 0; i < m; i++) {
		int a, b;
		cin >> a >> b;
		if (merge(a, b)) cnt++;
	}
	double ret = 0;
	
	for (auto g : graph) {
		double cost = get<0>(g);
		int a = get<1>(g);
		int b = get<2>(g);
		if (merge(a, b)) {
			ret += cost;
			cnt++;
		}
		if (cnt == n - 1) break;
	}
	cout << fixed;
	cout.precision(2);
	cout << ret;
}
