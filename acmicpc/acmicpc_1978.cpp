#include <iostream>
#include <vector>
using namespace std;

bool isPrime(int n) {
	if (n < 2)
		return false;
	for (int i = 2; i * i <= n; i++) {
		if (n % i == 0) {
			return false;
		}
	}
	return true;
}

int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int N;
	cin >> N;

	int *a = new int[N];

	for (int i = 0; i < N; i++) {
		cin >> a[i];
	}

	int count = 0;

	for (int i = 0; i < N; i++) {
		if (isPrime(a[i])) {
			++count;
		}
	}

	cout << count << '\n';

	delete[] a;

	return 0;
}