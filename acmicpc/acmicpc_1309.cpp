#include <iostream>
using namespace std;
#define MAX 100001
#define DIV 9901
// D[N][0] = Lion is not in this row.
// D[N][0] = D[N-1][0] + D[N-1][1] + D[N-1][2]
// D[N][1] = Lion is in the left side of this row.
// D[N][1] = D[N-1][0] + D[N-1][2]
// D[N][2] = Lion is in the right side of this row.
// D[N][2] = D[N-1][0] + D[N-1][1]

int cage[MAX][3];
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int N;
    cin >> N;

    cage[0][0] = 1; cage[0][1] = 1; cage[0][2] = 1;

    for(int i = 1; i < N; i++) {
        cage[i][0] += (cage[i-1][0] + cage[i-1][1] + cage[i-1][2]);
        cage[i][0] %= DIV;
        cage[i][1] += (cage[i-1][0] + cage[i-1][2]);
        cage[i][1] %= DIV;
        cage[i][2] += (cage[i-1][0] + cage[i-1][1]);
        cage[i][2] %= DIV;
    }

    cout << (cage[N-1][0] + cage[N-1][1] + cage[N-1][2]) % DIV << '\n';

    return 0;
}