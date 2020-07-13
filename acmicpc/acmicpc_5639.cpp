#include <iostream>
using namespace std;

typedef struct Node {
	int data;
	struct Node *left;
	struct Node *right;
} Node;

// ���� ��ȸ�� ����->������->��Ʈ ������� �湮�Ѵ�.
// ���� �Ʒ��� ���� ���ȣ���� ���ش�. 
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
		
		// root�� ���� ������� �Ǵ��ϰ�, ���ٸ� ó�� ���� data��
		// data�� ������ ��带 root�� �����Ѵ�. 
		if(root == NULL) {
			root = node;
		}
		// root node�� �̹� �����Ѵٸ� 
		else {
			Node *curNode = root;
			Node *prev;
			while(true) {
				// �Է¹��� data�� curNode�� data���� ũ�ٸ�
				// curNode���� ������ �ڽ� ���� �����ؾ� �Ѵ�. 
				if(data > curNode->data) {
					prev = curNode;
					
					// �̹� curNode�� ������ �ڽ� ��尡 �ִ����� ������ �˻��Ѵ�.
					// curNode�� ������ �ڽ� ��尡 ���ٸ� �״�� �����Ѵ�. 
					if(curNode->right != NULL) {
						curNode = curNode->right;
					}
					// curNode�� ������ �ڽ��� �����Ѵٸ� 
					else {
						curNode->right = node;
						break;
					}
				}
				// curNode ���� ���� �ڽ� ���� �����ؾ��ϴ� ���
				// ��, �θ� ��庸�� ���� ���� ���Դٸ� 
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
