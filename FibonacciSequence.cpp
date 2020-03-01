/* This is Fibonacci Sequence implemented in C++.
     The function fib1 and fib2 calculates and returns the n-th
	 value of Fibonacci sequence. 
	 fib1 is made in recursive way, and fib2 is made in iterative way. 
*/

#include <iostream>

int fib1(int n) {
	if (n <= 1)
		return n;
	else
		return fib1(n - 1) + fib1(n - 2);
}

int fib2(int n) {
	int i;
	int* f = new int[n+1];
	f[0] = 0;
	if (n > 0) {
		f[1] = 1;
		for (i = 2; i <= n; i++) {
			f[i] = f[i - 1] + f[i - 2];
		}
	}
	int return_val = f[n];
	delete[] f;
	return return_val;
}

int main() {
	int n;
	int return_of_fib1, return_of_fib2;
	std::cout << "Enter value 'n' for fib1 : ";
	std::cin >> n;
	return_of_fib1 = fib1(n);
	std::cout << "The return value of fib1 is : " << return_of_fib1 << std::endl << std::endl;
	std::cout << "Enter value 'n' for fib2 : ";
	std::cin >> n;
	return_of_fib2 = fib2(n);
	std::cout << "The return value of fib1 is : " << return_of_fib2 << std::endl;
	return 0;
}
