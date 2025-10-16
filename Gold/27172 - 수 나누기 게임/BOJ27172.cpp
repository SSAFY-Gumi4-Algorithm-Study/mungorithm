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
vector<int> v, ret;
bool check[1000001];
int idx[1000001];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cin >> n;
    v.resize(n);
    ret.resize(n);
    int mx = 0;
    for (int i = 0; i < n; i++) {
        cin >> v[i];
        check[v[i]] = true;
        idx[v[i]] = i;
        mx = max(v[i], mx);
    }
    sort(v.begin(), v.end());
    for (int i = 0; i < n; i++) {
        for (int j = 2 * v[i]; j <= mx; j += v[i]) {
            if (check[j]) {
                ret[idx[v[i]]]++;
                ret[idx[j]]--;
            }
        }
    }
    for (int i = 0; i < n; i++) {
        cout << ret[i] << ' ';
    }
}
