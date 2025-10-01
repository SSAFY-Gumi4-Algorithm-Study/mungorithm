#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

int n;
vector<int> v;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n;

    v.resize(n);

    for(int i = 0; i < n; i++){
        cin >> v[i];
    }

    sort(v.begin(), v.end());

    int ret = 0;

    for(int i = 0; i < n; i++){
        int target = v[i];
        int l = 0;
        int r = n - 1;
        if(l == i) l++;
        if(r == i) r--;
        while(l < r){
            if(v[l] + v[r] == target){
                ret++;
                break;
            }
            else if(v[l] + v[r] > target){
                r--;
                if(r == i) r--;
            }
            else{
                l++;
                if(l == i) l++;
            }
        }
    }

    cout << ret;
}