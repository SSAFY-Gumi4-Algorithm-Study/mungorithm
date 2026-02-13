#include <iostream>
#include <algorithm>
#include <deque>
#include <vector>
#include <queue>
#include <cmath>
#include <unordered_set>
#include <unordered_map>
#include <map>
#include <set>
#include <string>
#include <tuple>
#include <climits>
using namespace std;

string s1, s2;
int dp[4001][4001];
int ret = 0;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> s1 >> s2;

	for (int i = 0; i < s1.size(); i++) {
		if (s1[i] == s2[0]) dp[i][0] = 1;
	}

	for (int j = 0; j < s2.size(); j++) {
		if (s1[0] == s2[j]) dp[0][j] = 1;
	}

	for (int i = 1; i < s1.size(); i++) {
		for (int j = 1; j < s2.size(); j++) {
			if (s1[i] == s2[j]) {
				dp[i][j] = dp[i - 1][j - 1] + 1;
				ret = max(dp[i][j], ret);
			}
		}
	}

	cout << ret;
}
