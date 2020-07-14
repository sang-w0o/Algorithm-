#include <iostream>
using namespace std;

#define MAX 100001
// position : �Է����� ���� ������ȸ�� ����� ������ inOrder�迭����
// �� ���Ұ� �� ��° index�� ����Ǿ� �ִ����� ����Ѵ�. 
int position[MAX];
// inOrder : �Է����� �־����� ������ȸ�� ����� �����ϴ� �迭 
int inOrder[MAX];
// postOrder : �Է����� �־����� ������ȸ�� ����� �����ϴ� �迭 
int postOrder[MAX];

// inOrderStart : inOrder���� �� �迭�� ���� index ( = 0)
// inOrderEnd : inOrder���� �� �迭�� ������ index ( = n-1)
// postOrderStart : postOrder���� �� �迭�� ���� index ( = 0)
// postOrderEnd : postOrder���� �� �迭�� ������ index ( = n-1)
// �� ������ root�������� ���� subtree, ������ subtree�� �����ؼ� ���ȣ���ϱ� ���� ���ȴ�. 
void solve(int inOrderStart, int inOrderEnd, int postOrderStart, int postOrderEnd) {
	if(inOrderStart > inOrderEnd || postOrderStart > postOrderEnd) {
		return;
	}
	
	// root�� �׻� postOrder�� ����� �������̴�. 
	int root = postOrder[postOrderEnd];
	cout << root << " ";
	
	// p�� inOrder�迭���� root�� ��ġ�� index�� �����Ѵ�. 
	int p = position[root];
	
	// left : root ���� ���� subtree�� ����Ų��.
	// ���� subtree�� inOrder �迭���� root���� ���ʿ� �ִ� ���� ������ Ʈ�� �̴�. 
	int left = p - inOrderStart;
	
	// p - 1 : root���� ���ʱ��� ��ȸ�ؾ� �ϱ� ����
	// postOrder+left-1 : �� ���� root�� ���� subtree�� �����ϴ� ���ҵ��� index���� ������ �����̴�. 
	solve(inOrderStart, p-1, postOrderStart, postOrderStart+left-1);
	
	// p + 1 : root���� ������ subtree�� �����ϱ� ����.
	// postOrderStart + left : ���������� root���� ������ subtree�� �����ϱ� ����. 
	// postOrderEnd - 1 : �迭�� 0-base�̱� ������ -1�� ���ش�. 
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
	
	// 0 : inOrder�迭�� ���� index
	// n-1 : inOrder�迭�� �� index
	// 0 : postOrder�迭�� ���� index
	// n-1 : inOrder�迭�� �� index 
	solve(0,n-1,0,n-1);
	
}
