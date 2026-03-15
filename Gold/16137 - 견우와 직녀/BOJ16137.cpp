#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <set>
#include <unordered_set>
#include <cstring>
using namespace std;

int n, t;
int a[11][11];
int dy[] = { -1, 0, 1, 0 };
int dx[] = { 0, 1, 0, -1 };

struct State {
    int y, x, t, flag;
};

int bfs() {
    int dist[11][11][2];

    for (int i = 0; i < 11; i++)
        for (int j = 0; j < 11; j++)
            for (int k = 0; k < 2; k++)
                dist[i][j][k] = 1e9;

    queue<State> q;
    q.push({ 0,0,0,0 });
    dist[0][0][0] = 0;

    while (!q.empty()) {

        State s = q.front();
        q.pop();

        int y = s.y;
        int x = s.x;
        int curT = s.t;
        int flag = s.flag;

        if (dist[y][x][flag] < curT) continue;

        if (y == n - 1 && x == n - 1)
            return curT;

        for (int i = 0; i < 4; i++) {

            int ny = y + dy[i];
            int nx = x + dx[i];

            if (ny < 0 || nx < 0 || ny >= n || nx >= n) continue;
            if (a[ny][nx] == 0) continue;

            if (a[ny][nx] == 1) {

                int nt = curT + 1;

                if (dist[ny][nx][0] <= nt) continue;

                dist[ny][nx][0] = nt;
                q.push({ ny, nx, nt, 0 });
            }

            else {

                if (flag == 1) continue;

                int nt = curT + 1;

                if (nt % a[ny][nx] != 0)
                    nt += a[ny][nx] - (nt % a[ny][nx]);

                if (dist[ny][nx][1] <= nt) continue;

                dist[ny][nx][1] = nt;
                q.push({ ny, nx, nt, 1 });
            }
        }
    }

    return 987654321;
}

bool possible(int y, int x) {

    if (a[y][x] != 0) return false;

    bool vertical = false;
    bool horizontal = false;

    if (y > 0 && a[y - 1][x] == 0) vertical = true;
    if (y < n - 1 && a[y + 1][x] == 0) vertical = true;

    if (x > 0 && a[y][x - 1] == 0) horizontal = true;
    if (x < n - 1 && a[y][x + 1] == 0) horizontal = true;

    if (vertical && horizontal) return false;

    return true;
}

int main() {

    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin >> n >> t;

    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            cin >> a[i][j];

    int ret = 987654321;

    ret = min(ret, bfs());

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {

            if (possible(i, j)) {

                a[i][j] = t;

                ret = min(ret, bfs());

                a[i][j] = 0;
            }
        }
    }

    cout << ret;
}
