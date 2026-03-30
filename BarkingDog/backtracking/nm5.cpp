/*
BOJ 15650 nm2
Used Algorithms:
Time Complexity: O()

핵심 아이디어
- 

실수
-next_permutation은 n개중 n개 순열 혹은 n개 중 m개 조합 이런경우에는 활용가능한데 이 문제는 조합이아니라 n 중 m 순열이기 때문에 활용하기 힘들다.

다른 관점
-
*/

#include <bits/stdc++.h>
using namespace std;

int N, M;
int input[10];
int isused[10];
int res[10];

void f(int k){
    if(k == M){
        for(int i = 0; i < M; i++){
            cout << res[i] << ' ';
        }
        cout << '\n';
        return;
    }
    for(int i = 0; i < N; i++){
        if(!isused[i]){
            res[k] = input[i];
            isused[i] = 1;

            f(k+1);
            isused[i] = 0;
        }
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> N >> M;

    for(int i = 0; i < N; i++) cin >> input[i];
    sort(input, input+N);
    f(0);

    return 0;
}