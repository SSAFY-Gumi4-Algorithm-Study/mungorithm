#include <iostream>
#include <algorithm>
#include <deque>
#include <vector>
#include <queue>
#include <cmath>
#include <unordered_set>
#include <map>
#include <set>
using namespace std;

int n;
vector<pair<int, int>> v;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	
	cin >> n;
	for (int i = 0; i < n; i++) {
		int l, r;
		cin >> l >> r;
		v.push_back({ l, 0 });
		v.push_back({ r, 1 });
	}
	sort(v.begin(), v.end());

	int cnt = 0;
	int ret = 0;
	int l = -1, r = -1;
	bool flag = false;
	for (int i = 0; i < v.size() - 1; i++) {
		int x = v[i].first;
		int nx = v[i + 1].first;
		cnt = v[i].second == 0 ? cnt + 1 : cnt - 1;
		if (x == nx ) continue;
		if (ret < cnt) {
			ret = cnt;
			l = x;
			flag = true;
		}
		else if(ret > cnt && flag){
			flag = false;
			r = x;
		}
	}

	if (flag) r = v[v.size() - 1].first;

	cout << ret << '\n' << l << ' ' << r;
}
