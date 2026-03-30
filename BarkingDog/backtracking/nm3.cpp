/*
BOJ 15650 nm2
Used Algorithms:
Time Complexity: O(n^m)

핵심 아이디어
- 

실수
- base coneition에서 마지막에 return을 안적는 실수를 하였다. 배열의 out of bound나 함수호출의 스택오버플로우가 발생할 수 있다.

다른 관점
-next_permutation은 중복이 없는 순열을 처리하는데 특화되어있어 이 문제의 경우 오히려 억지로 구현하면 더 효율성이 떨어진다. 따라서 백트래킹 기법이 좋다.
*/

#include <bits/stdc++.h>
using namespace std;

int arr[8];
int N, M;

void f(int k){
    if(k == M){
        for(int i = 0; i < M; i++) cout << arr[i] << ' ';
        cout << '\n';
        return;
    }
    for(int i = 1; i <= N; i++){
        arr[k] = i;
        f(k+1);
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> N >> M;
    f(0);

    return 0;
}