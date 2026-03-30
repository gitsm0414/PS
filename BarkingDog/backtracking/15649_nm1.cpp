/*
BOJ 15649 N&M 1
Used Algorithms: back tracking
Time Complexity: O((N!)/(N-M)!) -> O(N!) 최악의 경우 단, M, M <= 8

핵심 아이디어
- 

실수
- 

다른 관점
-
*/

#include <bits/stdc++.h>
using namespace std;

int N, M;

int arr[10];
bool issued[10];

void f(int k){
    if(k == M){
        for(int i = 0; i < M; i++){
            cout << arr[i] << ' ';
        }
        cout << '\n';
        return;
    }

    for(int i = 1; i <= N; i++){
        if(!issued[i]){
            arr[k] = i;
            issued[i] = 1;
            f(k+1);
            issued[i] = 0;
        }
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> N >> M;
    f(0);

    return 0;
}