#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

int n, m, r;
int a[300][300];
int dy[] = {0, 1, 0, -1};
int dx[] = {1, 0, -1, 0};


void rotate(int layer){
    for(int l = 0; l < layer; l++){
        int dir = 0;
        int tmp = a[l][l];
        int y = l;
        int x = l;
        while(true){
            int ny = y + dy[dir];
            int nx = x + dx[dir];
            if(ny < l || nx < l || ny >= n - l || nx >= m - l){
                dir++;
                ny = y + dy[dir];
                nx = x + dx[dir];
            }
            if(ny == l && nx == l){
                a[y][x] = tmp;
                break;
            }
            a[y][x] = a[ny][nx];
            y = ny;
            x = nx;
        }
    }
}

int main(){
    cin >> n >> m >> r;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            cin >> a[i][j];
        }
    }
    int layer = n > m ? m / 2 : n / 2;
    for(int i = 0; i < r; i++){
        rotate(layer);
    }
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            cout << a[i][j] << ' ';
        }
        cout << '\n';
    }
}
