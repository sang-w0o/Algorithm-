#include <iostream>
using namespace std;

#define MAX 100001
// position : 입력으로 들어온 중위순회의 결과를 저장한 inOrder배열에서
// 각 원소가 몇 번째 index에 저장되어 있는지를 기록한다. 
int position[MAX];
// inOrder : 입력으로 주어지는 중위순회의 결과를 저장하는 배열 
int inOrder[MAX];
// postOrder : 입력으로 주어지는 후위순회의 결과를 저장하는 배열 
int postOrder[MAX];

// inOrderStart : inOrder값이 들어간 배열의 시작 index ( = 0)
// inOrderEnd : inOrder값이 들어간 배열의 마지막 index ( = n-1)
// postOrderStart : postOrder값이 들어간 배열의 시작 index ( = 0)
// postOrderEnd : postOrder값이 들어간 배열의 마지막 index ( = n-1)
// 위 값들은 root기준으로 왼쪽 subtree, 오른쪽 subtree를 구분해서 재귀호출하기 위해 사용된다. 
void solve(int inOrderStart, int inOrderEnd, int postOrderStart, int postOrderEnd) {
	if(inOrderStart > inOrderEnd || postOrderStart > postOrderEnd) {
		return;
	}
	
	// root는 항상 postOrder의 결과의 마지막이다. 
	int root = postOrder[postOrderEnd];
	cout << root << " ";
	
	// p는 inOrder배열에서 root가 위치한 index를 저장한다. 
	int p = position[root];
	
	// left : root 기준 왼쪽 subtree를 가리킨다.
	// 왼쪽 subtree는 inOrder 배열에서 root보다 왼쪽에 있는 노드로 구성된 트리 이다. 
	int left = p - inOrderStart;
	
	// p - 1 : root보다 왼쪽까지 순회해야 하기 때문
	// postOrder+left-1 : 이 값은 root의 왼쪽 subtree를 구성하는 원소들의 index값의 마지막 범위이다. 
	solve(inOrderStart, p-1, postOrderStart, postOrderStart+left-1);
	
	// p + 1 : root기준 오른쪽 subtree를 조사하기 위함.
	// postOrderStart + left : 마찬가지로 root기준 오른쪽 subtree를 조사하기 위함. 
	// postOrderEnd - 1 : 배열이 0-base이기 때문에 -1을 해준다. 
	solve(p+1, inOrderEnd, postOrderStart + left, postOrderEnd-1);
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	
	int n;
	cin >> n;
	
	for(int i = 0; i < n; i++) {
		cin >> inOrder[i];
	}
	
	for(int i = 0; i < n; i++) {
		cin >> postOrder[i];
	}
	
	for(int i = 0; i < n; i++) {
		position[inOrder[i]] = i;
	}
	
	// 0 : inOrder배열의 시작 index
	// n-1 : inOrder배열의 끝 index
	// 0 : postOrder배열의 시작 index
	// n-1 : inOrder배열의 끝 index 
	solve(0,n-1,0,n-1);
	
}
