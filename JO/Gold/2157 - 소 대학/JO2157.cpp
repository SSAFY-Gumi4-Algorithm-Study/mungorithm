#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>
#include<unordered_set>
#include<unordered_map>
#include<cstring>
#include <set>
#include <map>
using namespace std;

int n, c, f;

struct Cow {
	int score;
	int money;

	bool operator < (Cow& other) const {
		return score < other.score;
	}
};

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> n >> c >> f;

	vector<Cow> cows(c);

	for (int i = 0; i < c; i++) {
		cin >> cows[i].score >> cows[i].money;
	}

	sort(cows.begin(), cows.end());

	int k = n / 2;

	long long INF = 1e18;

	vector<long long> l(c, INF);
	vector<long long> r(c, INF);

	priority_queue<int> pq;
	long long sum = 0;

	for (int i = 0; i < c; i++) {
		if (pq.size() == k) {
			l[i] = sum;
		}

		pq.push(cows[i].money);
		sum += cows[i].money;

		if (pq.size() > k) {
			sum -= pq.top();
			pq.pop();
		}
	}

	while (!pq.empty()) pq.pop();
	sum = 0;

	for (int i = c - 1; i >= 0; i--) {
		if (pq.size() == k) {
			r[i] = sum;
		}

		pq.push(cows[i].money);
		sum += cows[i].money;

		if (pq.size() > k) {
			sum -= pq.top();
			pq.pop();
		}
	}

	for (int i = c - 1; i >= 0; i--) {
		long long total = l[i] + cows[i].money + r[i];

		if (total <= f) {
			cout << cows[i].score;
			return 0;
		}
	}

	cout << -1;
}
