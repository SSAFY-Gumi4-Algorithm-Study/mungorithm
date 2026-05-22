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

int n, m;
vector<pair<int,int>> graph[20001];
int dist[20001];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> m;

    for (int i = 0; i < m; i++) {
        int from, to, cost;
        cin >> from >> to >> cost;
        graph[from].push_back({ to, cost });
    }

    fill(dist, dist + 20001, 987654321);
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;
    dist[1] = 0;
    pq.push({ 0, 1 });

    while (!pq.empty()) {
        int cost = pq.top().first;
        int cur = pq.top().second;
        pq.pop();

        if (cost > dist[cur]) continue;

        for (auto p : graph[cur]) {
            int next = p.first;
            int nc = cost + p.second;
            if (dist[next] > nc) {
                dist[next] = nc;
                pq.push({ nc, next });
            }
        }
    }

    cout << dist[n];
}
