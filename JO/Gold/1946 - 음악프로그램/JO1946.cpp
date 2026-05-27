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
int ind[1001];
vector<int> graph[1001];
vector<int> ret;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        int k;
        cin >> k;
        int prev = -1;
        for (int j = 0; j < k; j++) {
            int x;
            cin >> x;
            if (j == 0) {
                prev = x;
                continue;
            }
            graph[prev].push_back(x);
            ind[x]++;
            prev = x;
        }
    }

    queue<int> q;
    int cnt = n;

    for (int i = 1; i <= n; i++) {
        if (ind[i] == 0) {
            q.push(i);
            cnt--;
        }
    }

    while (!q.empty()) {
        int cur = q.front();
        q.pop();
        ret.push_back(cur);
        for (int next : graph[cur]) {
            ind[next]--;
            if (ind[next] == 0) {
                q.push(next);
                cnt--;
            }
        }
    }

    if (cnt) {
        cout << 0;
        return 0;
    }
    for (int x : ret) {
        cout << x << '\n';
    }
}
