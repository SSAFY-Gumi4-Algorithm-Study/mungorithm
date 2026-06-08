#include<iostream>
#include<vector>
#include<queue>
#include<unordered_set>
#include<cstring>
#include <set>
#include <map>
using namespace std;

int n;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	priority_queue<int> a;
	priority_queue<int, vector<int>, greater<>> b;
	int x, y;
	cin >> n;
	cin >> x;
	a.push(x);
	cout << x << '\n';
	for (int i = 0; i < (n - 1) / 2; i++) {
		cin >> x >> y;
		if (x > a.top()) {
			b.push(x);
		}
		else {
			a.push(x);
		}
		if (y > a.top()) {
			b.push(y);
		}
		else {
			a.push(y);
		}
		while (a.size() - b.size() != 1) {
			if (a.size() > b.size()) {
				x = a.top();
				a.pop();
				b.push(x);
			}
			else {
				x = b.top();
				b.pop();
				a.push(x);
			}
		}
		cout << a.top() << '\n';
	}
}
