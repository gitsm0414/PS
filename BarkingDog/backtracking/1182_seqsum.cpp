/*
BOJ 1182 부분수열의 합
Used Algorithms:
Time Complexity: O(2^N)

핵심 아이디어
- 부분수열: 주어진 수열에서 추출한 수열, 이때 각 항 간의 '상대적 순서관계'는 그대로 유지되야 한다.

실수
- 

다른 관점
-인풋수열의 각 항을 부분수열에 포함할지말지 2가지로 나누어 보는 관점이 있다. 아래 코드 참고.
물론 이 경우 부분수열이 공집합인 경우도 포함하기 때문에 S = 0이라면 공집합도 cnt를 증가시키게 된다. 
따라서 이때만 cnt--를 한번 해주면 예외처리 가능하다.

void f(int cur, int total) {
    if (cur == N) { // 모든 원소를 다 결정했을 때
        if (total == S) cnt++;
        return;
    }
    // 1. 현재 원소를 포함하는 경우
    f(cur + 1, total + input[cur]);
    // 2. 현재 원소를 포함하지 않는 경우
    f(cur + 1, total);
}

... f(0, 0);
*/

#include <bits/stdc++.h>
using namespace std;

int N, S;
int sum = 0;
int cnt = 0;

int input[21]; //인풋 수열
int idx_arr[21]; //현재 만들어진 부분수열의 idx를 값으로하는 배열

void f(int k){
    if(k > 0 && idx_arr[k-1] == N-1) return;

    int index = (k > 0 ?  idx_arr[k-1] : -1);

    for(int i = index+1; i < N; i++){ //부분수열의 이전 항 바로 다음 항부터 끝까지 범위에 대해..
        idx_arr[k] = i; //부분수열에 추가
        sum += input[i]; //합 적용
        if(sum == S) cnt++;
        
        f(k+1);
        sum -= input[i];
    }

}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> N >> S;  
    for(int i = 0; i < N; i++) cin >> input[i];  
    f(0);
    cout << cnt;

    return 0;
}