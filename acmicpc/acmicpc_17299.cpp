#include <iostream>
#include <vector>
#include <stack>
using namespace std;

// 각 숫자의 등장횟수를 저장하는 배열
int freq[1000001];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int N;
	cin >> N;

	vector<int> a(N);
	vector<int> answer(N);

	for (int i = 0; i < N; i++) {
		cin >> a[i];
		freq[a[i]] += 1;
	}

	//예제 입력 : 1 1 2 3 4 2 1

	// a[0] = 1, a[1] = 1, a[2] = 2, a[3] = 3, a[4] = 4, a[5] = 2, a[6] = 1
	// freq[1] = 3, freq[2] = 2, freq[3] = 1, freq[4] = 1

	stack<int> s;
	s.push(0);
	for (int i = 1; i < N; i++) {
		if (s.empty()) {
			s.push(i);
		}
		while (!s.empty() && freq[a[s.top()]] < freq[a[i]]) {
			answer[s.top()] = a[i];
			s.pop();
		}
		s.push(i);
	}

	// i = 1일 때 freq[1] = 3 < freq[1] = 3 -->false --> s : <0,1>
	// i = 2일 때 freq[1] = 3 < freq[2] = 2 -->false --> s : <0,1,2>
	// i = 3일 때 freq[2] = 2 < freq[3] = 1 -->false --> s : <0,1,2,3>
	// i = 4일 때 freq[3] = 1 < freq[4] = 1 -->false --> s : <0,1,2,3,4>
	// i = 5일 때 freq[4] = 1 < freq[2] = 2 -->true
	  // answer[4] = 2, s : <0,1,2,3>
	  // freq[3] = 1 < freq[2] = 2 --> true
	  // answer[3] = 2, s : <0,1,2>
	  // freq[2] = 2 < freq[2] = 2 --> false
	  // s : <0,1,2,5>
	// i = 6일 때 freq[2] = 2 < freq[1] = 3 --> true
	  // answer[5] = 1, s : <0,1,2>
	  // freq[2] = 2 < freq[1] = 3 --> true
	  // answer[2] = 1, s : <0,1>
	  // freq[1] = 3 < freq[1] = 3 --> false
	  // s : <0,1,6>

	while (!s.empty()) {
		answer[s.top()] = -1;
		s.pop();
	}
	// answer[6] = -1
	// answer[1] = -1
	// answer[0] = -1

	for (int i = 0; i < N; i++) {
		cout << answer[i] << ' ';
	}
	cout << '\n';
	return 0;
}