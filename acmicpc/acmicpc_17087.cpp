#include <iostream>
using namespace std;

inline int min(int a, int b) {
	return (a >= b) ? b : a;
}

int abs(int a) {
	if (a <= 0)
		return -a;
	return a;
}

int getGCD(int a, int b) {
	/*for (int i = min(a, b); i >= 1; i--) {
		if (a % i == 0 && b % i == 0) {
			return i;
		}
	}
	return 1;*/
	// 위 코드로 했을 시에는 시간 초과가 뜬다.
	// 위 코드는 O(N)의 시간이 걸리지만,
	// 아래의 방식처럼 유클리드 호제법을 이용하면
	// 시간복잡도는 O(lg(a+b)) 이다.
	if (b == 0) return a;
	else return getGCD(b, a % b);
}

int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int N, S;
	cin >> N >> S;

	int *dist = new int[N];

	for (int i = 0; i < N; i++) {
		int tmp;
		cin >> tmp;
		dist[i] = abs(S - tmp);
	}

	int result = dist[0];

	for (int i = 1; i < N; i++) {
		result = getGCD(result, dist[i]);
	}
	cout << result << '\n';

	delete[] dist;
}