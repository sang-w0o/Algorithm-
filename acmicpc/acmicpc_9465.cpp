#include <iostream>
using namespace std;
#define MAX 100001
// D[i][j] : Maximum score achievable from 2*i stickers. Sticker picked from i-th column is j.
// D[i][0] : Not picked.
// D[i][1] : Up sticker is picked.
// D[i][2] : Down sticker is picked.

int D[MAX][3];
int score[2][MAX];

int max(int a, int b) {
    return a >= b ? a : b;
}

void init() {
    for(int i = 0; i < MAX; i++) {
        for(int j = 0; j < 3; j++) {
            D[i][j] = 0;
        }
    }

    for(int i = 0; i < 2; i++) {
        for(int j = 0; j < MAX; j++) {
            score[i][j] = 0;
        }
    }
}

void solve() {
    int n;
    cin >> n;

    init();

    for(int i = 0; i < 2; i++) {
        for (int j = 1; j <= n; j++) {
            cin >> score[i][j];
        }
    }

    for(int i = 1; i <= n; i++) {
        D[i][0] = max(max(D[i-1][0], D[i-1][1]), D[i-1][2]);
        D[i][1] = max(D[i-1][0], D[i-1][2]) + score[0][i];
        D[i][2] = max(D[i-1][0], D[i-1][1]) + score[1][i];
    }

    int res = max(D[n][1], D[n][2]);
    cout << res << '\n';
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int T;
    cin >> T;

    for(int i = 0; i < T; i++) {
        solve();
    }

    return 0;
}