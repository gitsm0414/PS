/*
BOJ 1992 쿼드트리
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

char board[70][70];

void f(int len, int x, int y){
    char tmp = board[x][y];

    bool same = true;
    for(int i = x; i < x + len; i++){
        for(int j = y; j < y + len; j++){
            if(tmp != board[i][j]){
                same = false; break;
            }
        }
        if(!same) break;
    }

    if(same){
        printf("%c", tmp);
        return;
    }else{
        printf("(");
        int half = len/2;
        for(int i = 0; i < 2; i++){
            for(int j = 0; j < 2; j++){
                f(half, x + i*half, y + j*half);
            }
        }
        printf(")");
    }  
}

int main(){
    //ios::sync_with_stdio(false);


    int n;
    cin >> n;
    for(int i = 0; i < n; i++){
        scanf("%s", board[i]);
    }

    f(n, 0, 0);

    return 0;
}