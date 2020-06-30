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
	// index를 넣기 위해 int형으로 만들었다.
	// 그 이유는 '('이 레이저의 시작인지, 쇠막대기의 시작인지를
	// 구분하기 위함이다.
	for (size_t i = 0; i < a.length(); i++) {
		if (a[i] == '(')
			s.push(i);
		else if (a[i] == ')') {

			if (i - s.top() == 1) {
				// 레이저 인 경우
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