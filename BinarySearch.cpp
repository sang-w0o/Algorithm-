/*This is Binary Search implemented in C++.
This algorithm searches if key x exists in the int array S.
If x exists, its location goes into "location", and if it
doesn't exist, "location" will have the value of 0.
The premise of Binary Search is that the elements of S are sorted.
*/

#include <iostream>
void binsearch(int n, const int* S, int x, int& location) {
	int low, high, mid;
	low = 1; high = n; location = 0;
	while (low <= high && location == 0) {
		mid = (low + high) / 2;
		if (x == S[mid]) location = mid;
		else if (x < S[mid]) high = mid - 1;
		else low = mid + 1;
	}
}

int main() {
	int n, x, location;
	std::cout << "Enter the size of the array S : ";
	std::cin >> n;
	int* S = new int[n];
	std::cout << "Enter the elements of the array S : ";
	for (int i = 0; i < n; i++) {
		std::cin >> S[i];
	}
	std::cout << "Enter the key : ";
	std::cin >> x;
	binsearch(n, S, x, location);
	std::cout << "The key " << x << " is here : " << location << std::endl;
	delete[] S;
}
