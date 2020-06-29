#include <cstdio>
#include <queue>
using namespace std;

// 1번부터 N번까지 N명의 사람이 원을 이루며 앉아있고, 
// 양의 정수 M(<=N)이 주어진다.
// 순서대로 M번째 사람을 제거하고, 한 사람이 제거되면
// 남은 사람들로 이뤄진 원을 따라 이 과정을 계속해간다.
// 이 과정은 N명의 사람들이 모두 제거될 때 까지 계속된다.
// ex) N = 7, M = 3이면
// 3번 제거 ==> 4,5,6에서 6번 제거 ==> 7,1,2 에서 2번 제거 ==> 7제거 ==>
// 5 제거 ==>1제거 ==> 4제거 (끝)
// 원에서 사람들이 제거되는 순서를 (N,M) - 조세퍼스 순열이라 한다.

int main() {

	int N, M;
	scanf("%d %d", &N, &M);
	queue<int> q;

	// 1번부터 N번까지의 사람(원소)를 큐에 삽입
	for (int i = 1; i <= N; i++) {
		q.push(i);
	}

	printf("<");

	for (int i = 0; i < N - 1; i++) {
		for (int j = 0; j < M - 1; j++) {
			// queue에 가장 마지막에 있는 원소를 queue의 처음으로 삽입
			q.push(q.front());
			q.pop();
		}
		// 제거된 사람의 번호를 출력하고 꺼낸다.
		printf("%d, ", q.front());
		q.pop();
	}
	printf("%d>\n", q.front());
	return 0;
}