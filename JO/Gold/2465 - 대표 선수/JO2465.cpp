#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>
#include<unordered_set>
#include<unordered_map>
#include<cstring>
#include <set>
#include <map>
using namespace std;

int n, m;

struct Student {
	int val;
	int c_idx;
	int s_idx;

	bool operator > (const Student& other) const {
		return val > other.val;
	}
};

int main() {
	cin >> n >> m;

	vector<vector<int>> v(n, vector<int>(m));

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> v[i][j];
		}
		sort(v[i].begin(), v[i].end());
	}

	priority_queue<Student, vector<Student>, greater<>> pq;

	int mx = -1;

	for (int i = 0; i < n; i++) {
		pq.push({ v[i][0], i, 0 });
		mx = max(mx, v[i][0]);
	}

	int mn = 987654321;
	int ret = 987654321;

	while (true) {
		Student cur = pq.top();
		pq.pop();

		ret = min(ret, mx - cur.val);

		if (cur.s_idx == m - 1) break;

		pq.push({ v[cur.c_idx][cur.s_idx + 1], cur.c_idx, cur.s_idx + 1 });
		mx = max(mx, v[cur.c_idx][cur.s_idx + 1]);
	}

	cout << ret;
}
