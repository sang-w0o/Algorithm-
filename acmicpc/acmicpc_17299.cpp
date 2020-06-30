#include <iostream>
#include <vector>
#include <stack>
using namespace std;

int freq[1000001];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int N;
	cin >> N;

	vector<int> a(N);
	vector<int> answer(N);

	for (int i = 0; i < N; i++) {
		cin >> a[i];
		freq[a[i]] += 1;
	}
}