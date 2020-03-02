/* This is Binomial Coefficient Algorithm implemented in C++.
    The inputs of the function bin are int n, int k, for which (k <= n).
	Function bin calculates the binomial coefficient of (n,k).
	Function bin2 is made by using "Dynamic Programming".*/

#include <iostream>

int bin2(int n, int k);
int minimum(int comp1, int comp2);
int** make2DArray(int row, int col);

int bin2(int n, int k) {
	int i, j;
	int** B = make2DArray(n+1, k+1);

	for (i = 0; i <= n; i++) {
		for (j = 0; j <= minimum(i, k); j++) {
			if (j == 0 || j == i) {
				B[i][j] = 1;
			}
			else {
				B[i][j] = B[i - 1][j - 1] + B[i - 1][j];
			}
		}
	}
	int res = B[n][k];

	for (int i = 0; i < n+1; i++) {
		delete[] B[i];
	}
	delete[] B;

	return res;
}

int minimum(int comp1, int comp2) {
	if (comp1 < comp2)
		return comp1;
	else
		return comp2;
}

int** make2DArray(int row, int col) {
	int** temp = new int*[row];
	for (int i = 0; i < row; i++) {
		temp[i] = new int[col];
		memset(temp[i], 0, sizeof(int)*col);
	}
	return temp;
}

int main() {
	int n, k;
	std::cout << "Enter the value of n : ";
	std::cin >> n;
	std::cout << "Enter the value of k (k <= n) : ";
	std::cin >> k;

	int res = bin2(n, k);

	std::cout << std::endl;
	std::cout << "The Binomial Coefficient of (" << n << "," << k << ") is : " << res << std::endl;

	return 0;
}