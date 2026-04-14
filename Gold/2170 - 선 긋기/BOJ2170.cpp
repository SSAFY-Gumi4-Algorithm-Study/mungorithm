#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <set>
#include <unordered_set>
#include <cstring>
using namespace std;

int n;
int l, r;

struct Line {
	int l, r;
	bool operator < (Line& other) const {
		return l < other.l;
	}
};

vector<Line> v;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	
	cin >> n;

	int ret = 0;

	for (int i = 0; i < n; i++) {
		int from, to;
		cin >> from >> to;
		v.push_back({from, to});
	}
	sort(v.begin(), v.end());

	l = v[0].l;
	r = v[0].r;
	for (int i = 1; i < n; i++) {
		if (r < v[i].l) {
			ret += r - l;
			r = v[i].r;
			l = v[i].l;
		}
		else {
			r = max(r, v[i].r);
			l = min(l, v[i].l);
		}
	}
	ret += r - l;
	cout << ret;
}
