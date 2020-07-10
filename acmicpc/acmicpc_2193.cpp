#include <iostream>
using namespace std;

// D[N][L] : number of N-length pinary numbers where last-number is L
// if L == 1 --> D[N][L] = D[N-1][L-1]
// if L == 0 --> D[N][L] = D[N-1][L] + D[N-1][L+1]

long long d[91][2];

int main() {
	
	ios_base::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	
	int N;
	cin >> N;
	
	
	d[1][0] = 0; d[1][1] = 1;
	
	for(int i = 2; i <= N; i++){
		d[i][0] = d[i-1][0] + d[i-1][1];
		d[i][1] = d[i-1][0];
	}
	
	cout << d[N][0] + d[N][1] << '\n';
	
}
