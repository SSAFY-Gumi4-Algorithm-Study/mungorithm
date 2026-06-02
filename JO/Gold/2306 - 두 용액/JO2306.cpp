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
vector<int> v;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n;
    v.resize(n);

    for (int i = 0; i < n; i++) {
        cin >> v[i];
    }

    sort(v.begin(), v.end());

    int l = 0;
    int r = n - 1;

    int ret = 2000000001;
    pair<int, int> idx;
    while (l < r) {
        int sum = v[l] + v[r];
        if (ret > abs(sum)) {
            ret = abs(sum);
            idx = { l, r };
        }
        if (sum <= 0) l++;
        else r--;
    }

    cout << v[idx.first] << ' ' << v[idx.second];
}
