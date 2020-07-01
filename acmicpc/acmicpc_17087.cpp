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
	// �� �ڵ�� ���� �ÿ��� �ð� �ʰ��� ���.
	// �� �ڵ�� O(N)�� �ð��� �ɸ�����,
	// �Ʒ��� ���ó�� ��Ŭ���� ȣ������ �̿��ϸ�
	// �ð����⵵�� O(lg(a+b)) �̴�.
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