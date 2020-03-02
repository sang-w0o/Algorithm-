/*  This is Floyd's Shortest Path Algorithm implemented in C++.
	Input : (1)Weighted Digraph W, integer n(number of vertices of W).
			   (If there is no direct edge(weight) between vertices, enter 100.)
			    (2) The index of 2 vertices that the user desires to know the shortest path. 
	Output : (1)Array D that shows the minimum weight of the shortest path,
				   (2)Array P that shows the biggest index of a vertex that is in the 
				   shortest path.
				   (3) The shortest path (route) of which user inserted.
*/

#define MAX 100

#include <iostream>

class Matrix {
private:
	int** W;
	int** D;
	int** P;
	int n;
	int Src_index, Dest_index;
public:
	Matrix(int n = 0);
	~Matrix();
	void floyd(int n, int** W, int** D, int** P);
	void call_floyd();
	void path(int Src_index, int Dest_index);
	void insertPathSrcDestIndex();
	void call_path();
	void insertWeight();
	void showArrayW();
	void showArrayD();
	void showArrayP();
};

int** make2DArray(int n);

Matrix::Matrix(int n) {
	this->n = n;
	this->Src_index = 0;
	this->Dest_index = 0;
	W = make2DArray(n);
	D = make2DArray(n);
	P = make2DArray(n);
}

Matrix::~Matrix() {
	for (int i = 0; i < n; i++) {
		delete[] W[i];
		delete[] D[i];
		delete[] P[i];
	}
	delete[] W;
	delete[] D;
	delete[] P;
}

void Matrix::floyd(int n, int** W, int** D, int** P) {
	int i, j, k;
	for (i = 0; i < n; i++) {
		for (j = 0; j < n; j++) {
			D[i][j] = W[i][j];
		}
	}
	for (k = 0; k < n; k++) {
		for (i = 0; i < n; i++) {
			for (j = 0; j < n; j++) {
				if (D[i][k] + D[k][j] < D[i][j]) {
					P[i][j] = k+1;
					D[i][j] = D[i][k] + D[k][j];
				}
			}
		}
	}
}

void Matrix::call_floyd() {
	floyd(n, W, D, P);
}

void Matrix::path(int Src_index, int Dest_index) {
	if (P[Src_index - 1][Dest_index - 1] != 0) {
		path(Src_index, P[Src_index - 1][Dest_index - 1]);
		std::cout << "V" << P[Src_index - 1][Dest_index - 1] << "\t";
		path(P[Src_index - 1][Dest_index - 1], Dest_index);
	}
}

void Matrix::insertPathSrcDestIndex() {
	std::cout << std::endl << std::endl;
	std::cout << "Enter the start vertex(index) number : ";
	std::cin >> Src_index;
	std::cout << "Enter the Destination vertex(index) number : ";
	std::cin >> Dest_index;
}

void Matrix::call_path() {
	std::cout << std::endl << std::endl;
	std::cout << "This is the shortest path route from V" << Src_index << " to V" << Dest_index << "." << std::endl;
	path(Src_index, Dest_index);
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

void Matrix::showArrayW() {
	std::cout << std::endl << std::endl;

	int i, j;
	
	std::cout << "======= < W > =======" << std::endl;
	for (i = 0; i < n; i++) {
		for (j = 0; j < n; j++) {
			if (W[i][j] == MAX)
				std::cout << "INF" << "\t";
			else
				std::cout << W[i][j] << "\t";
		}
		std::cout << std::endl;
	}
}

void Matrix::showArrayD() {
	std::cout << std::endl << std::endl;

	int i, j;

	std::cout << "======= < D > =======" << std::endl;
	for (i = 0; i < n; i++) {
		for (j = 0; j < n; j++) {
			std::cout << D[i][j] << "\t";
		}
		std::cout << std::endl;
	}
}

void Matrix::showArrayP() {
	std::cout << std::endl << std::endl;

	int i, j;

	std::cout << "======= < P > =======" << std::endl;
	for (i = 0; i < n; i++) {
		for (j = 0; j < n; j++) {
			std::cout << P[i][j] << "\t";
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

int main() {
	int n;
	std::cout << "Enter the number of vertices : ";
	std::cin >> n;

	Matrix A = Matrix(n);

	A.insertWeight();

	A.call_floyd();

	A.showArrayW();
	A.showArrayD();
	A.showArrayP();

	A.insertPathSrcDestIndex();
	A.call_path();

	std::cout << std::endl << std::endl;

	return 0;
}