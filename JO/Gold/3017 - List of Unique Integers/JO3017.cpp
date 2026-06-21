#include<iostream>
#include<unordered_set>
using namespace std;

int n;
int a[100001];

int main(){
    cin >> n;
    
    for(int i = 0; i < n; i++){
        cin >> a[i];
    }

    int l = 0;
    int r = 0;
    unordered_set<int> st;
    int len = 0;
    long long ret = 0;
    while(l <= r && r < n){
        if(st.count(a[r])){
            while(st.count(a[r])){
                ret += len--;
                st.erase(a[l]);
                l++;
            }
        }
        st.insert(a[r]);
        len++;
        r++;
    }

    while(len != 0){
        ret += len--;
    }

    cout << ret;
}
