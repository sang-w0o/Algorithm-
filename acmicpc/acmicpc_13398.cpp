#include <iostream>
#include <vector>
using namespace std;
#define MAX 100001
int num[MAX];

int max(int a, int b) {
    return a >= b ? a : b;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int n;
    cin >> n;

    for(int i = 1; i <= n; i++) {
        cin >> num[i];
    }

    // d[i] : i에서 끝나는 연속합의 값
    vector<int> d(n+1);
    // dr[i] : i에서 시작하는 연속합의 값
    vector<int> dr(n+1);

    for(int i = 1; i <= n; i++) {
        d[i] = num[i];
        if(i==1) continue;
        if(d[i] < d[i-1] + num[i]) {
            d[i] = d[i-1] + num[i];
        }
    }

    for(int i = n; i >= 1; i--) {
        dr[i] = num[i];
        if(i == n) continue;
        if(dr[i] < dr[i+1] + num[i]) {
            dr[i] = dr[i+1] + num[i];
        }
    }

    int res = d[1];
    for(int i = 2; i <= n; i++) {
        if(res < d[i]) {
            res = d[i];
        }
    }

    // 한개의 수 (num[i])를 제외한 것이 더 큰 경우가 있는지를 검사한다.
    for(int i = 2; i < n; i++) {
        if(res < d[i-1] + dr[i+1]) {
            res = d[i-1] + dr[i+1];
        }
    }

    cout << res << '\n';
    return 0;
}
