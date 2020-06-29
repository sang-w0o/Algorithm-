#include <iostream>
#include <stack>
#include <string>
using namespace std;

// ��ȣ ���ڿ��� �־����� ��, �ùٸ��� ������ ���� ��ȣ ���ڿ������� Ȯ���϶�.
// ��ȣ ���ڿ� : ( )�θ� �̷���� ���ڿ�
// �ùٸ� ��ȣ ���ڿ� : ��ȣ�� ���� �ùٸ� ���ڿ�, ex : (), (()) (), (((())))

// Stack�� ����Ͽ� �Է� ���ڿ����� '('�� ������ push�ϰ�,
// �Է� ���ڿ����� ')'�� ������ pop�� �Ͽ� '('���� Ȯ���Ѵ�.
// Stack�� �ִ� '(' ���� �տ� ������ ¦�� �ȸ´� ��ȣ���̴�.

// �� ���������� �ܼ��� ( �� )�� ������ ���� �ǹǷ�
// Stack �ڷᱸ���� ��������� �ʾ�����, ���� �ǹ̷� �����ߴ�.

int isValid(string s) {
	int cnt = 0; // Stack�� ũ�� �ǹ�
	for (size_t i = 0; i < s.size(); i++) {
		if (s[i] == '(') {
			++cnt; // '('�� ������ Stack�� ũ�� 1 ����
		}
		else {
			cnt -= 1;  // ')'�� ������ Stack�� ũ�� 1 ����
		}
		if (cnt < 0) {  // '(' ���� ')'�� ������ �ùٸ� ��ȣ���ڿ��� �ƴϴ�.
			return -1;
		}
	}

	if (cnt == 0) {  // '('�� ')' �� ������ ��ġ�ϸ� �ùٸ� ��ȣ ���ڿ��̴�.
		return 0;
	}
	else {  // '('�� ')'�� ���� ��ġ���� ������ �ùٸ� ��ȣ���ڿ��� �ƴϴ�.
		return -1;
	}
}
int main() {
	
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	string input;
	getline(cin, input);

	if (isValid(input) == 0) {
		cout << "true";
	}
	else {
		cout << "false";
	}
	return 0;
	
}