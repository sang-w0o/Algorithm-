#include <iostream>
#include <string>
using namespace std;

typedef struct Stack {
	int data[10000];
	int ptr;
	Stack() {
		ptr = 0;
	}
	void push(int a) {
		data[ptr] = a;
		ptr += 1;
	}
	bool empty() {
		if (ptr == 0)
			return true;
		else
			return false;
	}
	int pop() {
		if (empty()) {
			return -1;
		}
		return data[--ptr];
	}
	int top() {
		if (empty()) {
			return -1;
		}
		return data[ptr - 1];
	}
	int size() {
		return ptr;
	}
}Stack;

int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int n;
	cin >> n;

	Stack s;

	while (n--) {
		string cmd;
		cin >> cmd;
		if (cmd == "push") {
			int num;
			cin >> num;
			s.push(num);
		}
		else if (cmd == "pop") {
			if (s.empty()) {
				cout << -1 << '\n';
			}
			else {
				cout << s.top() << '\n';
				s.pop();
			}
		}
		else if (cmd == "size") {
			cout << s.size() << '\n';
		}
		else if (cmd == "empty") {
			if (s.empty()) {
				cout << 1 << '\n';
			}
			else {
				cout << 0 << '\n';
			}
		}
		else if (cmd == "top") {
			cout << s.top() << '\n';
		}
	}
	return 0;
}