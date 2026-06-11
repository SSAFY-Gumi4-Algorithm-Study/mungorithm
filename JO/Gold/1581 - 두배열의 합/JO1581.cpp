#include<iostream>
#include<algorithm>
#include<vector>
#include<unordered_map>
using namespace std;

int t, n, m;
int a[1001], b[1001];
int psum_a[1001], psum_b[1001];
unordered_map<int, int> mp;

int main(){
    cin >> t;
    cin >> n;
    for(int i = 1; i <= n; i++){
        cin >> a[i];
        psum_a[i] = psum_a[i - 1] + a[i];
    }
    cin >> m;
    for(int i = 1; i <= m; i++){
        cin >> b[i];
        psum_b[i] = psum_b[i - 1] + b[i];
    }

    for(int i = 0; i < n; i++){
        for(int j = i + 1; j <= n; j++){
            mp[psum_a[j] - psum_a[i]]++;
        }
    }

    int ret = 0;

    for(int i = 0; i < m; i++){
        for(int j = i + 1; j <= m; j++){
            int x = psum_b[j] - psum_b[i];
            ret += mp[t - x];
        }
    }

    cout << ret;
}
