#include <iostream>
using namespace std;

int d[1001];

void makeArray(int n) {
	d[1] = 1;
	d[2] = 3;
	

	for (int i = 3; i <= n; i++) {
		d[i] = (d[i - 1] + d[i - 2] + d[i - 2]) % 10007;
	}

}
int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int n;
	cin >> n;

	makeArray(n);

	cout << d[n] << '\n';

}