#include <iostream>
using namespace std;
#define MAX 501

// D[N][i] = max(D[N-1][i-1], D[N-1][i]) + element[N][i]

int D[MAX][MAX];
int element[MAX][MAX];
int max(int a, int b) {
    return a >= b ? a : b;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int n;
    cin >> n;

     for(int i = 0; i < n; i++) {
         for(int j = 0; j < i+1; j++) {
             cin >> element[i][j];
         }
     }

     D[0][0] = element[0][0];
     for(int i = 1; i < n; i++) {
         for(int j = 0; j < i+1; j++) {
             D[i][j] = max(D[i-1][j-1], D[i-1][j]) + element[i][j];
         }
     }

     int res = D[n-1][0];
     for(int i = 0; i < n; i++) {
         res = max(res, D[n-1][i]);
     }

     cout << res << '\n';
     return 0;
}