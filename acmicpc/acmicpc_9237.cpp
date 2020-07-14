#include <iostream>
#include <algorithm>
using namespace std;

int max(int a,int b) {
	return (a >= b) ? a : b;
}

int main() {
	
	ios_base::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	
	int N;
	cin >> N;
	
	// cnt = 2 : 묘목 구입 1일 + t의 최소값이 1이므로
	// 1일만에 자라는 나무가 다 자라려면 최소 2일 걸림. 
	int cnt = 2;
	
	int *t = new int[N];
	for(int i = 0; i < N; i++) {
		cin >> t[i];
	}
	
	// t 배열의 원소들을 오름차순으로 정렬
	sort(t, t + N);
	
	// 2 3 3 4
	int res = 0;
	
	// 정렬된 t배열에 대해 큰 값부터 작은값 순으로 for문 돌린다. 
	// 큰 값부터 돌리는 이유 : t값이 가장 큰 묘목부터 먼저 심어야 최고 일수가 나온다.
	// cnt++ 하는 이유 : 하루에 한 묘목밖에 심지 못하므로 다음 묘목을 심을 때에는
	// 하루가 증가하기 때문이다. 
	for(int i = N - 1; i >= 0; i--) {
		res = max(res, cnt + t[i]);
		//  
		cnt++;
	}
	
	// i = 3 --> res = max(0, 2 + 4) = 6
	// i = 2 --> res = max(6, 3 + 3) = 6
	// i = 1 --> res = max(6, 4 + 3) = 7
	// i = 0 --> res = max(7, 5 + 2) = 7 
	
	cout << res << '\n';
	delete[] t;
	return 0;
}
