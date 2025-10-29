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

int n;
int a[100001];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    sort(a, a + n);

    int l = 0;
    int r = n - 1;

    int mn = 2000000001;
    pair<int,int> ret = {0, 0};
    while (l < r) {
        if (a[l] + a[r] == 0) {
            ret = {a[l], a[r]};
            break;
        }
        else if (a[l] + a[r] > 0) {
            int sum = abs(a[l] + a[r]);
            if (mn > sum) {
                mn = sum;
                ret = {a[l], a[r]};
            }
            r--;
        }
        else if (a[l] + a[r] < 0) {
            int sum = abs(a[l] + a[r]);
            if (mn > sum) {
                mn = sum;
                ret = {a[l], a[r]};
            }
            l++;
        }
    }
    cout << ret.first << ' ' << ret.second;
}
