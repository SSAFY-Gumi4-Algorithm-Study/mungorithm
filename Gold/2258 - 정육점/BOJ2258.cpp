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

int n, m;
vector<pair<int, int>> v;
int psum[100001];

bool cmp(pair<int, int> a, pair<int, int> b) {
	if (a.second == b.second) return a.first > b.first;
	return a.second < b.second;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> n >> m;
	int sum = 0;
	for (int i = 0; i < n; i++) {
		int w, c;
		cin >> w >> c;
		v.push_back({ w, c });
		sum += w;
	}
	if (sum < m) {
		cout << -1;
		return 0;
	}
	sort(v.begin(), v.end(), cmp);

	int cheapSum = 0;
	int weight = 0;
	int ret = INT_MAX;

	for (int i = 0; i < n;) {
		int p = v[i].second;
		vector<int> same;

		while (i < n && v[i].second == p) {
			same.push_back(v[i].first);
			i++;
		}

		sort(same.rbegin(), same.rend());

		int cur = cheapSum;

		for (int j = 0; j < same.size(); j++) {
			cur += same[j];

			if (cur >= m) {
				ret = min(ret, p * (j + 1));
				break;
			}
		}
		for (int num : same) {
			cheapSum += num;
		}
	}

	cout << ret;
}
