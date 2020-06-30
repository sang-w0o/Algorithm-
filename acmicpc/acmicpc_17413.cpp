#include <iostream>
#include <stack>
#include <string>
using namespace std;

void print(stack<char> &s) {

	while (!s.empty()) {
		cout << s.top();
		s.pop();
	}
}

int main() {

	string input;
	getline(cin, input);

	stack<char> s;
	
	bool isTag = false;

	for (char ch : input) {
		if (ch == '<') {
			// 태그가 시작하면 앞에 있는 것들을 역순으로 출력한다.
			print(s);
			isTag = true;
			cout << ch;
		}
		else if (ch == '>') {
			isTag = false;
			cout << ch;
		}
		else if(isTag){
			// 태그 내용은 역순이 아닌 정순으로 출력한다.
			cout << ch;
		}
		else {
			if (ch == ' ') {
				cout << ch;
			}
			else
				s.push(ch);
		}
	}

	print(s);
	cout << '\n';
	return 0;
}