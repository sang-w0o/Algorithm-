/* This is Exchange Sort implemented in C++.
	 This algorithm sorts the array S (size : n) 
	 in an ascended order.
	 */

#include <iostream>

void exchange(int& t1, int& t2) {
	int temp = t1;
	t1 = t2;
	t2 = temp;
}

void exchangesort(int n, int* S) {
	int i, j;
	for (i = 0; i < n - 1; i++) {
		for (j = i + 1; j < n; j++) {
			if (S[j] < S[i])
				exchange(S[i], S[j]);
		}
	}
}

int main() {
	int n;
	std::cout << "Enter the size of the array S : ";
	std::cin >> n;
	int* S = new int[n];
	std::cout << "Enter the elements of the array S : ";
	for (int i = 0; i < n; i++) {
		std::cin >> S[i];
	}
	exchangesort(n, S);
	std::cout << "This is the array S sorted in an ascending order" << std::endl << std::endl;
	for (int i = 0; i < n; i++) {
		std::cout << S[i] << "  ";
	}
	delete[] S;
	return 0;

}
