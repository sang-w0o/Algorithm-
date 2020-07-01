#include <iostream>
using namespace std;

int min(int a, int b) {
	return (a >= b) ? b : a;
}

int getGCD(int a, int b) {
	int result = 1;
	for (int i = min(a,b); i >= 1; i--) {
		if (a % i == 0 && b % i == 0) {
			result = i;
			break;
		}
	}
	return result;
}

int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int N;
	cin >> N;

	while (N--) {
		int numbers;
		cin >> numbers;
		int *a = new int[numbers];
		for (int i = 0; i < numbers; i++)
			cin >> a[i];
		long long result = 0;
		for (int i = 0; i < numbers; i++) {
			for (int j = i + 1; j < numbers; j++) {
				result += getGCD(a[i], a[j]);
			}
		}
		cout << result << '\n';
		
		delete[] a;
	}
	return 0;
}