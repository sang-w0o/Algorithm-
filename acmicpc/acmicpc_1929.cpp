#include <iostream>
#include <vector>
using namespace std;

int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int N;
	int M;
	cin >> N;
	cin >> M;

	int *a = new int[M + 1];

	for (int i = 0; i < M + 1; i++) {
		a[i] = 0;
	}
	a[1] = 1;

	for (int i = 2; i <= M; i++) {
		for (int j = 2; i * j <= M; j++) {
			a[i * j] = 1;
		}
	}

	//위 for문 돈 후 a배열의 값.
	// 0 1 0 0 1 0 1 0 1 1 1 0 1 0 1 1 1

	for (int i = N; i <= M; i++) {
		if (!a[i])
			cout << i << '\n';
	}

	delete[] a;
	return 0;
}