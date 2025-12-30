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
using namespace std;

int T;
int n;
vector<string> v;

bool check(string s) {
	int sum = 0;
	int cur = 0;
	char op = '+';
	for (int i = 0; i < s.size(); i++) {
		if (s[i] == ' ') continue;
		if (isdigit(s[i])) {
			int num = s[i] - '0';
			while (i + 2 < s.size() && s[i + 1] == ' ') {
				i += 2;
				num = num * 10 + (s[i] - '0');
			}
			if (op == '+') cur += num;
			else cur -= num;
		}
		else op = s[i];
	}
	return cur == 0;
}

void solve(int cnt, string s) {
	if (cnt == n + 1) {
		if (check(s)) v.push_back(s);
		return;
	}
	solve(cnt + 1, s + " " + to_string(cnt));
	solve(cnt + 1, s + "+" + to_string(cnt));
	solve(cnt + 1, s + "-" + to_string(cnt));
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	
	cin >> T;
	for (int t = 0; t < T; t++) {
		v.clear();
		cin >> n;
		solve(2, "1");
		for (string s : v) {
			cout << s << '\n';
		}
		cout << '\n';
	}
}
