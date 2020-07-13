#include <iostream>
using namespace std;
#define DIV 1000000000
// D[K][N] : ways to make N with sum of K numbers from 0~N
// L : Last number used in addtion of K numbers to make N

// ( N - L ) + L = N
// count of numbers : ( K - 1 ) + 1 = K

// Thus, D[K][N] = (Sigma) D[K-1][N-1] + 1 ( 0 <= L <= N )

long long D[201][201];

int main() {
	
	ios_base::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	
	int N, K;
	
	cin >> N >> K;

	D[0][0] = 1LL;
	
	for(int i = 1; i <= K; i++) {
		for(int j = 0; j <= N; j++) {
			for(int l = 0; l <= j; l++) {
			D[i][j] += D[i-1][j-l];
			D[i][j] %= DIV;
			}
		}
	}
	
	cout << D[K][N] << '\n';

	
	return 0;
}
