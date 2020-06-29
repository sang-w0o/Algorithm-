#include <iostream>
#include <string>
#include <stack>
using namespace std;


// 문장이 주어졌을 때 단어를 모두 뒤집는다.
// 단어의 순서를 바꿀 수 없고, 단어는 모두 영어 알파벳으로 이뤄져 있다.
// 단어와 단어는 공백으로 구분된다.
// 단어의 최대 길이 : 20, 문장의 최대 길이 : 100

// Stack 사용!

int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int t;  // 단어의 개수 t
	cin >> t;

	// std::cin은 개행문자를 버퍼에 남겨둔다.
	// getline() 함수는 이전의 개행 다음 부터 들어온 문자열을 읽는다.
	// 따라서 처음에 t를 입력받고, 최초로 getline을 실행하면 읽어들이는 문자가 없는데,
	// 이를 방지하기 위해 아래의 ignore 함수를 수행한다.
	cin.ignore();

	while (t--) {
		string str;
		getline(cin, str);  // 단어 입력 받기
		str += '\n';  // 단어 뒤에 개행 추가
		stack<char> s;
		for (char ch : str) {
			if (ch == ' ' ||ch  == '\n') {
				while (!s.empty()) {
					cout << s.top();
					s.pop();
				}
				cout << ch;
			}
			else {
				s.push(ch);
			}
		}
	}
	return 0;
}

// 시간복잡도 : O(n)
