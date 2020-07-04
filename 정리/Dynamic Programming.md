Dynamic Programming
======

* Dynamic Programming은 __큰 문제를 여러개의 작은 문제로 나누어 푸는 것__ 이다. (작은 문제는 서로 중복 가능)
* Divide And Conquer는 DP와 마찬가지로 큰 문제를 작은 문제로 나누어 풀지만, 작은 문제가 중복될 수 없다.
<hr/>

<h2>Dynamic Programming</h2>

* 다음 두 가지 속성을 만족해야 문제를 DP로 풀 수 있다.
  1. Overlapping Subproblem
  2. Optimal Substructure

* Overlapping Subproblem : 겹치는 부분문제(작은 문제)
* Optimal Substructure : 최적부분 구조(문제의 정답이 작은 문제의 정답을 통해 구할 수 있을 때)

* Overlapping Subproblem의 예시 : 피보나치 수열
  * 큰 문제 : N 번째 피보나치 수를 구하는 문제
  * 작은 문제 : N-1 번째와 N-2 번째 피보나치 수를 구하는 문제

* Optimal Substructure를 만족한다면, 문제의 크기에 관계없이 어떤 한 문제의 답은 일정하다.
  * ex) 10번째 피보나치 수를 구하면서 구한 4번째 피보나치 수와 5번째 피보나치 수를 구하기 위한 4번째 피보나치 수는 동일하다.

* DP에서 작은 문제들은 각각 1번만 풀어야 한다. Optimal Substructure를 만족하기 때문에, __같은 문제는 구할 때 마다 정답이 같다__.   
  따라서 정답을 한번 구하면, 정답을 어딘가에 메모하는데, 이는 코드의 구현에서는 배열에 저장하는 것으로 할 수 있다.   
  이런 방식을 `Memoization` 이라 한다.

* 다음은 재귀호출을 사용한 피보나치 수를 구하는 함수이다.
```C
int fibonacci(int n) {
    if(n <= 1) {
        return n;
    }
    else {
        return fibonacci(n - 1) + fibonacci(n - 2);
    }
}

// 시간 복잡도 : O(2^n)
```
* 위 코드는 예를 들어 n이 5일 때, `fibonacci(3)` 와 `fibonacci(2)`의 값이 동일함에 불구하고 연산을 반복해서 한다.   
  이런 경우에 Memoization 기법을 사용하는 것이다.
* 아래는 Memoization을 적용한 피보나치 수를 구하는 함수이다.
```C
int memo[100]; // memo 배열은 0으로 초기화된다.
int fibonacci(int n) {
    if(n <= 1)
        return n;
    else {
        if(memo[n] > 0) {
            return memo[n];
        }
        memo[n] = fibonacci(n - 1) + fibonacci(n - 2);
        return memo[n];
    }
}

// 시간 복잡도 : 이 코드는 모든 문제를 1번씩 푼다.
// 따라서 시간복잡도는 (문제의 개수) * (문제 1개를 푸는 시간) 이 된다.
// 따라서 N * O(1) = O(N) ( O(1)은 함수에서 덧셈 1회만 하기 때문이다.)
```

* DP를 구현하는 방식에는 다음 두 가지 방법이 있다.
 1. Top-down : 큰 문제를 쪼개가면서 작은 문제들을 만들고, 다시 합쳐가면서 원래 문제를 푸는 방식(예시 : 재귀함수)
 2. Bottom-up : 작은 문제들을 모아서 큰 문제를 하나 만드는 행위를 반복하는 방식(주로 반복문으로 구현)

* Bottom-up 방식의 자세한 설명
 1. 문제를 크기가 작은 문제부터 차례대로 푼다.
 2. 문제의 크기를 조금씩 크게 만들면서 문제를 점점 푼다.
 3. 작은 문제를 풀어왔기에, 큰 문제는 항상 풀 수 있다.
 4. (1)~(3)을 반복하다보면 큰 문제를 풀 수 있다.

* Bottom-up 방식으로 구현한 피보나치 함수는 아래와 같다.
```C
int d[100];
int fibonacci(int n) {
    d[0] = 0;
    d[1] = 1;
    for(int i = 2; i <= n; i++) {
        d[i] = d[i-1] + d[i-2];
    }
    return d[n];
}
```

