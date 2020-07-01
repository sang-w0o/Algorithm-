#include <iostream>
using namespace std;

int factorial(int n) {
	if (n > 2)
		n *= factorial(n - 1);
	return n;
}

int main() {
	
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int N;
	cin >> N;
	if (N) {
		cout << factorial(N) << '\n';
	}
	else {
		cout << 1 << '\n';
	}
}