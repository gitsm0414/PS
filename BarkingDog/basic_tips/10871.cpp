//이 코드는 바킹독이 작성한 코드. 참고용
/*

문제
정수 N개로 이루어진 수열 A와 정수 X가 주어진다. 이때, A에서 X보다 작은 수를 모두 출력하는 프로그램을 작성하시오.

입력
첫째 줄에 N과 X가 주어진다. (1 ≤ N, X ≤ 10,000)

둘째 줄에 수열 A를 이루는 정수 N개가 주어진다. 주어지는 정수는 모두 1보다 크거나 같고, 10,000보다 작거나 같은 정수이다.

출력
X보다 작은 수를 입력받은 순서대로 공백으로 구분해 출력한다. X보다 작은 수는 적어도 하나 존재한다.


#include<bits/stdc++.h>
using namespace std;
int main(void){
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int n, x, t;
    cin >> n >> x;
    
    while(n--){
        cin >> t;
        if(t < x) cout << t << ' ';
    }
}
이렇듯 불필요하게 헤더를 포괄적으로 가져오거나, main함수 바로 밑 두줄의 명령어나,
실제 협엽등에서 중요할 수 있는 가독성이나 유지보수 이런걸 고려하지 않고
코테에서는 내가 이해할 수 있는, 그리고 어디까지나 목적은 문제만 풀면 된다 임을 새겨두자.
*/




#include<iostream>
using namespace std;

int main(){
    int n, x;
    cin >> n >> x;
    int* arr = new int[n];

    for(int i = 0; i < n; i++){
        cin >> arr[i];
    }

    for(int i = 0; i < n; i++){
        if(arr[i] < x){
            cout << arr[i] << ' ';
        }
    }
    
    delete [] arr;
    return 0;
}

