#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int n;
vector<int> v[4];
int idx[4];

int main(){
    cin >> n;
    for(int i = 0; i < 4; i++){
        v[i].resize(n);
    }

    for(int i = 0; i < 4; i++){
        for(int j = 0; j < n; j++){
            cin >> v[i][j];
        }
    }

    for(int i = 0; i < 4; i++){
        sort(v[i].begin(), v[i].end());
    }

    int ret = 1987654321;

    while(true){
        int mx = -1;
        int mn = 1987654321;
        int mn_idx;

        for(int i = 0; i < 4; i++){
            mx = max(mx, v[i][idx[i]]);
            if(mn > v[i][idx[i]]){
                mn = v[i][idx[i]];
                mn_idx = i;
            }
        }
        ret = min(ret, mx - mn);
        idx[mn_idx]++;
        if(idx[mn_idx] == n) break;
    }

    cout << ret;
}
