#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
#include<deque>
#include<tuple>
#include<string>
#include<unordered_map>
#include<unordered_set>
#include<cmath>

using namespace std;

int n;
int a[601];

bool check(pair<int,int> x, pair<int,int> y) {
	if (x.first != y.first && x.first != y.second && x.second != y.first && x.second != y.second) return false;
	return true;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	vector<pair<int, pair<int,int>>> v;
	for (int i = 0; i < n; i++) {
		for (int j = i + 1; j < n; j++) {
			v.push_back({ a[i] + a[j], {i, j} });
		}
	}
	int ret = 2000000001;
	sort(v.begin(), v.end());
	for (int i = 0; i < v.size(); i++) {
		for (int j = i + 1; j < v.size(); j++) {
			if (check(v[i].second, v[j].second)) continue;
			ret = min(ret, v[j].first - v[i].first);
			break;
		}
	}
	cout << ret;
}
