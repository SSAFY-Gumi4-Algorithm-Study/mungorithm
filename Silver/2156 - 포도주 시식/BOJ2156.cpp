#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

int a[10001], dp[10001];
int n;

int main(){
    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> a[i];
    }
    dp[0] = a[0];
    dp[1] = dp[0] + a[1];
    dp[2] = max(a[0] + a[2], a[1] + a[2]);
    for(int i = 2; i < n; i++){
        dp[i] = max(max(dp[i - 2] + a[i], dp[i - 3] + a[i - 1] + a[i]), dp[i - 1]);
    }
    cout << dp[n - 1];
}
