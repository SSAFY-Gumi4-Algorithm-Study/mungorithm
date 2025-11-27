#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
#include<tuple>
#include<string>
#include<unordered_map>
#include<unordered_set>
#include<cmath>

using namespace std;

string s, t;
priority_queue<int, vector<int>, greater<int>> pq[26];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> s;
	cin >> t;
	for (int i = 0; i < s.size(); i++) {
		pq[s[i] - 'a'].push(i);
	}

	int ret = 0;

	bool flag = false;

	while (!flag) {
		int idx = -1;
		for (int i = 0; i < t.size(); i++) {
			int a = t[i] - 'a';
			while (!pq[a].empty() && pq[a].top() < idx) {
				pq[a].pop();
			}
			if (pq[a].empty()) {
				flag = true;
				break;
			}
			idx = pq[a].top();
			pq[a].pop();
		}
		if (!flag) ret++;
	}
	cout << ret;
}
