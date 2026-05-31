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
int a[51][51];
int dist[51];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            if (i == j) a[i][j] = 0;
            else a[i][j] = 987654321;
        }
    }

    while (true) {
        int x, y;
        cin >> x >> y;
        if (x == -1 && y == -1) break;
        a[x][y] = 1;
        a[y][x] = 1;
    }

    for (int k = 1; k <= n; k++) {
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                a[i][j] = min(a[i][j], a[i][k] + a[k][j]);
            }
        }
    }

    int ret = 987654321;

    for (int i = 1; i <= n; i++) {
        int mx = 0;
        for (int j = 1; j <= n; j++) {
            if (a[i][j] == 987654321) continue;
            mx = max(mx, a[i][j]);
        }
        ret = min(ret, mx);
        dist[i] = mx;
    }

    int cnt = 0;
    vector<int> ans;
    for (int i = 1; i <= n; i++) {
        if (dist[i] == ret) {
            cnt++;
            ans.push_back(i);
        }
    }
    
    cout << ret << ' ' << cnt << '\n';
    for (int x : ans) {
        cout << x << ' ';
    }
}
