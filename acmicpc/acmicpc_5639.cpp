#include <iostream>
using namespace std;

typedef struct Node {
	int data;
	struct Node *left;
	struct Node *right;
} Node;

// 후위 순회는 왼쪽->오른쪽->루트 순서대로 방문한다.
// 따라서 아래와 같이 재귀호출을 해준다. 
void postOrder(Node *parent) {
	if(parent != NULL) {
		postOrder(parent->left);
		postOrder(parent->right);
		cout << parent->data << '\n';
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	
	int data = 0;
	Node *root = NULL;
	
	while(cin >> data) {
		Node *node = new Node;
		node->data = data;
		node->left = NULL;
		node->right = NULL;
		
		// root가 없는 노드인지 판단하고, 없다면 처음 들어온 data를
		// data로 가지는 노드를 root로 설정한다. 
		if(root == NULL) {
			root = node;
		}
		// root node가 이미 존재한다면 
		else {
			Node *curNode = root;
			Node *prev;
			while(true) {
				// 입력받은 data가 curNode의 data보다 크다면
				// curNode기준 오른쪽 자식 노드로 삽입해야 한다. 
				if(data > curNode->data) {
					prev = curNode;
					
					// 이미 curNode가 오른쪽 자식 노드가 있는지의 유무를 검사한다.
					// curNode에 오른쪽 자식 노드가 없다면 그대로 삽입한다. 
					if(curNode->right != NULL) {
						curNode = curNode->right;
					}
					// curNode의 오른쪽 자식이 존재한다면 
					else {
						curNode->right = node;
						break;
					}
				}
				// curNode 기준 왼쪽 자식 노드로 삽입해야하는 경우
				// 즉, 부모 노드보다 작은 값이 들어왔다면 
				else {
					prev = curNode;
					if(curNode->left != NULL) {
						curNode = curNode->left;
					}
					else {
						curNode->left = node;
						break;
					}
				}
			}
		}
	}
	
	postOrder(root);
	return 0;
}
