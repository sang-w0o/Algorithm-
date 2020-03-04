/* This is Chained Matrix Minimal Multiplication Algorithm implemented in C++.
(1) Function minmult
	Input :
	(1) Integer n(Number of matrices)
	(2) Array d[n](Size of column of each Matrix.)
	Output : 
	(1) Array P (The array that stores information to get minimum order.)
	   P[i][j] is the point where the array i to array j splits.
(2) Function order
	Input : integer n, array P (Which is made by function minmult).
	Output : Optimized Order
	*/

#include <iostream>

class ChainedMatrix {
private:
	int Src_index;
	int Dest_index;
	int n;
	int** P;
	int* d;
	int** M;
public:
	ChainedMatrix(int n = 0);
	~ChainedMatrix();
	void minmult(int n, int* d, int** P);
	void insertArray_d();
	void call_minmult();
	void showArray_d();
	void showArray_M();
	void showArray_P();
	void order(int i, int j);
	void order_insert();
	void order_start();
};

int** make2DArray(int n);

ChainedMatrix::ChainedMatrix(int n) {
	this->n = n;
	P = make2DArray(n+1);
	d = new int[n+2];
	M = make2DArray(n+1);
	Src_index = 0;
	Dest_index = 0;
}

ChainedMatrix::~ChainedMatrix() {
	for (int i = 0; i < n+1; i++) {
		delete[] P[i];
		delete[] M[i];
	}
	delete[] P; delete[] d; delete[] M;
}

void ChainedMatrix::minmult(int n, int* d, int** P) {
	int i, j, k, diagonal;
	
	for (diagonal = 1; diagonal <= n; diagonal++) {
		for (i =	1; i <= n - diagonal; i++) {  
			j = i + diagonal;
			M[i][j] = 10000;
			for (k = i; k <= j - 1; k++) {
				int min = M[i][k] + M[k + 1][j] + (d[i])*(d[k+1])*(d[j+1]);

				if (min < M[i][j]) {
					M[i][j] = min;
					P[i][j] = k;
				}
			}
		}
	}
	
}

void ChainedMatrix::insertArray_d() {
	std::cout << std::endl << std::endl;
	std::cout << "Enter the size of row and column from the first Matrix : ";
	for (int i = 1; i <= n+1; i++) {
		std::cin >> d[i];
	}
}

void ChainedMatrix::call_minmult() {
	minmult(n, d, P);
}

void ChainedMatrix::showArray_d() {
	std::cout << std::endl << std::endl;
	std::cout << "======== < d > =======" << std::endl;
	for (int i = 1; i <= n+1; i++) {
		std::cout << d[i] << "\t";
	}
	std::cout << std::endl;
}

void ChainedMatrix::showArray_M() {
	std::cout << std::endl << std::endl;

	std::cout << "======= < M > =======" << std::endl;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			std::cout << M[i][j] << "\t";
		}
		std::cout << std::endl;
	}
}

void ChainedMatrix::showArray_P() {
	std::cout << std::endl << std::endl;

	std::cout << "======= < P > =======" << std::endl;
	for (int i = 1; i < n; i++) {
		for (int j = 1; j <= n; j++) {
			std::cout << P[i][j] << "\t";
		}
		std::cout << std::endl;
	}
}

void ChainedMatrix::order(int i, int j) {
	int k;
	if (i == j)
		std::cout << "A" << i;
	else {
		k = P[i][j];
		std::cout << "(";
		order(i,k);
		order(k+1, j);
		std::cout << ")";
	}
}

void ChainedMatrix::order_insert() {
	std::cout << std::endl << std::endl;

	std::cout << "Enter the Source Matrix Number : ";
	std::cin >> Src_index;
	std::cout << "Enter the Destination Matrix Number : ";
	std::cin >> Dest_index;
}

void ChainedMatrix::order_start() {
	std::cout << std::endl << std::endl;
	std::cout << "Mimimum Multiplication from Matrix" << Src_index << " to Matrix" << Dest_index << " is : " << std::endl;
	order(Src_index, Dest_index);
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
	std::cout << "Enter the number of matrices : ";
	std::cin >> n;

	ChainedMatrix A(n);

	A.insertArray_d();

	A.showArray_d();

	A.call_minmult();

	A.showArray_P();

	A.showArray_M();

	A.order_insert();

	A.order_start();

	std::cout << std::endl << std::endl;

	return 0;
}