#include <iostream>
#include <stack>
#include <vector>
using namespace std;

int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int N;
	cin >> N;

	vector<int> a(N);
	vector<int> answer(N);

	// N���� �� �Է¹޾Ƽ� a�� ����
	for (int i = 0; i < N; i++) {
		cin >> a[i];
	}
	stack<int> s;

	// 5, 2, 7�� �ִٰ� ����. 2�� ��ū���� 7 �̰�, 
	// 5�� ��ū���� 7�̴�.
	// ���� 5, 6, 7�� �ִٸ� 6�� ��ū���� 7������,
	// 5�� ��ū���� 6�� �ȴ�.
	// � ���� ��ū���� 7�̶�� ���� �� ���� 7 ���̿�
	// 7���� ū ���� ���ٴ� ���̴�.

	// �� ������ �̿��ؼ� ������ ����ϸ�,
	// ������ ���� ��(top)�� �ִ� �� ���� ū ���� ������ �Ǹ�
	// �� ���� �ٷ� ��ū���� �ȴ�.
	// ��ū���� ã�� ���� ���ÿ��� �ٷ� pop�Ѵ�.

	s.push(0);
	for (int i = 1; i < N; i++) {
		if (s.empty()) {
			s.push(i);
		}
		while (!s.empty() && a[s.top()] < a[i]) {
			answer[s.top()] = a[i];
			s.pop();
		}
		s.push(i);
	}

	// a[0] = 3, a[1] = 5, a[2] = 2, a[3] = 7
	// answer : [0] : 5, [1] : 7, [2] : 7, [3] : -1
	// s : 3

	while (!s.empty()) {
		answer[s.top()] = -1;
		s.pop();
	}

	for (int i = 0; i < N; i++) {
		cout << answer[i] << ' ';
	}
	cout << '\n';
	return 0;
}