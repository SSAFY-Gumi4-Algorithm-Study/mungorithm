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

int n, m;
int a[1001][1001];
int visited[1001][1001];
pair<int,int> check[1001][1001];
int dy[] = { -1, 0, 1, 0 };
int dx[] = { 0, 1, 0, -1 };
vector<pair<int, int>> v;
int idx = 1;

int dfs(int y, int x) {
	visited[y][x] = 1;
	v.push_back({y, x });
	int cnt = 1;
	for (int i = 0; i < 4; i++) {
		int ny = y + dy[i];
		int nx = x + dx[i];
		if (ny < 0 || nx < 0 || ny >= n || nx >= m) continue;
		if (a[ny][nx] == 1 || visited[ny][nx]) continue;
		
		cnt += dfs(ny, nx);
	}
	return cnt;
}

void countZero(int y, int x) {
	unordered_set<int> st;
	for (int i = 0; i < 4; i++) {
		int ny = y + dy[i];
		int nx = x + dx[i];
		if (ny < 0 || nx < 0 || ny >= n || nx >= m) continue;
		if (a[ny][nx] == 1) continue;
		if (!st.count(check[ny][nx].second)) {
			a[y][x] = (a[y][x] + check[ny][nx].first) % 10;
			st.insert(check[ny][nx].second);
		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		string s;
		cin >> s;
		for (int j = 0; j < m; j++) {
			a[i][j] = s[j] - '0';
		}
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (a[i][j] == 0 && !visited[i][j]) {
				v.clear();
				int cnt = dfs(i, j);
				for (auto p : v) {
					check[p.first][p.second] = {cnt, idx};
				}
				idx++;
			}
		}
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (a[i][j] == 1) {
				countZero(i, j);
			}
			cout << a[i][j];
		}
		cout << '\n';
	}

}
