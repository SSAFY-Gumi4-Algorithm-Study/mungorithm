#include<iostream>
#include<set>
using namespace std;

int n, k;
int a[200001];

int main(){
    cin >> n >> k;
    
    for(int i = 0; i < n; i++){
        cin >> a[i];
    }

    multiset<int> ms;

    int l = 0;
    int ret = 0;

    for(int r = 0; r < n; r++){
        ms.insert(a[r]);

        while(*ms.rbegin() - *ms.begin() > k){
            ms.erase(ms.find(a[l]));
            l++;
        }

        ret = max(ret, r - l + 1);
    }

    cout << ret;
}
