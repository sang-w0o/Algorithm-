#include <iostream>
#include <stack>
using namespace std;

int D[1001];
int V[1001];

int max(int a, int b) {
	return (a>=b) ? a : b;
}

int main() {
	
	ios_base::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	
	int N;
	cin >> N;
	
	int *arr = new int[N + 1];
	
	for(int i = 1; i <= N; i++) {
		cin >> arr[i];
		D[i] = 1;
	}
	
	int tmp = 0;
	
	for(int i = 1; i <= N; i++) {
		for(int j = i; j >= 1; j--) {
			if(arr[i] > arr[j]) {
				int temp = tmp;
				tmp = max(tmp, D[j]);
				if(temp != tmp) {
					V[i] = j;
				}
			}
		}
		D[i] += tmp;
		tmp = 0;
	}
	
	int result = 0;
	int index = 0;
	
	for(int i = 1; i <= N; i++) {
		int temp = result;
		result = max(result, D[i]);
		if(result != temp) {
			index = i;
		}
	}
	cout << result << '\n';

	stack<int> s;
	s.push(arr[index]);
	result--;
	while(result--) {
		int i = V[index];
		s.push(arr[i]);
		index = i;
	}
	
	while(!s.empty()) {
		int f = s.top();
		s.pop();
		cout << f << " ";
	}
	
	delete[] arr;
	
	
}
