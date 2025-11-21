#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
#include<tuple>
#include<string>
#include<unordered_map>
#include<unordered_set>
#include<cmath>

using namespace std;

int n;
pair<int, int> node[10001];
int check[10001];
int cnt = 1;
int leftmn[10001], rightmx[10001];
int mxlevel = -1;

void inorder(int cur, int level) {
	mxlevel = max(mxlevel, level);
	if (node[cur].first != -1) {
		inorder(node[cur].first, level + 1);
	}
	leftmn[level] = min(leftmn[level], cnt);
	rightmx[level] = max(rightmx[level], cnt);
	cnt++;
	if (node[cur].second != -1) {
		inorder(node[cur].second, level + 1);
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> n;
	for (int i = 0; i < n; i++) {
		int c, l, r;
		cin >> c >> l >> r;
		node[c] = { l, r };
		if(l != -1) check[l] = 1;
		if(r != -1) check[r] = 1;
	}
	int root = -1;
	for (int i = 1; i <= n; i++) {
		if (!check[i]) {
			root = i;
			break;
		}
	}
	fill(leftmn, leftmn + 10001, 987654321);
	inorder(root, 1);
	int ret_w = 0;
	int ret_l = 0;
	for (int i = 1; i <= mxlevel; i++) {
		if (ret_w < rightmx[i] - leftmn[i] + 1) {
			ret_w = rightmx[i] - leftmn[i] + 1;
			ret_l = i;
		}
	}
	cout << ret_l << ' ' << ret_w;
}
