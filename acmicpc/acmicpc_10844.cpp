#define DIV 1000000000
#include <iostream>
using namespace std;

long long D[101][10];

// D[N][L] : case of stair numbers of which length is n, lastly used number is L
//  ^== N-th number is L
// (N-1)th number can be L+1 and L-1
// D[N][L] = D[N-1][L-1] + D[N-1] + D[L+1]
// if L = 0 --> D[N][L] = D[N-1][L+1]
// if L = 9 --> D[N][L] = D[N-1][L-1]
int main() {
	
	ios_base::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	
	int N;
	cin >> N;
	
	for(int i = 1; i <= 9; i++)
		D[1][i] = 1;
	
	for(int i = 2; i <= N; i++) {
		for(int j = 0; j <= 9; j++) {
			if(j - 1 >= 0) D[i][j] += D[i-1][j-1];
			if(j + 1 <= 9) D[i][j] += D[i-1][j+1];
			D[i][j] %= DIV;
		}
	}
	
	long long res = 0;
	for(int i = 0; i <= 9; i++) {
		res += D[N][i];
	}
	
	cout << res % DIV << '\n';
	
}
