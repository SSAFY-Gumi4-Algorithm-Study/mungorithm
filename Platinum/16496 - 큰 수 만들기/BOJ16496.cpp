#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <set>
#include <unordered_set>
#include <cstring>
using namespace std;

int n;
vector<string> v;
bool cmp(string a, string b) {
	return a + b > b + a;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> n;
	v.resize(n);
	for (int i = 0; i < n; i++) {
		cin >> v[i];
	}
	sort(v.begin(), v.end(), cmp);
	if (v[0] == "0") {
		cout << "0";
		return 0;
	}
	string ret = "";
	for (int i = 0; i < n; i++) {
		ret += v[i];
	}
	cout << ret;
}
