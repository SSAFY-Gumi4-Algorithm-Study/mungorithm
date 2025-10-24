#include<iostream>
#include<vector>
#include<algorithm>
#include<tuple>
#include<string>
#include<unordered_set>
#include<stack>
#include<cmath>
#include<queue>
#include<deque>
#include<unordered_map>
using namespace std;

struct Trie {
	Trie* child[26];
	bool isEnd;
	int cnt;

	Trie() {
		for (int i = 0; i < 26; i++) child[i] = nullptr;
		isEnd = false;
		cnt = 0;
	}
};

int n;
unordered_map<string, int> mp;

string insert(Trie* root, string s) {
	Trie* cur = root;
	string prefix = "";
	string uniquePrefix = "";

	for (char c : s) {
		int idx = c - 'a';
		prefix += c;
		if (cur->child[idx] == nullptr) cur->child[idx] = new Trie();
		cur = cur->child[idx];
		cur->cnt++;
		if (cur->cnt == 1 && uniquePrefix.empty()) {
			uniquePrefix = prefix;
		}
	}

	cur->isEnd = true;

	if (mp.find(s) != mp.end()) {
		mp[s]++;
		return s + to_string(mp[s]);
	}
	else {
		mp[s] = 1;
		if (!uniquePrefix.empty()) return uniquePrefix;
		return s;
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> n;
	Trie* root = new Trie();

	for (int i = 0; i < n; i++) {
		string s;
		cin >> s;
		cout << insert(root, s) << '\n';
	}
	return 0;
}
