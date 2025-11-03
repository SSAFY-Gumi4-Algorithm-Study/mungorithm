#include<iostream>
#include<vector>
#include<algorithm>
#include<map>
#include<unordered_map>
#include<unordered_set>
#include<deque>
#include<string>
#include<cmath>
#include<set>
#include<queue>

using namespace std;
int n, m;
string s[300001];
unordered_map<int, int> mp;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		cin >> s[i];
	}
	long long ret = 0;
	int l = 0;
	int r = m;
	for (int i = 0; i <= m; i++) {
		mp[s[i].size()]++;
	}
	for (int i = 0; i < n; i++) {
		if (mp[s[i].size()] >= 2) {
			ret += mp[s[i].size()] - 1;
		}
		mp[s[l++].size()]--;
		if(r != n - 1) mp[s[++r].size()]++;
	}
	cout << ret;
}
