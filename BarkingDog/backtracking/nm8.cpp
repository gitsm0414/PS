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
        f(idx+1, i);
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
                int tmp = input[j];
                input[j] = input[j-1];
                input[j-1] = tmp;
            }
        }
    }
    f(0,0);   

    return 0;
}