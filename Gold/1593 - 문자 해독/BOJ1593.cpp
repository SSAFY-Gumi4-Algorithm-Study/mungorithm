#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <set>
#include <unordered_set>
#include <cstring>
using namespace std;

int n, m;
string w, s;
int w_cnt[128];
int s_cnt[128];

bool check() {
	for (int i = 0; i < 128; i++) {
		if (w_cnt[i] != s_cnt[i]) return false;
	}
	return true;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> n >> m;
	cin >> w >> s;
	for (int i = 0; i < n; i++) {
		w_cnt[w[i]]++;
	}

	for (int i = 0; i < n; i++) {
		s_cnt[s[i]]++;
	}

	int ret = 0;

	if (check()) ret++;

	for (int i = n; i < m; i++) {
		s_cnt[s[i]]++;
		s_cnt[s[i - n]]--;
		if (check()) ret++;
	}
	cout << ret;
}
