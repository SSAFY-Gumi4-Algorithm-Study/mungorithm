#include<iostream>
#include<vector>
#include<algorithm>
#include<tuple>
#include<string>
#include<unordered_set>
#include<stack>
#include<cmath>
#include<queue>
using namespace std;

int T;
int n, m;
vector<vector<char>> a;
vector<vector<int>> visited;
pair<int ,int> start;
vector<pair<int,int>> fire;
int dy[] = {-1, 0, 1, 0};
int dx[] = {0, 1, 0, -1};


void init() {
    a.assign(n, vector<char>(m));
    fire.clear();
    visited.assign(n, vector<int>(m, 987654321));
}

void moveFire() {
    queue<pair<int,int>> q;
    for (auto p : fire) {
        q.push(p);
        visited[p.first][p.second] = 0;
    }
    while (!q.empty()) {
        int y = q.front().first;
        int x = q.front().second;
        q.pop();
        for (int i = 0; i < 4; i++) {
            int ny = y + dy[i];
            int nx = x + dx[i];
            if (ny < 0 || nx < 0 || ny >= n || nx >= m) continue;
            if (a[ny][nx] == '#' || visited[ny][nx] != 987654321) continue;
            visited[ny][nx] = visited[y][x] + 1;
            q.push({ny, nx});
        }
    }
}

int escape() {
    queue<pair<int,int>> q;
    vector<vector<int>> time(n, vector<int>(m, -1));
    q.push(start);
    time[start.first][start.second] = 0;
    while (!q.empty()) {
        int y = q.front().first;
        int x = q.front().second;
        q.pop();
        for (int i = 0; i < 4; i++) {
            int ny = y + dy[i];
            int nx = x + dx[i];
            if (ny < 0 || nx < 0 || ny >= n || nx >= m) {
                return time[y][x] + 1;
            }
            if (a[ny][nx] == '#' || time[ny][nx] != -1 || time[y][x] + 1 >= visited[ny][nx]) continue;
            time[ny][nx] = time[y][x] + 1;
            q.push({ny, nx});
        }
    }
    return -1;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> T;
    for (int t = 1; t <= T; t++) {
        cin >> m >> n;
        init();
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> a[i][j];
                if (a[i][j] == '@') start = {i, j};
                else if (a[i][j] == '*') fire.push_back({i, j});
            }
        }
        moveFire();
        int ret = escape();
        if (ret == -1) cout << "IMPOSSIBLE\n";
        else cout << ret << '\n';
    }
}
