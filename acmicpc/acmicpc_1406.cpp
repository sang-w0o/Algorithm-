#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <cstring>
#include <stack>
using namespace std;

// 커서 : 문장의 맨 앞, 맨 뒤, 문장 중간 임의의 곳에 위치할 수 있다.
// L : 커서를 왼쪽으로 한칸 옮김
// D : 커서를 오른쪽으로 한칸 옮김
// B : 커서 왼쪽에 있는 문자를 삭제함
// P $ : $라는 문자를 커서 오른쪽에 추가함, 커서는 $에 위치

// B 연산은 커서의 왼쪽 문자를 삭제하고, P연산은 커서 왼쪽 뒤에 문자를 추가한다.
// 이 특징을 이용해 Stack을 사용할 수 있다.

// 커서를 기준으로 왼쪽 stack(left)와 오른쪽 스택(right)로 나눠보자.

// Stack을 사용하면 모든 연산이 O(1) 이 된다.
// (push, pop만 수행하기 때문)

char a[600000];

int main() {
	scanf("%s", a);
	stack<char> left, right;

	size_t n = strlen(a);  // 입력받은 문자열의 길이
	for (size_t i = 0; i < n; i++) {
		left.push(a[i]);
	}

	int m;  // 명령의 개수
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