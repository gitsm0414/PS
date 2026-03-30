/*
BOJ 15650 nm2
Used Algorithms:
Time Complexity: O()

핵심 아이디어
- 

실수
-잔실수 많으니 아래 주석에서 확인할 것

다른 관점
-
*/

#include <bits/stdc++.h>
using namespace std;

int N, M;
int arr[10];
int res[10];

void f(int idx, int st){
    if(idx == M){
        for(int i = 0; i < M; i++) cout << res[i] << ' ';
        cout << '\n';
        return;
    }
    int last_val = 0;
    for(int i = st; i < N; i++){
        if(last_val == arr[i]) continue;
        last_val = arr[i];
        res[idx] = arr[i];//idx 를 i라 해버렸다...
        f(idx+1, i);//i를 st라 해버렸다..
    }

}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> N >> M;
    for(int i = 0; i < N; i++) cin >> arr[i]; //N, M 실수..
    sort(arr, arr+N);

    f(0,0);

    return 0;
}