/* This is Binomial Coefficient Algorithm implemented in C++.
	The inputs of the function bin are int n, int k, for which (k <= n).
	Function bin calculates the binomial coefficient of (n,k).
	If (k = 0) or (n=k), it returns 1.
	Function bin is made by using "Divide-and-Conquer".*/

#include <iostream>

int bin(int n, int k);

int bin(int n, int k) {
	if (k == 0 || n == k)
		return 1;
	else
		return (bin(n - 1, k - 1) + bin(n - 1, k));
}

int main() {
	int n, k;
	std::cout << "Enter the value of n : ";
	std::cin >> n;
	std::cout << "Enter the value of k (k <= n) : ";
	std::cin >> k;

	int res = bin(n, k);

	std::cout << std::endl;
	std::cout << "The Binomial Coefficient of (" << n << "," << k << ") is : " << res << std::endl;

	return 0;
}