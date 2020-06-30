#include <iostream>
#include <stack>
#include <vector>
using namespace std;

int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int N;
	cin >> N;

	vector<int> a(N);
	vector<int> answer(N);

	// N개의 수 입력받아서 a에 삽입
	for (int i = 0; i < N; i++) {
		cin >> a[i];
	}
	stack<int> s;

	// 5, 2, 7이 있다고 하자. 2의 오큰수는 7 이고, 
	// 5의 오큰수도 7이다.
	// 만약 5, 6, 7이 있다면 6의 오큰수는 7이지만,
	// 5의 오큰수는 6이 된다.
	// 어떤 수의 오큰수가 7이라는 것은 그 수와 7 사이에
	// 7보디 큰 수가 없다는 뜻이다.

	// 이 성질을 이용해서 스택을 사용하면,
	// 스택의 가장 위(top)에 있는 수 보다 큰 값이 들어오게 되면
	// 그 수가 바로 오큰수가 된다.
	// 오큰수를 찾은 수는 스택에서 바로 pop한다.

	s.push(0);
	for (int i = 1; i < N; i++) {
		if (s.empty()) {
			s.push(i);
		}
		while (!s.empty() && a[s.top()] < a[i]) {
			answer[s.top()] = a[i];
			s.pop();
		}
		s.push(i);
	}

	// a[0] = 3, a[1] = 5, a[2] = 2, a[3] = 7
	// answer : [0] : 5, [1] : 7, [2] : 7, [3] : -1
	// s : 3

	while (!s.empty()) {
		answer[s.top()] = -1;
		s.pop();
	}

	for (int i = 0; i < N; i++) {
		cout << answer[i] << ' ';
	}
	cout << '\n';
	return 0;
}