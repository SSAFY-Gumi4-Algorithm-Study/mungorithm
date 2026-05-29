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

int n, m, k;
int visited[1001][1001];
int dy[] = { -1, 0, 1, 0 };
int dx[] = { 0, 1, 0, -1 };

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> m >> k;

    fill(&visited[0][0], &visited[0][0] + 1001 * 1001, 987654321);
    queue<pair<int, int>> q;

    for (int i = 0; i < k; i++) {
        int y, x;
        cin >> y >> x;
        visited[y][x] = 0;
        q.push({ y, x });
    }

    while (!q.empty()) {
        int y = q.front().first;
        int x = q.front().second;
        q.pop();

        for (int i = 0; i < 4; i++) {
            int ny = y + dy[i];
            int nx = x + dx[i];
            if (ny < 1 || nx < 1 || ny > n || nx > m) continue;
            if (visited[ny][nx] != 987654321) continue;
            visited[ny][nx] = visited[y][x] + 1;
            q.push({ ny, nx });
        }
    }

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            cout << visited[i][j] << ' ';
        }
        cout << '\n';
    }
}
