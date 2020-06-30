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
			// �±װ� �����ϸ� �տ� �ִ� �͵��� �������� ����Ѵ�.
			print(s);
			isTag = true;
			cout << ch;
		}
		else if (ch == '>') {
			isTag = false;
			cout << ch;
		}
		else if(isTag){
			// �±� ������ ������ �ƴ� �������� ����Ѵ�.
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