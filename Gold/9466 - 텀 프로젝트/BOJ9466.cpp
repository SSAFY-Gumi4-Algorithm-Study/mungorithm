#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <set>
#include <unordered_set>
#include <cstring>
using namespace std;

int T;
int n;
int a[100001], visited[100001], finished[100001];
int cnt = 0;

void init() {
	fill(visited, visited + 100001, 0);
	fill(finished, finished + 100001, 0);
	cnt = 0;
}

void dfs(int cur) {
	visited[cur] = 1;
	int next = a[cur];

	if (!visited[next]) dfs(next);
	else if (!finished[next]) {
		while (next != cur) {
			next = a[next];
			cnt++;
		}
		cnt++;
	}
	finished[cur] = 1;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> T;
	for (int t = 1; t <= T; t++) {
		init();
		cin >> n;
		for (int i = 1; i <= n; i++) {
			cin >> a[i];
		}

		for (int i = 1; i <= n; i++) {
			if (visited[i]) continue;
			dfs(i);
		}

		cout << n - cnt << '\n';
	}
}
