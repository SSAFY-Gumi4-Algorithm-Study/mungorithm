#include<iostream> 
#include<algorithm> 
#include<vector> 
using namespace std; 

int n, m, r; 
int a[301][301]; 
int dy[] = { 0, 1, 0, -1 }; 
int dx[] = { 1, 0, -1, 0 }; 

void rotate(int layer) { 
	int len_y = n - 2 * layer; 
	int len_x = m - 2 * layer; 
	int len = len_y * 2 + len_x * 2 - 4; 
	for (int i = 0; i < r % len; i++) { 
		int y = layer; 
		int x = layer; 
		int dir = 0; 
		int tmp = a[y][x]; 
		while (true) { 
			int ny = y + dy[dir]; 
			int nx = x + dx[dir]; 
			if (ny < layer || nx < layer || ny >= n - layer || nx >= m - layer) { 
				dir++; 
				ny = y + dy[dir]; 
				nx = x + dx[dir]; 
			} 
			if (ny == layer && nx == layer) { 
				break; 
			} 
			a[y][x] = a[ny][nx]; 
			y = ny; 
			x = nx; 
		} 
		a[y][x] = tmp; 
	} 
} 
int main() { 
	cin >> n >> m >> r; 
	for (int i = 0; i < n; i++) { 
		for (int j = 0; j < m; j++) { 
			cin >> a[i][j]; 
		} 
	} 
	int layer = n > m ? m / 2 : n / 2; 
	for (int i = 0; i < layer; i++) { 
		rotate(i); 
	} 
	for (int i = 0; i < n; i++) { 
		for (int j = 0; j < m; j++) { 
			cout << a[i][j] << ' '; 
		} 
		cout << '\n'; 
	} 
}
