#include <iostream>
using namespace std;

#define SIZE 10000001
int isNotPrime[SIZE];

void makePrime() {
	for (int i = 2; i * i < SIZE; i++) {
		if (!isNotPrime[i]) {
			for (int j = i * i; j < SIZE; j += i) {
				isNotPrime[j] = 1;
			}
		}
	}
	isNotPrime[1] = 1;
}

int goldBach(int n) {
	int res = 0;
	int mid = n >> 1;
	for (int i = 0, j = n; i <= mid; i++, j--) {
		if (i % 2 == 1 && j % 2 == 1 && !isNotPrime[i] && !isNotPrime[j]) {
			res++;
		}
	}
	if (res == 0)
		return 1;
	return res;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	makePrime();
	int N;
	cin >> N;

	while (N--) {
		int n;
		cin >> n;
		cout << goldBach(n) << '\n';
	}
	return 0;
}