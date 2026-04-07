#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <set>
#include <unordered_set>
#include <cstring>
using namespace std;

int a, b, n;

struct Work {
	int start;
	char color;
	
	bool operator < (const Work& other) const {
		if (start == other.start) return color < other.color;
		return start < other.start;
	}
};

vector<Work> v;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> a >> b >> n;
	int rTime = 0, bTime = 0;

	for (int i = 0; i < n; i++) {
		int s;
		char col;
		int num;
		cin >> s >> col >> num;
		if (col == 'B') {
			bTime = max(bTime, s);
			for (int j = 0; j < num; j++) {
				if(j != 0) bTime += a;
				v.push_back({ bTime, 'B' });
			}
			bTime += a;
		}
		else {
			rTime = max(rTime, s);
			for (int j = 0; j < num; j++) {
				if (j != 0) rTime += b;
				v.push_back({ rTime, 'R' });
			}
			rTime += b;
		}
	}
	sort(v.begin(), v.end());
	vector<int> R, B;
	for (int i = 0; i < v.size(); i++) {
		if (v[i].color == 'R') {
			R.push_back(i + 1);
		}
		else {
			B.push_back(i + 1);
		}
	}

	cout << B.size() << '\n';
	for (int i : B) {
		cout << i << ' ';
	}
	cout << '\n' << R.size() << '\n';
	for (int i : R) {
		cout << i << ' ';
	}
}
