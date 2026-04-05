#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <set>
#include <unordered_set>
#include <cstring>
using namespace std;

int n;

struct Work {
	int len;
	int due;

	bool operator < (Work& other) const {
		return this->due > other.due;
	}
};

vector<Work> v;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> n;
	v.resize(n);
	for (int i = 0; i < n; i++) {
		cin >> v[i].len >> v[i].due;
	}
	sort(v.begin(), v.end());
	long long cur = 1e18;
	for (int i = 0; i < n; i++) {
		if (cur > v[i].due) cur = v[i].due;
		cur = cur - v[i].len;
	}
	cout << cur;
}
