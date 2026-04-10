#include <iostream>
#include <algorithm>
#include <deque>
#include <vector>
#include <queue>
#include <cmath>
#include <stack>
#include <unordered_set>
#include <unordered_map>
#include <map>
#include <set>
#include <string>
#include <tuple>
#include <climits>
using namespace std;

int n, m;
vector<int> elevator[101];
vector<int> graph[100001];
int a, b;
int visited[100001];
int usedElevator[100001];
int prevFloor[100001];
queue<int> q;
bool used[101];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> n >> m;
	fill(visited, visited + 100001, -1);
	for (int i = 1; i <= m; i++) {
		int s, f;
		cin >> s >> f;
		for (int j = s; j <= n; j += f) {
			elevator[i].push_back(j);
			graph[j].push_back(i);
		}
	}
	cin >> a >> b;
	q.push(a);
	visited[a] = 0;

	while (!q.empty()) {
		int cur = q.front();
		q.pop();
		if (cur == b) break;
		for (int idx : graph[cur]) {
			if (used[idx]) continue;
			used[idx] = true;

			for (int next : elevator[idx]) {
				if (visited[next] != -1) continue;
				q.push(next);
				visited[next] = visited[cur] + 1;
				prevFloor[next] = cur;
				usedElevator[next] = idx;
			}
		}
	}

	if (visited[b] == -1) {
		cout << -1;
		return 0;
	}

	cout << visited[b] << '\n';

	vector<int> path;
	int cur = b;

	while (cur != a) {
		path.push_back(usedElevator[cur]);
		cur = prevFloor[cur];
	}

	for (int i = path.size() - 1; i >= 0; i--) {
		cout << path[i] << '\n';
	}
}
