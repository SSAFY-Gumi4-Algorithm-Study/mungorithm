#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

int n, m;
vector<int> v;
int ret = 0;

int blueRay(int cap) {
    int cnt = 1, sum = 0;
    for (int len : v) {
        if (sum + len > cap) {
            cnt++;
            sum = len;
        }
        else {
            sum += len;
        }
    }
    return cnt;
}

int main() {
    cin >> n >> m;
    v.resize(n);
    int r = 0;
    for (int i = 0; i < n; i++) {
        cin >> v[i];
        r += v[i];
    }
    int l = *max_element(v.begin(), v.end());

    while (l <= r) {
        int mid = (l + r) / 2;
        if (blueRay(mid) <= m) {
            ret = mid;
            r = mid - 1;
        }
        else {
            l = mid + 1;
        }
    }
    cout << ret;
}