#define SIZE 1000000
#include <iostream>
using namespace std;

int isNotPrime[SIZE];

void makePrime() {
	for (int i = 2; i * i < SIZE; i++) {
		if (!isNotPrime[i])
			for (int j = i * i; j < SIZE; j += i)
				isNotPrime[j] = 1;
	}
	isNotPrime[1] = 1;
}

void goldBach(int n) {
	int mid = n >> 1;
	for (int i = 0, j = n; i <= mid; i++, j--) {
		if (i % 2 == 1 && j % 2 == 1 && !isNotPrime[i] && !isNotPrime[j]) {
			cout << n << " = " << i << " + " << j << '\n';
			return;
		}
	}
	cout << "Goldbach's conjecture is wrong." << '\n';
}

int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	makePrime();
	int N;
	while (true) {
		cin >> N;
		if (!N)
			break;
		goldBach(N);
	}
	return 0;
}