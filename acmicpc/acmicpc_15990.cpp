#define DIV 1000000009
#include <iostream>
#include <cstring>

using namespace std;

long long D[100001][4];


	// D[i][j] : Ways to make i with sum of 1, 2, 3
	// j : Lastly used number in sum
	
	// D[i][1] = D[i-1][2] + D[i-1][3]
	// D[i][2] = D[i-2][1] + D[i-2][3]
	// D[i][3] = D[i-3][1] + D[i-3][2]
	
	// if j = N --> D[i][N] = D[i-N][2] + D[i-N][3] (i > N)
	// if i = N --> D[i][N] = 1
	// if i < N --> 0

int main() {
	
	ios_base::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	
	int T;
	cin >> T;
	D[1][1] = 1; D[2][2] = 1; D[3][3] = 1;
	D[3][1] = 1; D[3][2] = 1;
	
	for(int i = 4; i <= 100000; i++) {
		D[i][1] = (D[i-1][2] + D[i-1][3]) % DIV;
		D[i][2] = (D[i-2][1] + D[i-2][3]) % DIV;
		D[i][3] = (D[i-3][1] + D[i-3][2]) % DIV;
	}
	while(T--) {
		int n;
		cin >> n;
		cout << (D[n][1] + D[n][2] + D[n][3]) % DIV << '\n';
	}
	
	return 0;
}
