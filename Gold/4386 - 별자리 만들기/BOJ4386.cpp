#include <iostream>
#include <algorithm>
#include <deque>
#include <vector>
#include <queue>
#include <cmath>
#include <unordered_set>
#include <unordered_map>
#include <map>
#include <set>
#include <string>
#include <tuple>
#include <climits>
using namespace std;

int n;
vector<pair<double, double>> v;
vector<pair<double, pair<int, int>>> edge;
int parent[101];

int find(int x) {
	if (x == parent[x]) return x;
	return parent[x] = find(parent[x]);
}

bool merge(int x, int y) {
	x = find(x);
	y = find(y);
	if (x == y) return false;
	parent[y] = x;
	return true;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> n;
	for (int i = 0; i < n; i++) {
		double x, y;
		cin >> x >> y;
		v.push_back({ x, y });
	}
	for (int i = 0; i < n; i++) {
		parent[i] = i;
	}
	for (int i = 0; i < n - 1; i++) {
		for (int j = i + 1; j < n; j++) {
			double dist = sqrt(pow((v[i].first - v[j].first), 2) + pow((v[i].second - v[j].second), 2));
			edge.push_back({ dist, {i, j} });
		}
	}
	sort(edge.begin(), edge.end());
	double ret = 0;
	int cnt = 0;
	for (auto p : edge) {
		int a = p.second.first;
		int b = p.second.second;
		if (merge(a, b)) {
			cnt++;
			ret += p.first;
		}
		if (cnt == n - 1) break;
	}
	cout << fixed;
	cout.precision(2);
	cout << ret;
}
