#include<iostream> 
#include<algorithm> 
#include<vector> 
#include<tuple>
using namespace std;

int n, m, t;
int a[51][51], tmp[51][51];
int visited[6];
int dy[] = { 1, 0, -1, 0 };
int dx[] = { 0, 1, 0, -1 };
vector<tuple<int, int, int>> v;
vector<int> sel;
int ret = 987654321;

int arrSum() {
	int mn = 987654321;
	int sum = 0;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			sum += tmp[i][j];
		}
		mn = min(sum, mn);
		sum = 0;
	}
	return mn;
}

void rotate(int r, int c, int s) {
	for (int i = 1; i <= s; i++) {
		int y = r - i;
		int x = c - i;
		int temp = tmp[y][x];
		for (int dir = 0; dir < 4; dir++) {
			while (true) {
				int ny = y + dy[dir];
				int nx = x + dx[dir];
				if (ny < r - i || nx < c - i || ny > r + i || nx > c + i) break;
				tmp[y][x] = tmp[ny][nx];
				y = ny;
				x = nx;
			}
		}
		tmp[r - i][c - i + 1] = temp;
	}
}

void solve(int cnt) {
	if (cnt == t) {
		int sum = 0;
		copy(&a[0][0], &a[0][0] + 51 * 51, &tmp[0][0]);
		for (int i = 0; i < sel.size(); i++) {
			int r = get<0>(v[sel[i]]);
			int c = get<1>(v[sel[i]]);
			int s = get<2>(v[sel[i]]);
			rotate(r, c, s);
		}
		sum = arrSum();
		ret = min(ret, sum);
		return;
	}
	for (int i = 0; i < v.size(); i++) {
		if (visited[i]) continue;
		sel.push_back(i);
		visited[i] = 1;
		solve(cnt + 1);
		sel.pop_back();
		visited[i] = 0;
	}
}

int main() {
	cin >> n >> m >> t;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			cin >> a[i][j];
		}
	}

	for (int i = 0; i < t; i++) {
		int r, c, s;
		cin >> r >> c >> s;
		v.push_back({ r, c, s });
	}

	solve(0);
	cout << ret;
}
