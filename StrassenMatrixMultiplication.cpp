/* This is Strassen's Matrix Multiplication Algorithm 
	implemented in C++. Integer n must be a power of 2.
	There are 2 n*n matrices A and B, and the result of A*B
	is stored in the array RES. */

#include <iostream>

class Matrix {
private:
	int n;
	int** A;
	int** B;
	int** RES;
public:
	Matrix(int n=0);
	~Matrix();
	void strassen(int n, int** A, int** B, int** RES);
	void inputElements();
	void printResult();
	void call_strassen();
};

int** make2DArray(int n);

Matrix::Matrix(int n) {
	this->n = n;
	A = make2DArray(n);
	B = make2DArray(n);
	RES = make2DArray(n);
}

Matrix::~Matrix() {
	for (int i = 0; i < n; i++) {
		delete[] A[i];
		delete[] B[i];
		delete[] RES[i];
	}
	delete[] A;
	delete[] B;
	delete[] RES;
}
void Matrix :: strassen(int n, int** A, int** B, int** RES) {
	int**m1 = make2DArray(n);
	int**m2 = make2DArray(n);
	int**m3 = make2DArray(n);
	int**m4 = make2DArray(n);
	int**m5 = make2DArray(n);
	int**m6 = make2DArray(n);
	int**m7 = make2DArray(n);

	int**tmp1 = make2DArray(n);
	int**tmp2 = make2DArray(n);

	int i, j;

	if (n <= 1)
		RES[0][0] = A[0][0] * B[0][0];

	else {
		for (i = 0; i < n / 2; i++)
			for (j = 0; j < n / 2; j++)
				tmp1[i][j] = A[i][j] + A[i + n / 2][j + n / 2];
		for (i = 0; i < n / 2; i++)
			for (j = 0; j < n / 2; j++)
				tmp2[i][j] = B[i][j] + B[i + n / 2][j + n / 2];
		strassen(n / 2, tmp1, tmp2, m1);

		for (i = 0; i < n / 2; i++)
			for (j = 0; j < n / 2; j++)
				tmp1[i][j] = A[i + n / 2][j] + A[i + n / 2][j + n / 2];
		for (i = 0; i < n / 2; i++)
			for (j = 0; j < n / 2; j++)
				tmp2[i][j] = B[i][j];
		strassen(n / 2, tmp1, tmp2, m2);

		for (i = 0; i < n / 2; i++)
			for (j = 0; j < n / 2; j++)
				tmp1[i][j] = A[i][j];
		for (i = 0; i < n / 2; i++)
			for (j = 0; j < n / 2; j++)
				tmp2[i][j] = B[i][j + n / 2] - B[i + n / 2][j + n / 2];
		strassen(n / 2, tmp1, tmp2, m3);

		for (i = 0; i < n / 2; i++)
			for (j = 0; j < n / 2; j++)
				tmp1[i][j] = A[i + n / 2][j + n / 2];
		for (i = 0; i < n / 2; i++)
			for (j = 0; j < n / 2; j++)
				tmp2[i][j] = B[i + n / 2][j] - B[i][j];
		strassen(n / 2, tmp1, tmp2, m4);

		for (i = 0; i < n / 2; i++)
			for (j = 0; j < n / 2; j++)
				tmp1[i][j] = A[i][j] + A[i][j + n / 2];
		for (i = 0; i < n / 2; i++)
			for (j = 0; j < n / 2; j++)
				tmp2[i][j] = B[i + n / 2][j + n / 2];
		strassen(n / 2, tmp1, tmp2, m5);

		for (i = 0; i < n / 2; i++)
			for (j = 0; j < n / 2; j++)
				tmp1[i][j] = A[i + n / 2][j] - A[i][j];
		for (i = 0; i < n / 2; i++)
			for (j = 0; j < n / 2; j++)
				tmp2[i][j] = B[i][j] + B[i][j + n / 2];
		strassen(n / 2, tmp1, tmp2, m6);

		for (i = 0; i < n / 2; i++)
			for (j = 0; j < n / 2; j++)
				tmp1[i][j] = A[i][j + n / 2] - A[i + n / 2][j + n / 2];
		for (i = 0; i < n / 2; i++)
			for (j = 0; j < n / 2; j++)
				tmp2[i][j] = B[i + n / 2][j] + B[i + n / 2][j + n / 2];
		strassen(n / 2, tmp1, tmp2, m7);

		for (i = 0; i < n / 2; i++)
			for (j = 0; j < n / 2; j++)
				RES[i][j] = m1[i][j] + m4[i][j] - m5[i][j] + m7[i][j];
		for (i = 0; i < n / 2; i++)
			for (j = 0; j < n / 2; j++)
				RES[i][j + n / 2] = m3[i][j] + m5[i][j];
		for (i = 0; i < n / 2; i++)
			for (j = 0; j < n / 2; j++)
				RES[i + n / 2][j] = m2[i][j] + m4[i][j];
		for (i = 0; i < n / 2; i++)
			for (j = 0; j < n / 2; j++)
				RES[i + n / 2][j + n / 2] = m1[i][j] + m3[i][j] - m2[i][j] + m6[i][j];
	}

	for (int i = 0; i < n; i++) {
		delete[] m1[i];
		delete[] m2[i];
		delete[] m3[i];
		delete[] m4[i];
		delete[] m5[i];
		delete[] m6[i];
		delete[] m7[i];
		delete[] tmp1[i];
		delete[] tmp2[i];
	}
	delete[] m1; delete[] m2; delete[] m3; delete[] m4; delete[] m5; delete[] m6; delete[] m7;
	delete[] tmp1; delete[] tmp2;
}

void Matrix::call_strassen() {
	strassen(n, A, B, RES);
}

void Matrix::inputElements() {
	std::cout << "Enter the components of the matrix A (size : " << n << "*" << n << ") : " << std::endl;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			std::cin >> A[i][j];
		}
	}

	std::cout << std::endl << std::endl;

	std::cout << "Enter the components of the matrix B (size : " << n << "*" << n << ") : " << std::endl;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			std::cin >> B[i][j];
		}
	}
}

void Matrix::printResult() {
	std::cout << std::endl << std::endl;

	std::cout << "====== < Matrix A >======" << std::endl;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			std::cout << A[i][j] << "\t";
		}
		std::cout << std::endl;
	}

	std::cout << std::endl << std::endl;

	std::cout << "====== < Matrix B > ======" << std::endl;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			std::cout << B[i][j] << "\t";
		}
		std::cout << std::endl;
	}

	std::cout << std::endl << std::endl;

	std::cout << "====== < RESULT Matrix > ======" << std::endl;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			std::cout << RES[i][j] << "\t";
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
	std::cout << "Enter the size (n) of A and B (A,B : n*n matrix) : ";
	std::cin >> n;

	Matrix A = Matrix(n);

	std::cout << std::endl << std::endl;

	A.inputElements();

	A.call_strassen();

	A.printResult();

	return 0;
}

