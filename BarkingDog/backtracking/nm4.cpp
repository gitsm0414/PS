/*
BOJ 15650 nm2
Used Algorithms:
Time Complexity: O()

핵심 아이디어
- 

실수
- 

다른 관점
-
*/

#include <bits/stdc++.h>
using namespace std;

int arr[10];
int N, M;

void f(int k, int st){
    if(k == M){
        for(int i = 0; i < M; i++) cout << arr[i] << ' ';
        cout << '\n';
        return;
    }
    //int st = (k > 0 ? arr[k-1] : 1); st변수를 함수 인자로놓고 f(0, 1)이렇게할수있다.
    for(int i = st; i <=N; i++){
        arr[k] = i;
        f(k+1, i);
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> N >> M;
    f(0, 1);

    return 0;
}