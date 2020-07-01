// 0의 개수는 N!를 소인수 분해를 했을 때,
// 2와 5가 몇개 나오는지 알아야 한다.
// 5의 개수가 항상 2의 개수보다 적기에, 5의 개수만 세어주면 된다.
// N!의 0의 개수 : [N/5] + [N/25] + [N/125] + ...

#include <iostream>
using namespace std;

int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int N;
	cin >> N;

	int count = 0;
	for (int i = 5; i <= N; i *= 5) {
		count += N / i;
	}

	cout << count << '\n';
}