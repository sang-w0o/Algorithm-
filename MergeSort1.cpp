/* This is Merge Sort  implemented in C++.
    mergeSort1 uses (2n) amount of space.
	*/

#include <iostream>
void mergeSort(int n, int* S);
void merge(int h, int m, int* U, int* V, int* S);

void mergeSort(int n, int* S) {
	if (n > 1) {
		int h = n / 2;
		int m = n - h;
		int* U = new int[h];
		int* V = new int[m];
		
		//copy S[0] through S[h-1] to U[0] through U[h-1];
		for (int i = 0; i < h; i++) {
			U[i] = S[i];
		}

		//copy S[h] through S[n-1] to V[0] through V[m-1];
		for (int i = h, j = 0; i < n, j < m; i++, j++) {
			V[j] = S[i];
		}

		mergeSort(h, U);
		mergeSort(m, V);
		merge(h, m, U, V, S);
		delete U;
		delete V;
	}
}

void merge(int h, int m, int* U, int* V, int* S) {
	int i, j, k;
	i = 0; j = 0; k = 0;
	while (i <= h && j <= m) {
		if (U[i] < V[j]) {
			S[k] = U[i];
			i++;
		}
		else {
			S[k] = V[j];
			j++;
		}
		k++;
	}
	if (i > h) {
		//copy V[j] through V[m] to S[k] through S[h+m-1]
		for (int l = j, n = k-1; l < m, n < h + m; l++, n++) {
			S[n] = V[l];
		}
	}
	else {
		//copy U[i] through U[h] to S[k] through S[h+m-1];
		for (int l = i, n = k-1; l < h, n < h + m; l++, n++) {
			S[n] = U[l];
		}
	}
}

int main() {
	int n;
	std::cout << "Enter the number of elements of the array S : ";
	std::cin >> n;
	int* S = new int[n];
	std::cout << "Enter the elements of the array S : ";
	for (int i = 0; i < n; i++) {
		std::cin >> S[i];
	}
	mergeSort(n, S);
	std::cout << std::endl;
	std::cout << "The sorted array S is : ";
	for (int i = 0; i < n; i++) {
		std::cout << S[i] << " ";
	}
	std::cout << std::endl;
	delete S;
	return 0;
}