#include <iostream>
#include <string>
#include <stack>
using namespace std;

// 1부터 N까지의 수를 Stack에 넣고, 뽑아 놓음으로 하나의 수열을 만들 수 있다.
// Push하는 순서는 오름차순이다.
// 임의의 수열 A가 있을 때, Stack을 이용해 이 수열을 만들 수 있는지 없는지를 판단하라.
// push연산은 +로, pop연산은 -로 표기하며, 불가능한 경우는 NO로 표기한다.

// ex) A = [4,3,6,8,7,5,2,1] 이라면
// ++++--++-++------ 를 이용해서 만들 수 있다.
// ++++- : 1 2 3 4 까지 push를 4번하고 pop을 1번 (-)하여 4를 만든다.
// pop (-)를 1번 하여 3을 가져온다.
// ++- : 5 6 까지 push하고 pop을 1번하여 6을 가져온다.
// ++-- : 7 8 까지 push하고 8,7을 pop을 2번하여 가져온다.
// ------ : --로 5를 가져오고, ---로 2를, -로 1을 가져온다.

// 접근법
// Stack에 push되는 순서는 오름차순이다.
// pop되는 순서대로 수열 A가 만들어지기 때문에, A의 첫 수부터 순서대로 만들어보면 된다.
// m : Stack에 추가되어야 하는 수
// A[i] : 만들어야 하는 수열 A의 수
// A[i]를 구해야 한다면 Stack에는 1부터 A[i-1]까지 모두 Push가 되어있는 상태여야 한다.

int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	stack<int> s;
	string answer;

	int n;  // 배열 A 원소의 개수
	cin >> n;

	int m = 0;  // m : Stack에 들어간 마지막 숫자

	while (n--) {
		int x;
		cin >> x;
		if (x > m) { // 입력받은 수가 stack에 들어간 마지막 숫자보다 크다면
			while (x > m) {  // m까지 stack에 넣고, 
				s.push(++m);
				answer += '+';
			}
			s.pop();  // m값을 pop한다.
			answer += '-';
		}
		else {  // 입력받은 수가 stack에 들어간 마지막 숫자보다 작거나 같다면
			bool found = false;
			if (!s.empty()) {  // stack이 비어있지 않다면
				int top = s.top();  // 가장 마지막에 들어간 원소를 구한다.
				s.pop();
				answer += '-';
				if (x == top) {
					found = true;
				}
			}
			if (!found) { // 수열이 만들어질 수 없는 경우이면
				cout << "NO" << '\n';
				return 0;
			}
		}
	}

	for (auto x : answer) {
		cout << x << '\n';
	}

	return 0;
}