#include <iostream>
using namespace std;
#define MAX 1001
#define DIV 10007

// D[N][i] : Cases of ascending number where number's length is N and lastly-used number is i.
// ex. D[N][2] = D[N-1][0] + D[N-1][1] + D[N-1][2];
long long D[MAX][10];
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int N;
    cin >> N;

    for(int i = 0; i <= 9; i++) {
        D[1][i] = 1;
    }

    for(int i = 2; i <= N; i++) {
        for(int j = 0; j <= 9; j++) {
            for(int k = j; k >= 0; k--){
                    D[i][j] += D[i - 1][k];
                    D[i][j] %= DIV;

            }
        }
    }

    long long res = 0;
    for(int i = 0; i <= 9; i++) {
        res += D[N][i];
        res %= DIV;
    }

    cout << res << '\n';

    return 0;
}