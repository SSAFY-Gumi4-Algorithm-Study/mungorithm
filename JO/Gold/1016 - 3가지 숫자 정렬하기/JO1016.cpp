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
int cnt[4][4];


int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n;
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        v.push_back(x);
    }

    vector<int> sorted;
    sorted = v;
    sort(sorted.begin(), sorted.end());

    for (int i = 0; i < n; i++) {
        if (v[i] == sorted[i]) continue;
        cnt[v[i]][sorted[i]]++;
    }

    int ret = 0;
    int t1 = min(cnt[1][2], cnt[2][1]);
    int t2 = min(cnt[1][3], cnt[3][1]);
    int t3 = min(cnt[2][3], cnt[3][2]);
    ret += t1 + t2 + t3;

    cnt[1][2] -= t1;
    cnt[2][1] -= t1;
    cnt[1][3] -= t2;
    cnt[3][1] -= t2;
    cnt[2][3] -= t3;
    cnt[3][2] -= t3;


    int t4 = min(cnt[1][2], min(cnt[2][3], cnt[3][1]));
    int t5 = min(cnt[1][3], min(cnt[3][2], cnt[2][1]));

    ret += t4 * 2 + t5 * 2;

    cnt[1][2] -= t4;
    cnt[2][3] -= t4;
    cnt[3][1] -= t4;
    cnt[1][3] -= t5;
    cnt[3][2] -= t5;
    cnt[2][1] -= t5;

    for (int i = 1; i <= 3; i++) {
        for (int j = 1; j <= 3; j++) {
            ret += cnt[i][j];
        }
    }

    cout << ret;
}
