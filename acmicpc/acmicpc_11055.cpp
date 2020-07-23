#include <iostream>
using namespace std;
#define MAX 1001

int numbers[MAX];
int D[MAX];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int N;
    cin >> N;

    for(int i = 1; i <= N; i++) {
        cin >> numbers[i];
    }

    int res = 0;

    for(int i = 1; i <= N; i++) {
        D[i] = numbers[i];
        for(int j = 1; j < i; j++) {
            if(numbers[j] < numbers[i] && D[i] < D[j] + numbers[i]) {
                D[i] = D[j] + numbers[i];
            }
           if(res < D[i]) res = D[i];
        }
    }

    cout << res << '\n';
    return 0;
}



