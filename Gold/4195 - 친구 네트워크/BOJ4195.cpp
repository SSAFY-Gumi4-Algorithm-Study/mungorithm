#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
#include<tuple>
#include<string>
#include<unordered_map>
#include<unordered_set>

using namespace std;

int T;
int n;
unordered_map<string, int> mp;
int check[200001];
int parent[200001];
int cnt = 1;

void init() {
	cnt = 1;
	fill(check, check + 200001, 1);
	for (int i = 1; i <= 200000; i++) {
		parent[i] = i;
	}
	mp.clear();
}

int find(int x) {
	if (x == parent[x]) return x;
	return parent[x] = find(parent[x]);
}

void merge(int x, int y) {
	x = find(x);
	y = find(y);
	if (x != y) {
		parent[y] = x;
		check[x] += check[y];
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> T;
	for (int t = 1; t <= T; t++) {
		init();
		cin >> n;
		
		for (int i = 0; i < n; i++) {
			string s1, s2;
			cin >> s1 >> s2;
			if (!mp.count(s1)) {
				mp[s1] = cnt++;
			}
			if (!mp.count(s2)) {
				mp[s2] = cnt++;
			}
			merge(mp[s1], mp[s2]);
			cout << check[find(mp[s1])] << '\n';
		}
	}
}
