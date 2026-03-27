/*
BOJ 11729 하노이의 탑
Used Algorithms:
Time Complexity: O()

핵심 아이디어
- 

실수
- 2^n은 2와 n의 비트 XOR이다. 따라서 거듭제곱을 표현하려면 <cmath> 헤더의 pow(2, n) 함수를 사용 (반환값이 double이라 형변환 필요).
혹은 (1 << n) 즉 시프트연산을 사용한다. (코테에서는 이게 권장됨)

다른 관점
-h()의 인자가 st, mid, end 3개 다 따로 지정해줬지만 사실 시작점과 목적지점을 뜻하는 두개의 인자만 있어도 가능하다.
1+2+3 = 6이므로, h(int n, int st, int end)-> h(n-1, st, 6 - st -end), h(n-1, 6 -st -end, end)이렇게 인자 개수를 하나 줄일 수 있다.
*/

#include <bits/stdc++.h>
using namespace std;

void h(int n, int st, int mid, int end){
    if(n==1){
        cout << st << ' ' << end << '\n';
        return;
    }
    h(n-1, st, end, mid);
    cout << st << ' ' << end << '\n';
    h(n-1, mid, st, end);
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;

    cout << (1 << 2) -1 << '\n';//하노이의 탑에서 필요한 횟수는 (2^n) -1

    h(n, 1, 2, 3);

    return 0;
}