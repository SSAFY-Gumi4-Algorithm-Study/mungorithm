#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int n;
bool cmp(string a, string b){
    return a + b > b + a;
}

int main(){
    cin >> n;
    vector<string> v(n);
    for(int i = 0; i < n; i++){
        cin >> v[i];
    }

    sort(v.begin(), v.end(), cmp);

    for(string s : v){
        cout << s;
    }
}
