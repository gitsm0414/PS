/*
바킹독 0x01 연습문제
>> 주어진 길이 N<=1000의 int 배열, 각 원소 0<=x<=100, 합이 100인 서로다른 두 원소 존재하면 1, 아니면 0을 리턴하는 함수 작성. 

Used Algorithms:
Time Complexity: 기본적으로 떠올렸을 땐 O(N^2), 잘만하면 O(N)까지

핵심 아이디어
-freq배열(a.k.a. occur배열을 이용하기) 

실수
- 

다른 관점
-나는 단계적으로, 절차적으로 생각해 그대로 옮겼는데, 
좀만 더 생각해보면 for문 하나만으로도 모든 작업을 수행할 수 있다.
시간 복잡도에는 차이가 없다.
*/

#include <bits/stdc++.h>
using namespace std;

/*
바킹독 버전
int func(int arr[], int N){
    int occur[101] = {};

    for(int i =0; i < N; i++){
        ocuur[arr[i]]++;
        if(occur[100-arr[i]]) return 1;
    }
        return 0;
}

*/

int func(int* arr, int n){
    int freq[101] = {}; // 0으로 초기화

    for(int i = 0; i < n; i++){
        freq[arr[i]]++;
    }
    for(int i = 0; i < 50; i++){
        if(freq[i] > 0 && freq[100-i] > 0) return 1;
    }
    if(freq[50] > 1) return 1;

    return 0;
}


int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    

    return 0;
}