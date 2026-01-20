#include <iostream>
#include <algorithm>
#include <deque>
#include <vector>
#include <queue>
#include <cmath>
#include <stack>
#include <unordered_set>
#include <unordered_map>
#include <map>
#include <set>
#include <string>
#include <tuple>
#include <climits>
using namespace std;

string s;
stack<char> stk;
stack<int> lenstk;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> s;

	for (int i = 0; i < s.size(); i++) {
		if (s[i] == ')') {
			int len = 0;
			while (!stk.empty() && stk.top() != '(') {
				char ch = stk.top();
				stk.pop();
				if (ch == '#') {
					len += lenstk.top();
					lenstk.pop();
				}
				else {
					len += 1;
				}
			}
			stk.pop();
			int k = stk.top() - '0';
			stk.pop();
			lenstk.push(len * k);
			stk.push('#');
		}
		else {
			stk.push(s[i]);
		}
	}
	int ret = 0;
	while (!stk.empty()) {
		if (stk.top() == '#') {
			stk.pop();
			ret += lenstk.top();
			lenstk.pop();
		}
		else {
			stk.pop();
			ret += 1;
		}
	}
	cout << ret;
}
