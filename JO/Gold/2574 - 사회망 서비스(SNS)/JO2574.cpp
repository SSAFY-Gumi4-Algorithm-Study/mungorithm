#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <set>
#include <map>
#include <unordered_set>
#include <cstring>
#include <stack>
using namespace std;

int n;
vector<int> graph[1000001];
int dp[1000001][2];

void dfs(int cur, int parent) {
    dp[cur][0] = 0;
    dp[cur][1] = 1;

    for (int next : graph[cur]) {
        if (next == parent) continue;
        dfs(next, cur);
        dp[cur][0] += dp[next][1];
        dp[cur][1] += min(dp[next][0], dp[next][1]);
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n;
    for (int i = 0; i < n - 1; i++) {
        int a, b;
        cin >> a >> b;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }

    dfs(1, -1);
    cout << min(dp[1][0], dp[1][1]);
}
