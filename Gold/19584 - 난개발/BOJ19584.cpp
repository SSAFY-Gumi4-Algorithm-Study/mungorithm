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
using namespace std;

int n, m;
int h[200001];
vector<tuple<int, int, int>> v;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		int x, y;
		cin >> x >> y;
		h[i] = y;
	}

	for (int i = 0; i < m; i++) {
		int a, b, c;
		cin >> a >> b >> c;
		if (h[a] > h[b]) {
			swap(a, b);
		}
		v.push_back({ h[a], 0, c});
		v.push_back({ h[b], 1, c});
	}
	
	sort(v.begin(), v.end());

	long long mx = 0;
	long long ret = 0;
	for (int i = 0; i < v.size() - 1; i++) {
		int cur = get<0>(v[i]);
		int flag = get<1>(v[i]);
		int cost = get<2>(v[i]);
		if (flag == 0) ret += cost;
		else ret -= cost;
		
		mx = max(ret, mx);
	}
	mx = max(ret, mx);
	cout << mx;
}
