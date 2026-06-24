#include<iostream>
using namespace std;
using ll = long long;

int n, m;
int a[100001];
ll psum[100001];

int main(){
    cin >> n >> m;

    ll l = 0;
    ll r = 0;

    for(int i = 1; i <= n; i++){
        cin >> a[i];
        l = max(l, (ll)a[i]);
        r += a[i];
    }
    
    long long ret = r;

    while(l <= r){
        ll mid = (l + r) / 2;
        int cnt = 0;
        ll sum = 0;

        for(int i = 1; i <= n; i++){
            if(sum + a[i] > mid){
                cnt++;
                sum = a[i];
                continue;
            }
            sum += a[i];
        }
        cnt++;

        if(cnt <= m){
            r = mid - 1;
            ret = mid;
        }
        else{
            l = mid + 1;
        }
    }

    cout << ret;
}
