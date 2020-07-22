#include <iostream>
using namespace std;
#define MAX 10001

// D[n] : n번째 잔을 마실 때 총합 와인의 최대량
// Case 1 : n-1번째 잔을 마시지 않은 경우 : D[n] = D[n-2] + amount[n]
// Case 2 : n-1번째 잔을 마신 경우 : D[n] = D[n-3] + amount[n-1] + amount[n]
// Case 3 : n-2, n-2번째 잔을 모두 마신 경우 : D[n] = D[n-1]
int D[MAX];

int max(int a, int b) {
    return a >= b ? a : b;
}



int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int n;
    cin >> n;

    int *amount = new int[n + 1];
    for(int i = 1; i <= n; i++) {
        cin >> amount[i];
    }

    D[1] = amount[1];
    D[2] = amount[1] + amount[2];

    for(int i = 3; i <= n; i++) {
        D[i] = max(max(D[i-3] + amount[i] + amount[i-1], D[i-2] + amount[i]), D[i-1]);
    }

    cout << D[n] << '\n';

    return 0;
}