#include<iostream>
#include<vector>
#include<algorithm>
#include<map>
#include<unordered_map>
#include<deque>
#include<string>
#include<cmath>
#include<set>
#include<queue>

using namespace std;

int n, m;
string name[1001];
int ind[1001];
vector<int> graph[1001];
unordered_map<string, int> mp;
map<string, set<string>> a;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> name[i];
		mp[name[i]] = i;
		a[name[i]];
	}
	cin >> m;
	for (int i = 0; i < m; i++) {
		string x, y;
		cin >> x >> y;
		ind[mp[x]]++;
		graph[mp[y]].push_back(mp[x]);
	}
	queue<int> q;
	vector<string> root;
	for (int i = 0; i < n; i++) {
		if (ind[i] == 0) {
			q.push(i);
			root.push_back(name[i]);
		}
	}
	while (!q.empty()) {
		int cur = q.front();
		q.pop();
		for (int next : graph[cur]) {
			ind[next]--;
			if (ind[next] == 0) {
				q.push(next);
				a[name[cur]].insert(name[next]);
			}
		}
	}
	sort(root.begin(), root.end());
	cout << root.size() << '\n';
	for (string s : root) {
		cout << s << ' ';
	}
	cout << '\n';
	for (auto p : a) {
		cout << p.first << ' ' << p.second.size() << ' ';
		for (string s : p.second) {
			cout << s << ' ';
		}
		cout << '\n';
	}
}
