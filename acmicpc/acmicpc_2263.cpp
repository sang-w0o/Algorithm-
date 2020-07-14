#include <iostream>
using namespace std;

typedef struct Node {
	int data;
	struct Node *left;
	struct Node *right;
}Node;

void preOrder(Node *parent) {
	if(parent != NULL) {
		cout << parent->data << " ";
		preOrder(parent->left);
		preOrder(parent->right);
	}
}


int main() {
	
	ios_base::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	
	int n;
	cin >> n;
	
	int *inOrder = new int[n+1];
	int *postOrder = new int[n+1];
	
	for(int i = 1; i <= n; i++) {
		cin >> inOrder[i];
	}
	
	for(int i = n; i >= 1; i--) {
		cin >> postOrder[i];
	}
	
//	Node *root = new Node;
//	root->data = postOrder[1];
//	root->left = NULL;
//	root->right = NULL;
	Node *root = NULL;
	
	for(int i = 1; i <= n; i++) {
		Node *node = new Node;
		node->data = postOrder[i];
		node->left = NULL;
		node->right = NULL;
		
		if(root == NULL) {
			root = node;
		}
		else {
			Node *curNode = root;
			Node *prev;
			while(true) {
				if(postOrder[i] > curNode->data) {
					prev = curNode;
					if(curNode->right != NULL) {
						curNode = curNode->right;
					}
					else {
						curNode->right = node;
						break;
					}
				}
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
	
	//cout << root->data << " ";
	preOrder(root);
	cout << '\n';
	delete[] inOrder;
	delete[] postOrder;
	return 0;
}
