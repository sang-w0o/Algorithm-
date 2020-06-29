#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <cstring>
#include <stack>
using namespace std;

// Ŀ�� : ������ �� ��, �� ��, ���� �߰� ������ ���� ��ġ�� �� �ִ�.
// L : Ŀ���� �������� ��ĭ �ű�
// D : Ŀ���� ���������� ��ĭ �ű�
// B : Ŀ�� ���ʿ� �ִ� ���ڸ� ������
// P $ : $��� ���ڸ� Ŀ�� �����ʿ� �߰���, Ŀ���� $�� ��ġ

// B ������ Ŀ���� ���� ���ڸ� �����ϰ�, P������ Ŀ�� ���� �ڿ� ���ڸ� �߰��Ѵ�.
// �� Ư¡�� �̿��� Stack�� ����� �� �ִ�.

// Ŀ���� �������� ���� stack(left)�� ������ ����(right)�� ��������.

// Stack�� ����ϸ� ��� ������ O(1) �� �ȴ�.
// (push, pop�� �����ϱ� ����)

char a[600000];

int main() {
	scanf("%s", a);
	stack<char> left, right;

	size_t n = strlen(a);  // �Է¹��� ���ڿ��� ����
	for (size_t i = 0; i < n; i++) {
		left.push(a[i]);
	}

	int m;  // ����� ����
	scanf("%d", &m);
	while (m--) {
		char what;
		scanf(" %c", &what);
		if (what == 'L') {
			if (!left.empty()) {
				right.push(left.top());
				left.pop();
			}
		}
		else if (what == 'D') {
			if (!right.empty()) {
				left.push(right.top());
				right.pop();
			}
		}
		else if (what == 'B') {
			if (!left.empty()) {
				left.pop();
			}
		}
		else if (what == 'P') {
			char c;
			scanf(" %c", &c);
			left.push(c);
		}
	}

	while (!left.empty()) {
		right.push(left.top());
		left.pop();
	}

	while (!right.empty()) {
		printf("%c", right.top());
		right.pop();
	}

	printf("\n");
	return 0;
}