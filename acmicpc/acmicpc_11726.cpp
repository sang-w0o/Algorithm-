#include <iostream>
using namespace std;

// D[n]을 2xn 직사각형을 채우는 방법의 수 라고 하자.
// 2xn 직사각형이 있을 때, 가장 오른쪽에 타일을 놓는 방법은
// 세로로 1개 놓는 것과 가로로 2개 놓는 2가지의 방법이 있다.
// Dynamic Programming은 문제를 한 가지(더 이상 작은 문제로 불가)와 나머지 단계로 구분하는데,
// '한 가지'를 가장 오른쪽에 블록을 넣는 것이라 하자.
// 만약 세로로 1개 놓는 것을 제외한다면 나머지 크기는 2x(n-1)이 되고, 이때 경우의 수는 D[n-1] 이다.
// 만약 가로로 2개 놓는 것을 제외한다면 나머지 크기는 2x(n-2)이 되고, 이때 경우의 수는 D[n-2] 이다.
// 이때, 점화식이 등장하는데, 바로 D[n] = D[n-1] + D[n-2] 이다.

int d[1001];

void makeArray(int n) {
	d[0] = 0;
	d[1] = 1;
	d[2] = 2;

	for (int i = 3; i <= n; i++) {
		d[i] = (d[i - 1] + d[i - 2]) % 10007;
	}

}

int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int N;
	cin >> N;

	makeArray(N);

	cout << d[N] << '\n';
}