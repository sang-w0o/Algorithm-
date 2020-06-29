#include <iostream>
#include <stack>
#include <string>
using namespace std;

// 괄호 문자열이 주어졌을 때, 올바르게 열리고 닫힌 괄호 문자열인지를 확인하라.
// 괄호 문자열 : ( )로만 이루어진 문자열
// 올바른 괄호 문자열 : 괄호의 쌍이 올바른 문자열, ex : (), (()) (), (((())))

// Stack을 사용하여 입력 문자열에서 '('가 나오면 push하고,
// 입력 문자열에서 ')'가 나오면 pop을 하여 '('인지 확인한다.
// Stack에 있는 '(' 들은 앞에 있으며 짝이 안맞는 괄호들이다.

// 이 문제에서는 단순히 ( 와 )의 개수만 세면 되므로
// Stack 자료구조를 사용하지는 않았지만, 같은 의미로 구현했다.

int isValid(string s) {
	int cnt = 0; // Stack의 크기 의미
	for (size_t i = 0; i < s.size(); i++) {
		if (s[i] == '(') {
			++cnt; // '('가 들어오면 Stack의 크기 1 증가
		}
		else {
			cnt -= 1;  // ')'가 들어오면 Stack의 크기 1 감소
		}
		if (cnt < 0) {  // '(' 보다 ')'가 많으면 올바른 괄호문자열이 아니다.
			return -1;
		}
	}

	if (cnt == 0) {  // '('와 ')' 의 개수가 일치하면 올바른 괄호 문자열이다.
		return 0;
	}
	else {  // '('와 ')'의 수가 일치하지 않으면 올바른 괄호문자열이 아니다.
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