/*
BOJ 2630 색종이 만들기
Used Algorithms:
Time Complexity: O()

핵심 아이디어
- 1780과 아이디어가 사실상 똑같다.

실수
- 

다른 관점
-
*/

#include <bits/stdc++.h>
using namespace std;

int res[2]; //{하얀색, 파란색}

int board[130][130];

void f(int len, int x, int y){
    int tmp = board[x][y];

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
        res[tmp]++;
        return;
    }else{
        int half = len/2;
        for(int i = 0; i < 2; i++){
            for(int j = 0; j < 2; j++){
                f(half, x + i*half, y + j*half);
            }
        }
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    for(int i = 0; i < n; i ++){
        for(int j = 0; j < n; j++){
            cin >> board[i][j];
        }
    }
    f(n, 0, 0);
    cout << res[0] << '\n' << res[1];

    return 0;
}