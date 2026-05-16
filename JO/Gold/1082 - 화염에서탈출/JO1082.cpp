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
char a[51][51];
int danger[51][51], visited[51][51];
int sy, sx, ey, ex;
vector<pair<int, int>> fire;
int dy[] = { -1, 0, 1, 0 };
int dx[] = { 0, 1, 0, -1 };

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    fill(&danger[0][0], &danger[0][0] + 51 * 51, 987654321);
    fill(&visited[0][0], &visited[0][0] + 51 * 51, 987654321);

    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> a[i][j];
            
            if (a[i][j] == 'D') {
                ey = i;
                ex = j;
            }

            else if (a[i][j] == 'S') {
                sy = i;
                sx = j;
            }

            else if (a[i][j] == '*') {
                fire.push_back({ i, j });
            }
        }
    }

    queue<pair<int, int>> q;
    for (auto p : fire) {
        q.push(p);
        danger[p.first][p.second] = 0;
    }

    while (!q.empty()) {
        int y = q.front().first;
        int x = q.front().second;
        q.pop();

        for (int i = 0; i < 4; i++) {
            int ny = y + dy[i];
            int nx = x + dx[i];
            if (ny < 0 || nx < 0 || ny >= n || nx >= m) continue;
            if (danger[ny][nx] != 987654321)continue;
            if (a[ny][nx] == 'X' || a[ny][nx] == 'D') continue;
            danger[ny][nx] = danger[y][x] + 1;
            q.push({ ny, nx });
        }
    }

    q.push({ sy, sx });
    visited[sy][sx] = 0;

    while (!q.empty()) {
        int y = q.front().first;
        int x = q.front().second;
        q.pop();
        if (y == ey && x == ex) {
            cout << visited[y][x];
            return 0;
        }
        for (int i = 0; i < 4; i++) {
            int ny = y + dy[i];
            int nx = x + dx[i];
            if (ny < 0 || nx < 0 || ny >= n || nx >= m) continue;
            if (visited[ny][nx] != 987654321) continue;
            if (a[ny][nx] == 'X') continue;
            if (danger[ny][nx] <= visited[y][x] + 1) continue;
            visited[ny][nx] = visited[y][x] + 1;
            q.push({ ny, nx });
        }
    }

    cout << "impossible";
}
