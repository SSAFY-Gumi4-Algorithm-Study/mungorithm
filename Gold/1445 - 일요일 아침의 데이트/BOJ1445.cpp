#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
#include<tuple>

using namespace std;

int n, m;
char a[51][51];
pair<int, int> s, e;
pair<int, int> dist[51][51];
int dy[] = { -1, 0, 1, 0 };
int dx[] = { 0, 1, 0, -1 };

struct Info {
	int trash, pass, y, x;
	Info(int trash, int pass, int y, int x) {
		this->trash = trash;
		this->pass = pass;
		this->y = y;
		this->x = x;
	}
};

struct cmp {
	bool operator()(Info a, Info b) {
		if (a.trash == b.trash) {
			return a.pass > b.pass;
		}
		return a.trash > b.trash;
	}
};

int check(int y, int x) {
	int cnt = 0;
	for (int i = 0; i < 4; i++) {
		int ny = y + dy[i];
		int nx = x + dx[i];
		if (ny < 0 || nx < 0 || ny >= n || nx >= m) continue;
		if (a[ny][nx] == 'g') return 1;
	}
	return 0;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> a[i][j];
			if (a[i][j] == 'S') s = { i, j };
			else if (a[i][j] == 'F') e = { i, j };
			dist[i][j] = { 300, 300 };
		}
	}

	priority_queue<Info, vector<Info>, cmp> pq;
	dist[s.first][s.second] = { 0, 0 };
	pq.push(Info(0, 0, s.first, s.second));
	while (!pq.empty()) {
		Info info = pq.top();
		pq.pop();
		pair<int, int> p = { info.trash, info.pass };
		int y = info.y;
		int x = info.x;
		if (a[y][x] == 'F') {
			cout << dist[y][x].first << ' ' << dist[y][x].second;
			break;
		}
		if (dist[y][x] < p) continue;
		for (int i = 0; i < 4; i++) {
			int ny = y + dy[i];
			int nx = x + dx[i];
			if (ny < 0 || nx < 0 || ny >= n || nx >= m) continue;
			int ntrash = p.first;
			int npass = p.second;
			if (a[ny][nx] != 'F') {
				if (a[ny][nx] == 'g') ntrash++;
				else if (check(ny, nx)) npass++;
			}
			pair<int, int> np = { ntrash, npass };
			if (dist[ny][nx] > np) {
				dist[ny][nx] = np;
				pq.push({ ntrash, npass, ny, nx });
			}
		}
	}
}
