/* This is Quick Sort implemented in C++.
    The array S, and its size n is declared in global scope.
	*/

#include <iostream>
int n = 8;
int S[] = { 0, };

void quickSort(int low, int high);
void partition(int low, int high, int& pivotpoint);

void quickSort(int low, int high) {
	int pivotpoint;
	if (high > low) {
		partition(low, high, pivotpoint);
		quickSort(low, pivotpoint - 1);
		quickSort(pivotpoint + 1, high);
	}
}

void partition(int low, int high, int& pivotpoint) {
	int i, j;
	int pivotitem;

	pivotitem = S[low];
	j = low;
	for (i = low + 1; i <= high; i++)
		if (S[i] < pivotitem) {
			j++;
			//exchange S[i] and S[j]
			int temp = S[j];
			S[j] = S[i];
			S[i] = temp;
		}
	pivotpoint = j;
	//exchange S[low] and S[pivotpoint];
	int temp = S[pivotpoint];
	S[pivotpoint] = S[low];
	S[low] = temp;
}

int main() {
	std::cout << "Enter the elements of the array S (size : " << n << ") : ";
	for (int i = 0; i < n; i++) {
		std::cin >> S[i];
	}
	quickSort(0, n - 1);
	std::cout << std::endl << std::endl;
	std::cout << "Result of array S sorted by quickSort : ";
	for (int i = 0; i < n; i++) {
		std::cout <<  S[i] <<"  ";
	}
	std::cout << std::endl;
	return 0;
}
