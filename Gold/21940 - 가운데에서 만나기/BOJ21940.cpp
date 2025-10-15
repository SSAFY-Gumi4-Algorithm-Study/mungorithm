#include<iostream>
#include<algorithm>
#include<vector>
#include<string>
#include<queue>
#include<unordered_set>
#include<map>
#include<cmath>
using namespace std;

int n, m, k;
int dist[201][201];
vector<int> friends;

int main() {
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            if (i == j) dist[i][j] = 0;
            else dist[i][j] = 987654321;
        }
    }

    for (int i = 0; i < m; i++) {
        int a, b, t;
        cin >> a >> b >> t;
        dist[a][b] = t;
    }

    for (int l = 1; l <= n; l++) {
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                dist[i][j] = min(dist[i][l] + dist[l][j], dist[i][j]);
            }
        }
    }
    cin >> k;
    for (int i = 1; i <= k; i++) {
        int f;
        cin >> f;
        friends.push_back(f);
    }

    vector<int> ret;
    int mn = 987654321;
    for (int i = 1; i <= n; i++){
        int mx = 0;
        bool flag = false;
        for (int x : friends) {
            if (dist[x][i] == 987654321 || dist[i][x] == 987654321) {
                break;
                flag = true;
            }
            mx = max(mx, dist[x][i] + dist[i][x]);
        }

        if (flag) continue;

        if (mn > mx) {
            mn = mx;
            ret.clear();
            ret.push_back(i);
        }
        else if (mn == mx) {
            ret.push_back(i);
        }
    }
    for (int x : ret) {
        cout << x << ' ';
    }
}
