#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;
vector <pair<int,pair<int,int>>>vc[101];
priority_queue<pair<int,pair<int, int>>> pq;
int dis[101][10001];

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	int T; cin >> T;
	int n, m, k,u,v,c,d; cin >> n >> m >> k;
	for (int i = 0; i < k; i++) {
		cin >> u >> v >> c >> d;
		vc[u].push_back({ v,{c,d} });
	}

	for (int i = 1; i <= n; i++) {
		sort(vc[i].begin(), vc[i].end());
		for (int j = 0; j <= m; j++) dis[i][j] = 100001;
	}

	pq.push({ 0,{1,0} });
	dis[1][0] = 0;
	while (!pq.empty()) {
		int now = pq.top().second.first;//현재 출발도시
		int dist = -pq.top().first;//현재 거리
		int cost = pq.top().second.second;//현재 비용
		pq.pop();

		if (dist>dis[now][cost])continue;
	

		for (auto& x : vc[now]) {
			if (cost+x.second.first<=m&&dist+x.second.second<dis[x.first][cost+x.second.first]) {
				dis[x.first][x.second.first+ cost] = dist + x.second.second;
				for (int i = cost + x.second.first; i <= m; i++) {
					if (dis[x.first][i] > dist + x.second.second)dis[x.first][i] = dist + x.second.second;
					else break;
				}
				pq.push({ -(x.second.second + dist),{x.first,cost + x.second.first} });
			}
		}
	}
	
	int ans = 100001;
	for (int i = 0; i <= m;i++) {
			ans = min(ans, dis[n][i]);
		}
	if (ans == 100001)cout << "Poor KCM";
	else cout << ans;

}
