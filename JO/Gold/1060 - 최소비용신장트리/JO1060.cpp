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
int parent[101];

struct Edge {
    int from, to, cost;

    bool operator < (const Edge& other) const {
        return this->cost < other.cost;
    }
};

vector<Edge> v;

int find(int x) {
    if (x == parent[x]) return x;
    return parent[x] = find(parent[x]);
}

bool merge(int x, int y) {
    x = find(x);
    y = find(y);
    if (x == y) return false;
    parent[y] = x;
    return true;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n;
    for (int i = 1; i <= n; i++) {
        parent[i] = i;
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            int x;
            cin >> x;
            if (x != 0) {
                v.push_back({ i, j, x });
            }
        }
    }

    sort(v.begin(), v.end());

    int cnt = 0;
    int ret = 0;

    for (Edge& e : v) {
        if (merge(e.from, e.to)) {
            cnt++;
            ret += e.cost;
        }
        if (cnt == n - 1) break;
    }

    cout << ret;
}
