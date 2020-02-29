/* This is Merge Sort  implemented in C++.
	mergeSort2 uses (n) amount of space.
	The array S (size : n) is declared in global scope.
	*/

#include <iostream>

int n = 8;
int S[8] = { 0, };

void mergeSort2(int low, int high);
void merge2(int low, int mid, int high);

void mergeSort2(int low, int high) {
	int mid;
	if (low < high) {
		mid = (low + high) / 2;
		mergeSort2(low, mid);
		mergeSort2(mid + 1, high);
		merge2(low, mid, high);
	}
}

void merge2(int low, int mid, int high) {
	int i, j, k;
	int i_tmp, j_tmp, k_tmp;
	int high_tmp = high - low;
	int low_tmp = 0;
	int mid_tmp = high / 2;
	i_tmp = low_tmp; j_tmp = mid_tmp + 1; k_tmp = low_tmp;
	i = low; j = mid + 1; k = low;

	int* U = new int[high_tmp + 1];

	while (i <= mid && j <= high) {
		if (S[i] < S[j]) {
			U[k_tmp] = S[i];
			i++;
			i_tmp++;
		}
		else {
			U[k_tmp] = S[j];
			j++;
			j_tmp++;
		}
		k++;
		k_tmp++;
	}
	if (i_tmp > mid_tmp) {
		//move S[j] through S[high] to U[k] through U[high-1]
		for (int r = j, s = k_tmp; r <= high || s <= high_tmp; r++, s++) {
			U[s] = S[r];
		}
	}
	else {
		//move S[i] through S[mid] to U[k] through U[high-1]
		for (int r = i, s = k_tmp; r <= mid || s <= high_tmp; r++, s++) {
			U[s] = S[r];
		}
	}
	//move U[low] through U[high] to S[low] through S[high-1]
	for (int r = low_tmp, s = low; r <= high_tmp || s <= high; r++, s++) {
		S[s] = U[r];
	}
	delete U;
}

int main() {
	std::cout << "Enter the elements of the array S (size : " << n << ") : ";
	for (int i = 0; i < n; i++) {
		std::cin >> S[i];
	}
	mergeSort2(0,n-1);
	std::cout << std::endl;
	std::cout << "Result of array S sorted in an ascending order : ";
	for (int i = 0; i < n; i++) {
		std::cout << S[i] << "  ";
	}
	std::cout << std::endl << std::endl;
	return 0;
}