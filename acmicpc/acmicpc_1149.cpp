#include <iostream>
using namespace std;
#define MAX 1001

// D[i][j] = Minimum cost to paint 1~i houses where i-th house is painted in j color.

int D[MAX][3];
int RGB[MAX][3];

int min(int a, int b) {
    return a >= b ? b : a;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int N;
    cin >> N;

    for(int i = 1; i <= N; i++){
        for(int j = 0; j < 3; j++){
            cin >> RGB[i][j];
        }
    }

    D[0][0] = RGB[0][0];
    D[0][1] = RGB[0][1];
    D[0][2] = RGB[0][2];

    for(int i = 1; i <= N; i++) {
        D[i][0] = min(D[i-1][1], D[i-1][2]) + RGB[i][0];
        D[i][1] = min(D[i-1][0], D[i-1][2]) + RGB[i][1];
        D[i][2] = min(D[i-1][0], D[i-1][1]) + RGB[i][2];
    }

    int res = min(min(D[N][0], D[N][1]), D[N][2]);
    cout << res << '\n';
    return 0;
}