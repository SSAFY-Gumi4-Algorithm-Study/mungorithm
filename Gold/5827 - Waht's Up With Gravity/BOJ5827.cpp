#include <iostream>
#include <algorithm>
#include <deque>
using namespace std;

int n, m;
char a[501][501];
pair<int, int> c, d;
int dy[] = { 1, -1, 0, 0 };
int dx[] = { 0, 0, 1, -1 };
int visited[501][501][2];

pair<int, int> gravity(int y, int x, int g) {
    int ny = y;
    int nx = x;
    while (true) {
        ny += dy[g];
        nx += dx[g];
        if (ny < 0 || nx < 0 || ny >= n || nx >= m) {
            return { -1, -1 };
        }
        if (a[ny][nx] == 'D') {
            return { ny, nx };
        }
        if (a[ny][nx] == '#') {
            return { ny - dy[g], nx - dx[g] };
        }
    }
}

int main() {
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        string s;
        cin >> s;
        for (int j = 0; j < m; j++) {
            a[i][j] = s[j];
            if (a[i][j] == 'C') {
                c = { i, j };
                a[i][j] = '.';
            }
            else if (a[i][j] == 'D') {
                d = { i, j };
            }
        }
    }
    fill(&visited[0][0][0], &visited[0][0][0] + 501 * 501 * 2, 987654321);
    pair<int, int> start = gravity(c.first, c.second, 0);

    if (start.first == -1 && start.second == -1) {
        cout << -1;
        return 0;
    }
    if (start.first == d.first && start.second == d.second) {
        cout << 0;
        return 0;
    }
    c = start;
    deque<pair<pair<int, int>, int>> dq;
    dq.push_front({ c, 0 });
    visited[c.first][c.second][0] = 0;
    while (!dq.empty()) {
        int y = dq.front().first.first;
        int x = dq.front().first.second;
        int g = dq.front().second;
        dq.pop_front();
        if (y == d.first && x == d.second) {
            cout << visited[d.first][d.second][g];
            return 0;
        }
        
        int ng = g == 0 ? 1 : 0;
        pair<int, int> next = gravity(y, x, ng);

        if (!(next.first == -1 && next.second == -1)) {
            if (visited[next.first][next.second][ng] > visited[y][x][g] + 1) {
                visited[next.first][next.second][ng] = visited[y][x][g] + 1;
                dq.push_back({ next, ng });

            }
        }
        for (int i = 2; i <= 3; i++) {
            int ny = y + dy[i];
            int nx = x + dx[i];
            if (ny < 0 || nx < 0 || ny >= n || nx >= m) continue;
            if (a[ny][nx] == '#') continue;
            if (ny == d.first && nx == d.second) {
                next = { ny, nx };
            }
            else {
                next = gravity(ny, nx, g);
            }
            if (!(next.first == -1 && next.second == -1)) {
                if (visited[next.first][next.second][g] > visited[y][x][g]) {
                    visited[next.first][next.second][g] = visited[y][x][g];
                    dq.push_front({ next, g });
                }
            }
        }
    }
    cout << -1;
}
