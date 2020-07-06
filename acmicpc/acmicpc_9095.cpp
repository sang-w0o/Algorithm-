#include <iostream>
using namespace std;

int d[10];

int solve(int n) {
	d[0] = 1;
	d[1] = 1;
	d[2] = 2;
	for (int i = 3; i <= n; i++) {
		d[i] = d[i - 1] + d[i - 2] + d[i - 3];
	}
	return d[n];
}

int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int T;
	cin >> T;

	while (T--) {
		int N = 0;
		cin >> N;
		cout << solve(N) << '\n';

	}
}