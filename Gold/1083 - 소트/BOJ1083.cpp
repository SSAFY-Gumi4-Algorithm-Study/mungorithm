#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <set>
#include <unordered_set>
#include <cstring>
using namespace std;

int n;
vector<int> v;
int s;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> n;
	v.resize(n);
	for (int i = 0; i < n; i++) {
		cin >> v[i];
	}
	cin >> s;
	int cnt = 0;
	
	for (int i = 0; i < n && s > 0; i++) {
		int idx = i;

		for (int j = i + 1; j < n && j <= i + s; j++) {
			if (v[j] > v[idx]) {
				idx = j;
			}
		}

		for (int j = idx; j > i; j--) {
			swap(v[j], v[j - 1]);
		}

		s -= (idx - i);
	}

	for (int i : v) {
		cout << i << ' ';
	}
}
