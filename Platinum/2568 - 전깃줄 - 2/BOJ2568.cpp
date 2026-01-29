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
vector<pair<int, int>> line;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	
	cin >> n;
	line.resize(n);

	for (int i = 0; i < n; i++) {
		cin >> line[i].first >> line[i].second;
	}
	sort(line.begin(), line.end());

	vector<int> dp;
	vector<int> pos(n);
	vector<int> parent(n, -1);

	for (int i = 0; i < n; i++) {
		int b = line[i].second;
		int p = lower_bound(dp.begin(), dp.end(), b) - dp.begin();
		
		if (p == dp.size()) dp.push_back(b);
		else dp[p] = b;

		pos[p] = i;
		if (p > 0) parent[i] = pos[p - 1];
	}

	vector<bool> inLis(n, false);
	int cur = pos[dp.size() - 1];
	while (cur != -1) {
		inLis[cur] = true;
		cur = parent[cur];
	}

	vector<int> remove;
	for (int i = 0; i < n; i++) {
		if (!inLis[i]) {
			remove.push_back(line[i].first);
		}
	}
	sort(remove.begin(), remove.end());

	cout << remove.size() << '\n';
	for (int x : remove) cout << x << '\n';
}
