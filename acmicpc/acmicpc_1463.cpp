#include <iostream>
using namespace std;

int d[1000000]; // For Memoization

int makeToOne(int n) {

	if (n == 1) return 0;

	if (d[n] > 0) return d[n];

	d[n] = makeToOne(n - 1) + 1;

	if (n % 2 == 0) {
		int temp = makeToOne(n / 2) + 1;
		if (d[n] > temp) d[n] = temp;
	}
	if (n % 3 == 0) {
		int temp = makeToOne(n / 3) + 1;
		if (d[n] > temp) d[n] = temp;
	}
	return d[n];

	// 위는 Top-Down 방식이고, 아래는 Bottom-Up 방식이다.
	
	/*
	d[1] = 0;
	for (int i = 2; i <= n; i++) {
		d[i] = d[i - 1] + 1;
		if (i % 2 == 0 && d[i] > d[i / 2] + 1) {
			d[i] = d[i / 2] + 1;
		}
		if (i % 3 == 0 && d[i] > d[i / 3] + 1) {
			d[i] = d[i / 3] + 1;
		}
	}
	*/
}

int main() {

	int N;

	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> N;

	int res = makeToOne(N);

	cout << res << '\n';

}