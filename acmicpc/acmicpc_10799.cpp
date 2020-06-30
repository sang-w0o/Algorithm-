#include <iostream>
#include <string>
#include <stack>
using namespace std;

int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	string a;
	cin >> a;

	int count = 0;
	stack<int> s;
	// index�� �ֱ� ���� int������ �������.
	// �� ������ '('�� �������� ��������, �踷����� ����������
	// �����ϱ� �����̴�.
	for (size_t i = 0; i < a.length(); i++) {
		if (a[i] == '(')
			s.push(i);
		else if (a[i] == ')') {

			if (i - s.top() == 1) {
				// ������ �� ���
				s.pop();
				count += s.size();
			}
			else {
				s.pop();
				count += 1;
			}
		}

	}

	cout << count << '\n';

}