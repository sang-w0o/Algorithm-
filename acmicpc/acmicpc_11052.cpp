#include <iostream>
using namespace std;

int d[1001];

int max(int a, int b) {
	return a >= b ? a : b;
}

int main() {
	
	ios_base::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	
	int N;
	cin >> N;
	
	int *p = new int[N + 1];
	
	p[0] = 0;
	
	for(int i = 1; i <= N; i++) {
		cin >> p[i];
	}
	
	// D[N] : Maximum cost to buy N cards.
	// D[N] = p[i] + D[n-i]
	// D[n] = MAX(D[n-i] + p[i]);
	// 1 <= i <= N
	
	int result = 0;
	
	for(int i = 1; i <= N; i++) {
		for(int j = 1; j <= i; j++){
			d[i] = max(d[i], d[i-j] + p[j]);
		}	
	}
	
	cout << d[N] << '\n';
}
