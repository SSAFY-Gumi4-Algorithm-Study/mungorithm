#include<iostream>
#include<vector>
#include<algorithm>
#include<tuple>
#include<string>
#include<unordered_set>
#include<stack>
#include<cmath>
#include<queue>
using namespace std;

int n, m;
int len = 1;
vector<int> tree;

void update(int idx, int val) {
    idx += len;
    tree[idx] = val;
    idx /= 2;
    while (idx > 0) {
        tree[idx] = min(tree[idx * 2], tree[idx * 2 + 1]);
        idx /= 2;
    }
}

int get(int idx, int s, int e, int ts, int te) {
    if (s > te || e < ts) return 1000000002;
    else if (s >= ts && e <= te) return tree[idx];
    int mid = (s + e) / 2;
    int l = get(idx * 2, s, mid, ts, te);
    int r = get(idx * 2 + 1, mid + 1, e, ts, te);
    return min(l, r);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n;
    while (len < n) len <<= 1;
    tree.resize(len * 2);
    for (int i = 0; i < n; i++) {
        cin >> tree[len + i];
    }
    for (int i = len - 1; i > 0; i--) {
        tree[i] = min(tree[i * 2], tree[i * 2 + 1]);
    }
    cin >> m;
    for (int i = 0; i < m; i++) {
        int cmd, a, b;
        cin >> cmd >> a >> b;
        if (cmd == 1) {
            update(a - 1, b);
        }
        else {
            cout << get(1, 0, len - 1, a - 1, b - 1) << '\n';
        }
    }
}
