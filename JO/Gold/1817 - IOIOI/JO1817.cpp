#include<iostream>
using namespace std;

int n, m;
string s;
int dp[1000001];

int main(){
    cin >> n >> m;
    cin >> s;
    for(int i = 2; i < m; i++){
        if(s[i] == 'I' && s[i - 1] == 'O' && s[i - 2] == 'I'){
            dp[i] = dp[i - 2] + 1;
        }
    }

    int ret = 0;

    for(int i = 0; i <= m; i++){
        if(dp[i] >= n) ret++;
    }

    cout << ret;
}
