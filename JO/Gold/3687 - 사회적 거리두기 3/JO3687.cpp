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
using ll = long long;

int n, m;
vector<pair<ll, ll>> v;

bool check(ll d) {
    ll cnt = 0;
    ll last = -(ll)4e18;

    for (auto p : v) {
        ll s = p.first;
        ll e = p.second;

        ll pos = max(s, last + d);
        if (pos > e) continue;

        ll add = (e - pos) / d + 1;
        cnt += add;

        last = pos + (add - 1) * d;

        if (cnt >= n) return true;
    }

    return false;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> m;
    v.resize(m);

    for (int i = 0; i < m; i++) {
        cin >> v[i].first >> v[i].second;
    }

    sort(v.begin(), v.end());

    ll l = 1;
    ll r = 1e18;
    ll ret = 0;

    while (l <= r) {
        ll mid = (l + r) / 2;

        if (check(mid)) {
            ret = mid;
            l = mid + 1;
        }
        else{
            r = mid - 1;
        }
    }

    cout << ret;
}
