#include <iostream>
using namespace std;

int min(int n, int m) {
	return (n >= m) ? m : n;
}

int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int N, M;
	cin >> N;
	cin >> M;

	int g = 1;
	for (int i = 1; i <= min(N, M); i++) {
		if (N % i == 0 && M % i == 0) {
			g = i;
		}
	}

	cout << g << '\n';

	int b = 1;

	for (int i = 1; i < g; i++) {
		for (int j = 1; j < g; j++) {
			if ((N * i == M * j) && (N * i % N == 0) && (M * j % N == 0)) {
				b = N * i;
			}
		}
	}

	cout << b << '\n';
}