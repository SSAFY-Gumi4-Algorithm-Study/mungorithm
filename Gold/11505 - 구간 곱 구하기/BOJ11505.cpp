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

int n, m, k;
vector<long long> tree;
int len;
long long mod = 1000000007;

void update(int idx, int val) {
    idx += len;
    tree[idx] = val;
    idx /= 2;
    while (idx >= 1) {
        tree[idx] = (tree[idx * 2] * tree[idx * 2 + 1]) % mod;
        idx /= 2;
    }
}

long long get(int idx, int s, int e, int ts, int te) {
    if (s > te || e < ts) return 1;
    else if (ts <= s && e <= te) return tree[idx];
    int mid = (s + e) / 2;
    long long l = get(2 * idx, s, mid, ts, te);
    long long r = get(2 * idx + 1, mid + 1, e, ts, te);
    return (l * r) % mod;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cin >> n >> m >> k;
    len = 1;
    while (n > len) len <<= 1;
    tree.assign(2 * len, 1);
    for (int i = 0; i < n; i++) {
        cin >> tree[len + i];
    }
    for (int i = len - 1; i > 0; i--) {
        tree[i] = (tree[i * 2] * tree[i * 2 + 1]) % mod;
    }
    for (int i = 0; i < m + k; i++) {
        int cmd;
        long long b, c;
        cin >> cmd >> b >> c;
        if (cmd == 1) update(b - 1, c);
        else cout << get(1, 0, len - 1, b - 1, c - 1) << '\n';
    }
}
