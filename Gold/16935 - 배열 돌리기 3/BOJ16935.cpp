#include<iostream> 
#include<algorithm> 
#include<vector> 
#include<string>
#include<unordered_map>
using namespace std; 

int n, m, r;
int a[101][101];

void rotate(int cmd) {
	int tmp[101][101];
	if (cmd == 1) {
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				tmp[i][j] = a[n - 1 - i][j];
			}
		}
	}
	else if (cmd == 2) {
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				tmp[i][j] = a[i][m - 1 - j];
			}
		}
	}
	else if (cmd == 3) {
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				tmp[j][n - 1 - i] = a[i][j];
			}
		}
		swap(n, m);
	}
	else if (cmd == 4) {
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				tmp[m - 1 - j][i] = a[i][j];
			}
		}
		swap(n, m);
	}
	else if (cmd == 5) {
		int n2 = n / 2, m2 = m / 2;
		for (int i = 0; i < n2; i++) {
			for (int j = 0; j < m2; j++) {
				tmp[i][j + m2] = a[i][j];
				tmp[i + n2][j + m2] = a[i][j + m2];
				tmp[i + n2][j] = a[i + n2][j + m2];
				tmp[i][j] = a[i + n2][j];
			}
		}
	}
	else if (cmd == 6) {
		int n2 = n / 2, m2 = m / 2;
		for (int i = 0; i < n2; i++) {
			for (int j = 0; j < m2; j++) {
				tmp[i + n2][j] = a[i][j];
				tmp[i + n2][j + m2] = a[i + n2][j];
				tmp[i][j + m2] = a[i + n2][j + m2];
				tmp[i][j] = a[i][j + m2];
			}
		}
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			a[i][j] = tmp[i][j];
		}
	}
}

int main() {
	cin >> n >> m >> r;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> a[i][j];
		}
	}
	for (int i = 0; i < r; i++) {
		int cmd;
		cin >> cmd;
		rotate(cmd);
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cout << a[i][j] << ' ';
		}
		cout << '\n';			
	}
}
