#include <iostream>
#include <vector>
using namespace std;
#define MAX 1001
int num[MAX];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int N;
    cin >> N;

    vector<int> D1(N+1);
    vector<int> D2(N+1);

    for(int i = 1; i <= N; i++) {
        cin >> num[i];
    }

    // 각 index별로 그 index를 기준으로 증가하는 부분수열의
    // 최대 길이를 구한다.
    for(int i = 1; i <= N; i++) {
        D1[i] = 1;
        for(int j = 1; j <= i; j++) {
            if(num[j] < num[i] && D1[j] + 1 > D1[i]) {
                D1[i] = D1[j] + 1;
            }
        }
    }

    // 각 index 별로 그 index를 기준으로 감소하는 부분수열의
    // 최대 길이를 구한다.
    for(int i = N; i >= 1; i--) {
        D2[i] = 1;
        for(int j = i; j <= N; j++) {
            if(num[i] > num[j] && D2[j] + 1 > D2[i]) {
                D2[i] = D2[j] + 1;
            }
        }
    }

    int res = 0;
    for(int i = 1; i <= N; i++) {
        if(res < D1[i] + D2[i] - 1) {
            res = D1[i] + D2[i] - 1;
        }
    }

    cout << res << '\n';

    return 0;
}



