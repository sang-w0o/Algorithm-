#include <iostream>
using namespace std;
#define MAX 1001
int D[MAX][MAX];
int cost[MAX][3];

int min(int a, int b){
    return a >= b ? b : a;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int N;
    cin >> N;

    for(int i = 1; i <= N; i++) {
        for(int j = 0; j < 3; j++) {
            cin >> cost[i][j];
        }
    }

    int res = (MAX-1)*(MAX-1)+1;

    for(int i = 0; i < 3; i++) {
        for(int j = 0; j < 3; j++) {
            if(i==j) {
                D[1][j] = cost[1][j];
            } else {
                D[1][j] = (MAX-1)*(MAX-1)+1;
            }
        }

        for(int k = 2; k <= N; k++) {
            D[k][0] = min(D[k-1][1], D[k-1][2]) + cost[k][0];
            D[k][1] = min(D[k-1][0], D[k-1][2]) + cost[k][1];
            D[k][2] = min(D[k-1][0], D[k-1][1]) + cost[k][2];
        }

        for(int l = 0; l < 3; l++) {
            if(l == i) continue;
            res = min(res, D[N][l]);
        }
    }

    cout << res << '\n';
    return 0;
}
