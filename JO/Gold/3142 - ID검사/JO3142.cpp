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

int n;
unordered_set<string> id, active;

int validate(string s) {
	if (id.count(s)) return 1;
	return 0;
}

int activate(string s) {
	if (active.count(s)) return 1;
	return 0;
}

int signup(string s) {
	if (id.count(s)) return id.size();
	id.insert(s);
	return id.size();
}

int close(string s) {
	if (id.count(s)) {
		active.erase(s);
		id.erase(s);
	}
	return id.size();
}

int login(string s) {
	if (id.count(s) && !active.count(s)) {
		active.insert(s);
	}
	return active.size();
}

int logout(string s) {
	if (active.count(s)) {
		active.erase(s);
	}
	return active.size();
}

int main() {
	cin >> n;
	for (int i = 1; i <= n; i++) {
		int cmd;
		string s;
		cin >> cmd >> s;
		if (cmd == 1) cout << validate(s);
		else if (cmd == 2) cout << activate(s);
		else if (cmd == 3) cout << signup(s);
		else if (cmd == 4) cout << close(s);
		else if (cmd == 5) cout << login(s);
		else cout << logout(s);
		cout << '\n';
	}
}
