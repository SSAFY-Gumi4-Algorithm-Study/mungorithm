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
int len;
vector<int> tree;

int get(int idx, int s, int e, int ts, int te) {
    if (e < ts || s > te) return 1000000010;
    else if (s >= ts && e <= te) return tree[idx];
    int mid = (s + e) / 2;
    int l = get(idx * 2, s, mid, ts ,te);
    int r = get(idx * 2 + 1, mid + 1, e, ts, te);
    return min(l, r);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cin >> n >> m;
    len = 1;
    while (len < n) len <<= 1;
    tree.assign(len * 2, 1000000010);
    for (int i = 0; i < n; i++) {
        cin >> tree[len + i];
    }
    for (int i = len - 1; i > 0; i--) {
        tree[i] = min(tree[i * 2], tree[i * 2 + 1]);
    }
    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        cout << get(1, 0, len - 1, a - 1, b - 1) << '\n';
    }
}
