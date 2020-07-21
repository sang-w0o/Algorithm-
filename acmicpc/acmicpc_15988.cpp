#include <iostream>
using namespace std;
#define DIV 1000000009
#define MAX 1000000

// D[i] = Ways to make i with addition of 1, 2, 3
// D[n] = D[n-1] + D[n-2] + D[n-3]
long long D[MAX + 1];

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int T;
    cin >> T;

    int *N = new int[T+1];
    for(int i = 1; i <= T; i++) {
        cin >> N[i];
    }


    D[0] = 1; D[1] = 1; D[2] = 2;
    for(int i = 3; i <= MAX; i++) {
        D[i] = (D[i-1] + D[i-2] + D[i-3]) % DIV;
    }

    for(int i = 1; i <= T; i++) {
        cout << D[N[i]] << '\n';
    }
    delete[] N;
    return 0;
}
