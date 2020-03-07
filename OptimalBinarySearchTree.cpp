/* This is Optimal Binary Search Tree Algoritm implemented in C++.
	Array P contains the probability that each key is the search key. (Size : n)
	Array A contains the optimal value that minimized the tree.
	In the array R, R[i][j] is the index of the element of the Optimal binary search tree
	that inclues the elements from the i-th to the j-th.
	*/

#include <iostream>

class Tree {
private:
	int n;
	float* P;
	float** A;
	int** R;
	float minavg;
public:
	Tree(int n = 0);
	~Tree();
	void insert_P();
	void showArray_P();
	void showArray_A();
	void showArray_R();
	void optsearchtree(int n, const float* P, float& minavg, int** R);
	void call_optsearchtree();
	float sum(int start_Index, int end_Index);
};

int** make_int_2DArray(int n);
float** make_float_2DArray(int n);

Tree::Tree(int n) {
	this->n = n;
	P = new float[n+1];
	A = make_float_2DArray(n+2);
	R = make_int_2DArray(n+2);
	minavg = 0.0;
}

Tree::~Tree() {
	for (int i = 0; i <= n+1; i++) {
		delete[] A[i];
		delete[] R[i];
	}
	delete[] P; 
	delete[] A; 
	delete[] R;
}

void Tree::insert_P() {
	std::cout << std::endl << std::endl;
	std::cout << "Enter the probability of each elements being a search key (Number of elements : " << n << " ) : ";
	for (int i = 1; i <= n; i++) {
		std::cin >> P[i];
	}
}

void Tree::showArray_P() {
	std::cout << std::endl << std::endl;
	std::cout << "======= < P > =======" << std::endl;
	for (int i = 1; i <= n; i++)
		std::cout << P[i] << "   ";
}

void Tree::showArray_A() {
	std::cout << std::endl << std::endl;
	std::cout << "======= < A > =======" << std::endl;
	for (int i = 1; i <= n; i++) {
		for (int j = 0; j <= n; j++) {
			std::cout << A[i][j] << "\t";
		}
		std::cout << std::endl;
	}
}

void Tree::showArray_R() {
	std::cout << std::endl << std::endl;
	std::cout << "======= < R > =======" << std::endl;
	for (int i = 1; i <= n; i++) {
		for (int j = 0; j <= n; j++) {
			std::cout << R[i][j] << "\t";
		}
		std::cout << std::endl;
	}
}

void Tree::optsearchtree(int n, const float* P, float& minavg, int** R) {
	int i, j, k, diagonal;

	for (i = 1; i <= n; i++) {
		A[i][i - 1] = 0.0;
		A[i][i] = P[i];
		R[i][i] = i;
		R[i][i - 1] = 0;
	}

	A[n + 1][n] = 0.0;
	R[n + 1][n] = 0;

	for (diagonal = 1; diagonal <= n - 1; diagonal++) {
		for (i = 1; i <= n - diagonal; i++) {
			j = i + diagonal;
			A[i][j] = 10000.0;
			for (k = i; k <= j; k++) {
				float min = A[i][k - 1] + A[k + 1][j] + sum(i, j);
				if (min < A[i][j]) {
					A[i][j] = min;
					R[i][j] = k;
				}
			}
		}
	}
	minavg = A[1][n];
}

void Tree::call_optsearchtree() {
	optsearchtree(n, P, minavg, R);
}

float Tree::sum(int start_Index, int end_Index) {
	float temp = 0.0;
	for (int i = start_Index; i < end_Index+1 ; i++) {
		temp += P[i];
	}
	return temp;
}

int** make_int_2DArray(int n) {
	int** temp = new int*[n];
	for (int i = 0; i < n; i++) {
		temp[i] = new int[n];
		memset(temp[i], 0, sizeof(int)*n);
	}
	return temp;
}

float** make_float_2DArray(int n) {
	float** temp = new float*[n];
	for (int i = 0; i < n; i++) {
		temp[i] = new float[n];
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			temp[i][j] = 0.0;
		}
	}

	return temp;
}

int main() {
	int n;
	std::cout << "Enter the number of elements : ";
	std::cin >> n;
	Tree A = Tree(n);

	A.insert_P();

	A.call_optsearchtree();

	A.showArray_P();

	A.showArray_A();

	A.showArray_R();

	return 0;
}