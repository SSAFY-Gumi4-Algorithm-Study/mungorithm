#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

int n, m;
vector<int> v, tmp;
int visited[8];


void solve(int cnt) {
    if (cnt == m) {
        for (int i = 0; i < tmp.size(); i++) {
            cout << tmp[i] << " ";
        }
        cout << '\n';
        return;
    }
    int prev = -1;
    for (int i = 0; i < n; i++) {
        if (prev == v[i]) continue;
        tmp.push_back(v[i]);
        prev = v[i];
        solve(cnt + 1);
        tmp.pop_back();
    }
}

int main() {
    cin >> n >> m;
    v.resize(n);

    for (int i = 0; i < n; i++) {
        cin >> v[i];
    }

    sort(v.begin(), v.end());

    solve(0);
}