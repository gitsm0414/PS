/*
BOJ 15650 nm2
Used Algorithms:
Time Complexity: O()

핵심 아이디어
- 

실수
- input받으면서 버블정렬할 때 j++아니라 j--해야되는데 실수했다.

다른 관점
-
*/

#include <bits/stdc++.h>
using namespace std;

int N, M;
int input[10];
int res[10];

void f(int idx, int st){
    if(idx == M){
        for(int i = 0; i < M; i++) cout << res[i] << ' ';
        cout << '\n';
        return;
    }
    for(int i = st; i < N; i++){
        res[idx] = input[i];
        f(idx+1, i+1);
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> N >> M;
    for(int i = 0; i < N; i++){
        cin >> input[i];
        for(int j = i; j > 0; j--){
            if(input[j] < input[j-1]){
                //swap
                input[j] = input[j] ^ input[j-1];
                input[j-1] = input[j] ^ input[j-1];
                input[j] = input[j] ^ input[j-1];
                //참고 주의사항: 인덱스가 같은애들끼리 ^ swap하면 0으로 증발해버린다. 물론 여기서 그럴일은 없겟지만
                //그래서 그냥 tmp 쓰는게 맘편하긴함
            }
        }
    }

    f(0, 0);
    return 0;
}