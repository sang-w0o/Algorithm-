#include <iostream>
using namespace std;
#define MAX 31

int D[MAX];

// D[i] : 3 * i 를 채우는 방법의 수
// 가장 오른쪽을 2*1로 채우는 방식은 3가지가 있다.
// D[i] = 3 * D[i-2] + 2 * D[i-4] + 2 * D[i-6] + ..
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int N;
    cin >> N;

    D[0] = 1;
    D[1] = 0;
    D[2] = 3;

    // N이 홀수이면 채울 수 없으므로 0이다.
    if(N%2 == 0) {
        for(int i = 4; i <= N; i += 2) {
            D[i] = D[i-2] * 3;
            for(int j = 4; j <= i; j+= 2) {
                D[i] += D[i-j] * 2;
            }
        }
    }

    cout << D[N] << '\n';
    return 0;
}
