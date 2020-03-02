/* This is Floyd's Shortest Path Algorithm implemented in C++.
	Input : Weighted Digraph W, integer n(number of vertices of W).
	(If there is no direct edge(weight) between vertices, enter 100.)
	Output : Array D that shows the minimum weight of the shortest path.*/

#define MAX 100

#include <iostream>

class Matrix {
private:
	int** W;
	int** D;
	int n;
public:
	Matrix(int n = 0);
	~Matrix();
	void floyd(int n, int** W, int** D);
	void insertWeight();
	void call_floyd();
	void printResult();
};

int** make2DArray(int n);
int minimum(int comp1, int comp2);

Matrix::Matrix(int n) {
	this->n = n;
	W = make2DArray(n);
	D = make2DArray(n);
}

Matrix::~Matrix() {
	for (int i = 0; i < n; i++) {
		delete[] W[i];
		delete[] D[i];
	}
	delete[] W;
	delete[] D;
}

void Matrix::floyd(int n, int** W, int** D) {
	int i, j, k;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			D[i][j] = W[i][j];
		}
	}

	for (k = 0; k < n; k++) {
		for (i = 0; i < n; i++) {
			for (j = 0; j < n; j++) {
				D[i][j] = minimum(D[i][j], D[i][k] + D[k][j]);
			}
		}
	}
}

void Matrix::insertWeight() {
	std::cout << std::endl << std::endl;
	std::cout << "Enter the weights of each vertex to vertex (size : " << n << "*" << n << ")" << std::endl;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			std::cin >> W[i][j];
		}
	}
}

void Matrix::call_floyd() {
	floyd(n, W, D);
}

void Matrix::printResult() {
	std::cout << std::endl << std::endl;

	std::cout << "======= < W > =======" << std::endl;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (W[i][j] == MAX) {
				std::cout << "INF" << "\t";
			}
			else {
				std::cout << W[i][j] << "\t";
			}
		}
		std::cout << std::endl;
	}

	std::cout << "======= < D > =======" << std::endl;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			std::cout << D[i][j] << "\t";
		}
		std::cout << std::endl;
	}
}

int** make2DArray(int n) {
	int** temp = new int*[n];
	for (int i = 0; i < n; i++) {
		temp[i] = new int[n];
		memset(temp[i], 0, sizeof(int)*n);
	}
	return temp;
}

int minimum(int comp1, int comp2) {
	if (comp1 < comp2)
		return comp1;
	else
		return comp2;
}

int main() {
	int n;
	std::cout << "Enter the number of vertices : ";
	std::cin >> n;

	Matrix A = Matrix(n);

	A.insertWeight();

	A.call_floyd();

	A.printResult();

	return 0;
}
