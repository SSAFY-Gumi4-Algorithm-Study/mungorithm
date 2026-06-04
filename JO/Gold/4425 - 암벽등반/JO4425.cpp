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

int n;
int a[501][501];
int visited[501][501];
int goal;
int dy[] = { 1, 0, -1, 0 };
int dx[] = { 0, 1, 0, -1 };

bool check(int mid, int sy, int sx) {
    queue<pair<int, int>> q;
    q.push({ sy, sx });
    visited[sy][sx] = 1;
    int cnt = 1;
    while (!q.empty()) {
        int y = q.front().first;
        int x = q.front().second;
        q.pop();

        for (int i = 0; i < 4; i++) {
            int ny = y + dy[i];
            int nx = x + dx[i];
            if (ny < 0 || nx < 0 || ny >= n || nx >= n) continue;
            if (visited[ny][nx]) continue;
            int diff = abs(a[y][x] - a[ny][nx]);
            if (diff > mid) continue;
            q.push({ ny, nx });
            cnt++;
            visited[ny][nx] = 1;
        }
    }
    if (cnt >= goal) return true;
    return false;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n;
    
    goal = (n * n * 3) / 4;

    int r = 0;
    int l = 1000001;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> a[i][j];
            r = max(r, a[i][j]);
            l = min(l, a[i][j]);
        }
    }

    int ret = 0;

    while (l <= r) {
        bool flag = false;
        int mid = (r + l) / 2;
        fill(&visited[0][0], &visited[0][0] + 501 * 501, 0);
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (!visited[i][j]) {
                    if (check(mid, i, j)) {
                        r = mid - 1;
                        ret = mid;
                        flag = true;
                        break;
                    }
                }
            }
            if (flag) break;
        }
        if (!flag) l = mid + 1;
    }

    cout << ret;
}
