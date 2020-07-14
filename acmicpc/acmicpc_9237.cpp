#include <iostream>
#include <algorithm>
using namespace std;

int max(int a,int b) {
	return (a >= b) ? a : b;
}

int main() {
	
	ios_base::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	
	int N;
	cin >> N;
	
	// cnt = 2 : ���� ���� 1�� + t�� �ּҰ��� 1�̹Ƿ�
	// 1�ϸ��� �ڶ�� ������ �� �ڶ���� �ּ� 2�� �ɸ�. 
	int cnt = 2;
	
	int *t = new int[N];
	for(int i = 0; i < N; i++) {
		cin >> t[i];
	}
	
	// t �迭�� ���ҵ��� ������������ ����
	sort(t, t + N);
	
	// 2 3 3 4
	int res = 0;
	
	// ���ĵ� t�迭�� ���� ū ������ ������ ������ for�� ������. 
	// ū ������ ������ ���� : t���� ���� ū ������� ���� �ɾ�� �ְ� �ϼ��� ���´�.
	// cnt++ �ϴ� ���� : �Ϸ翡 �� ����ۿ� ���� ���ϹǷ� ���� ������ ���� ������
	// �Ϸ簡 �����ϱ� �����̴�. 
	for(int i = N - 1; i >= 0; i--) {
		res = max(res, cnt + t[i]);
		//  
		cnt++;
	}
	
	// i = 3 --> res = max(0, 2 + 4) = 6
	// i = 2 --> res = max(6, 3 + 3) = 6
	// i = 1 --> res = max(6, 4 + 3) = 7
	// i = 0 --> res = max(7, 5 + 2) = 7 
	
	cout << res << '\n';
	delete[] t;
	return 0;
}
