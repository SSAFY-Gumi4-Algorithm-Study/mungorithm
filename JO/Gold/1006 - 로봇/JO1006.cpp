#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <set>
#include <map>
#include <unordered_set>
#include <cstring>
#include <stack>
using namespace std;

int n, m;
int dy[] = { 0, 0, 1, -1 };
int dx[] = { 1, -1, 0, 0 };
int d1_idx[] = { 2, 3, 1, 0 };
int d2_idx[] = { 3, 2, 0, 1 };
int a[101][101];
int visited[101][101][4];
int sy, sx, sd, ey, ex, ed;

struct State {
    int y, x, d;
};


int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            cin >> a[i][j];
        }
    }

    memset(visited, -1, sizeof(visited));

    cin >> sy >> sx >> sd;
    cin >> ey >> ex >> ed;
    sd--;
    ed--;

    queue<State> q;

    q.push({ sy, sx, sd });
    visited[sy][sx][sd] = 0;

    while (!q.empty()) {
        State cur = q.front();
        q.pop();
        int y = cur.y;
        int x = cur.x;
        int d = cur.d;

        if (y == ey && x == ex && d == ed) {
            break;
        }

        for (int i = 1; i <= 3; i++) {
            int ny = y + dy[d] * i;
            int nx = x + dx[d] * i;
            if (ny < 1 || nx < 1 || ny > n || nx > m) break;
            if (a[ny][nx] == 1) break;
            if (visited[ny][nx][d] != -1) continue;
            q.push({ ny, nx, d });
            visited[ny][nx][d] = visited[y][x][d] + 1;
        }

        int d1 = d1_idx[d];
        int d2 = d2_idx[d];
        if (visited[y][x][d1] == -1) {
            q.push({ y, x, d1 });
            visited[y][x][d1] = visited[y][x][d] + 1;
        }
        if (visited[y][x][d2] == -1) {
            q.push({ y, x, d2 });
            visited[y][x][d2] = visited[y][x][d] + 1;
        }
    }
    cout << visited[ey][ex][ed];
}
