#include <iostream>
using namespace std;

int D[1001];

int max(int a, int b) {
	return (a>=b) ? a : b;
}

int main() {
	
	ios_base::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	
	int N;
	cin >> N;
	
	int *arr = new int[N + 1];
	
	for(int i = 1; i <= N; i++) {
		cin >> arr[i];
		D[i] = 1;
	}
	
	int tmp = 0;
	
	for(int i = 1; i <= N; i++) {
		for(int j = i; j >= 1; j--) {
			if(arr[i] > arr[j]) {
				tmp = max(tmp, D[j]);
			}
		}
		D[i] += tmp;
		tmp = 0;
	}
	
	int res = 0;
	
	for(int i = 1; i <= N; i++) {
		res = max(res, D[i]);
	}
	cout << res << '\n';
	delete[] arr;
	
	
}
