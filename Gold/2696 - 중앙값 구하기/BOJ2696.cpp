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

int T;
int n;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	
	cin >> T;
	for (int t = 1; t <= T; t++) {
		cin >> n;
		priority_queue<int> min_pq;
		priority_queue<int, vector<int>, greater<>> max_pq;
		vector<int> v;
		for (int i = 1; i <= n; i++) {
			int num;
			cin >> num;
			if (max_pq.empty()) {
				max_pq.push(num);
			}
			else if (max_pq.top() >= num) {
				min_pq.push(num);
			}
			else if (max_pq.top() < num) {
				max_pq.push(num);
			}
			if (max_pq.size() - min_pq.size() == 2) {
				int tmp = max_pq.top();
				max_pq.pop();
				min_pq.push(tmp);
			}
			else if (min_pq.size() - max_pq.size() == 1) {
				int tmp = min_pq.top();
				min_pq.pop();
				max_pq.push(tmp);
			}
			if (i % 2) {
				v.push_back(max_pq.top());
			}
		}
		cout << v.size() << '\n';
		for (int i = 1; i <= v.size(); i++) {
			cout << v[i - 1] << ' ';
			if (i % 10 == 0) cout << '\n';
		}
	}
}
