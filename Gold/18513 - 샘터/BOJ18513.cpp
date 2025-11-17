#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <unordered_set>
using namespace std;

int n, k;
vector<int> v;
unordered_set<int> st;
int cnt = 0;
long long ret = 0;

int main(){
	cin >> n >> k;
	for (int i = 0; i < n; i++) {
		int num;
		cin >> num;
		v.push_back(num);
	}
	queue<pair<int, int>> q;
	for (int num : v) {
		q.push({ num, 0 });
		st.insert(num);
	}
	while (!q.empty()) {
		int cur = q.front().first;
		int dist = q.front().second;
		q.pop();
		if (!st.count(cur + 1)) {
			st.insert(cur + 1);
			cnt++;
			ret += dist + 1;
			q.push({ cur + 1, dist + 1 });
		}
		if (cnt == k) break;
		if (!st.count(cur - 1)) {
			st.insert(cur - 1);
			cnt++;
			ret += dist + 1;
			q.push({ cur - 1 , dist + 1 });
		}
		if (cnt == k) break;
	}
	cout << ret;
}
