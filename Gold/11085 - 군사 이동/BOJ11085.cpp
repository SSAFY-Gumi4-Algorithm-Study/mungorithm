#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <set>
#include <unordered_set>
using namespace std;

int n, m;
int c, v;
int parent[1001];

struct Edge {
	int a, b, w;
	
	bool operator < (const Edge& other) const {
		return w > other.w;
	}
};

vector<Edge> edge;

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

int main(){
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	
	cin >> n >> m;
	cin >> c >> v;
	for (int i = 0; i < n; i++) {
		parent[i] = i;
	}
	for (int i = 0; i < m; i++) {
		int a, b, w;
		cin >> a >> b >> w;
		edge.push_back({ a, b, w });
	}
	sort(edge.begin(), edge.end());

	for (int i = 0; i < edge.size(); i++) {
		Edge& e = edge[i];
		if (merge(e.a, e.b)) {
			if (find(c) == find(v)) {
				cout << e.w;
				break;
			}
		}
	}
}
