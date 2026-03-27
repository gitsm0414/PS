/*
BOJ 1074 Z
Used Algorithms:
Time Complexity: O()

핵심 아이디어
- 사실상 제미나이가 다 한거라서 코드원리 이해 잘하고 내용 잘 복습하는것밖에...

실수
- int mtx[33000][33000]; //10^9개의 int를 요구, 4GB이므로 백준의 메모리 제한을 훨씬 넘는다. 따라서 이접근방법은 맞지않다.
- 과정보다는 몇번째 방문인지를 구해야하므로 블럭단위로 했을 때 넘겨도 되면 그 블록 안의 개수만큼 더하고 그냥 패스한다.

다른 관점
-
*/

#include <bits/stdc++.h>
using namespace std;


int cnt = 0;

int f(int n, int r, int c){//한변 길이가 2^n인 정사각형에서 [r, c]까지 가기 위한 스텝 수
    if(n == 0){//한변 길이 1인 정사각형일 때
        return 0; //왜냐하면 시작점은 횟수로 카운트하지 않는다.
    }
    int half = 1 << (n-1);//사분면의 한변 길이
    int area = half*half;//1사분면의 넓이

    
    if(r < half && c < half)//1사분면
        return f(n-1, r, c);

    if(r < half && c >= half)//2사분면
        return area + f(n-1, r, c - half);

    if(c < half)//3사분면
        return 2*area + f(n-1, r - half, c);

    //4사분면
        return 3*area + f(n-1, r - half, c - half);
    }



int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, r, c;
    cin >> n >> r >> c;

    cout << f(n, r, c);

    return 0;
}