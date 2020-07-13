#include <iostream>
#include <cmath>
using namespace std;

int main() {
	
	ios_base::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	
	int N;
	cin >> N;
	
	int *D = new int[N + 1];
	
	for(int i = 0; i <= N; i++) {
		D[i] = 0;
	}

	
	for(int i = 1; i <= N; i++) {
		D[i] = i;
		for(int j = 1; j * j <= i; j++) {
			if(D[i] > D[i - j*j] + 1){
				D[i] = D[i - j*j] + 1;
			}
		}
	}
	
	cout << D[N] << '\n';
	
	delete[] D;

	return 0;
	
}

