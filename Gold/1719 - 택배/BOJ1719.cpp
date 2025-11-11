#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
#include<tuple>
#include<string>
#include<unordered_map>
#include<unordered_set>

using namespace std;

int n, m;
int a[201][201];
int ret[201][201];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			if (i == j) a[i][j] = 0;
			else a[i][j] = 987654321;
		}
	}
	for (int i = 0; i < m; i++) {
		int from, to, dist;
		cin >> from >> to >> dist;
		a[from][to] = dist;
		a[to][from] = dist;
		ret[from][to] = to;
		ret[to][from] = from;
	}
	for (int k = 1; k <= n; k++) {
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= n; j++) {
				if (a[i][j] > a[i][k] + a[k][j]) {
					a[i][j] = a[i][k] + a[k][j];
					ret[i][j] = ret[i][k];
				}
			}
		}
	}
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			if (i == j) cout << "- ";
			else if (ret[i][j] == 0) cout << j << ' ';
			else cout << ret[i][j] << ' ';
		}
		cout << '\n';
	}
}
