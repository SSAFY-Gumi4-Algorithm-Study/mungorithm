#include<iostream> 
#include<algorithm> 
#include<vector> 
#include<string>
#include<queue>
#include<unordered_set>
using namespace std;

long long n;
int ret[7] = {0, 1, 0, 1, 1, 1, 1};

int main() {
	cin >> n;
	cout << (ret[n % 7] ? "SK" : "CY");
}
