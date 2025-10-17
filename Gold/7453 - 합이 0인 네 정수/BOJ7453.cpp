#include<iostream>
#include<algorithm>
#include<vector>
#include<string>
#include<queue>
#include<unordered_set>
#include<map>
#include<cmath>
using namespace std;

int n;
int a[4001];
int b[4001];
int c[4001];
int d[4001];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> a[i] >> b[i] >> c[i] >> d[i];
    }
    vector<int> ab, cd;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            ab.push_back(a[i] + b[j]);
        }
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cd.push_back(c[i] + d[j]);
        }
    }
    sort(cd.begin(), cd.end());
    long long cnt = 0;
    for (int i = 0; i < ab.size(); i++) {
        int target = -ab[i];
        auto low = lower_bound(cd.begin(), cd.end(), target);
        if (low != cd.end() && *low == target) {
            auto high = upper_bound(cd.begin(), cd.end(), target);
            cnt += high - low;
        }
    }
    cout << cnt;
}
