#include<iostream>
#include<vector>
#include<queue>
#include<unordered_set>
#include<unordered_map>
#include<cstring>
#include <set>
#include <map>
using namespace std;

int n, q;
unordered_map<int, set<int>> mp;
int cnt[100001];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> n >> q;
	for (int i = 1; i <= n; i++) {
		mp[0].insert(i);
	}

	for (int i = 0; i < q; i++) {
		int cmd;
		int a, b;
		cin >> cmd;
		if (cmd == 0) {
			cin >> a >> b;
			mp[cnt[a]].erase(a);
			cnt[a] += b;
			mp[cnt[a]].insert(a);
		}
		else {
			cin >> a;
			if (mp[a].size() == 0) cout << "None";
			for (int x : mp[a]) {
				cout << x << ' ';
			}
			cout << '\n';
		}
	}
}
