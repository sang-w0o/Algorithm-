#include <iostream>
#include <string>
#include <stack>
using namespace std;


// ������ �־����� �� �ܾ ��� �����´�.
// �ܾ��� ������ �ٲ� �� ����, �ܾ�� ��� ���� ���ĺ����� �̷��� �ִ�.
// �ܾ�� �ܾ�� �������� ���еȴ�.
// �ܾ��� �ִ� ���� : 20, ������ �ִ� ���� : 100

// Stack ���!

int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int t;  // �ܾ��� ���� t
	cin >> t;

	// std::cin�� ���๮�ڸ� ���ۿ� ���ܵд�.
	// getline() �Լ��� ������ ���� ���� ���� ���� ���ڿ��� �д´�.
	// ���� ó���� t�� �Է¹ް�, ���ʷ� getline�� �����ϸ� �о���̴� ���ڰ� ���µ�,
	// �̸� �����ϱ� ���� �Ʒ��� ignore �Լ��� �����Ѵ�.
	cin.ignore();

	while (t--) {
		string str;
		getline(cin, str);  // �ܾ� �Է� �ޱ�
		str += '\n';  // �ܾ� �ڿ� ���� �߰�
		stack<char> s;
		for (char ch : str) {
			if (ch == ' ' ||ch  == '\n') {
				while (!s.empty()) {
					cout << s.top();
					s.pop();
				}
				cout << ch;
			}
			else {
				s.push(ch);
			}
		}
	}
	return 0;
}

// �ð����⵵ : O(n)
