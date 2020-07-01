// nCm = n! / (n-m)! * m!
// ������ 2�� ������ 5�� �������� �� ���� ��찡 �ִ�.

#include <iostream>
using namespace std;

int min(int a, int b) {
	return (a >= b) ? b : a;
}
int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	long long N, M;
	int two = 0, five = 0;
	cin >> N >> M;

	for (long long i = 2; i <= N; i *= 2) {
		two += N / i;
	}

	for (long long i = 2; i <= M; i *= 2) {
		two -= M / i;
	}

	for (long long i = 2; i <= N - M; i *= 2) {
		two -= (N-M) / i;
	}

	for (long long i = 5; i <= N; i *= 5) {
		five += N / i;
	}

	for (long long i = 5; i <= N - M; i *= 5) {
		five -= (N - M) / i;
	}

	for (long long i = 5; i <= M; i *= 5) {
		five -= M / i;
	}
	
	cout << min(two, five) << '\n';
}