#include <iostream>
#include <limits.h>
using namespace std;

int max(int a, int b) {
	return (a>=b) ? a : b;
}

int main() {
	
	ios_base::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	
	int n;
	cin >> n;
	
	int *arr = new int[n + 1];
	
	int *D = new int[n + 1];
	
	for(int i = 1; i <= n; i++) {
		cin >> arr[i];
		D[i] = arr[i];
	}
	
	D[1] = arr[1];

	
	for(int i = 2; i <= n; i++) {
		int tmp = arr[i];
		int tmp2 = D[i-1] + tmp;
		D[i] = max(tmp, tmp2);
	}
	
	int res = -INT_MAX;
	
	for(int i = 1; i <= n; i++) {
		res = max(res, D[i]);
	}
	
	cout << res << '\n';
	
	delete[] D;
	delete[] arr;
	return 0;
	
}
