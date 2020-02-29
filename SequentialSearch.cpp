/*This is Sequential Search implemented in C++.
   This algorithm searches if key x exists in the int array S.
    If x exists, its location goes into "location", and if it 
	doesn't exist, "location" will have the value of 0.
	*/

#include <iostream>
void seqsearch(int n, const int* S, int x, int& location) {
	location = 1;
	while (location <= n && S[location] != x)
		location++;
	if (location > n)
		location = 0;
}

int main() {
	int n;
	int x;
	int location = 0;
	std::cout << "Enter the size of the array S : ";
	std::cin >> n;
	int* S = new int[n];
	std::cout << "Enter the elements of the array S : ";
	for (int i = 0; i < n; i++) {
		std::cin >> S[i];
	}
	std::cout << "Enter the key : ";
	std::cin >> x;
	seqsearch(n, S, x, location);
	std::cout << "The key " << x << " is here : " << location << std::endl;
	delete S;
	return 0;
}