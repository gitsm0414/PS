/*
BOJ 1629 곱셈
Used Algorithms:
Time Complexity: O(log b)

핵심 아이디어
- a^2n mod c = a^n * a^n mod c = (a^n mod c)*(a^n mod c) mod c 임을 이용한다.
- a^(2n+1) mod c =  (a^n * a^n * a) mod c = (a^n mod c)*(a^n mod c)*(a mod c) mod c

실수
- 

다른 관점
-
*/

#include <bits/stdc++.h>
using namespace std;
using ll = long long;



ll pow(int a, int b, int c){
    if(b==1) return a % c;
    ll val = pow(a, b/2, c);
    //b 짝수
    if(b%2 == 0)
        val = val * val % c;
    else{//b 홀수
        val = val * val % c;
        val = val * a % c;
    }
    return val;

}


int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    ll a, b, c;
    cin >> a >> b >> c; 
    cout << pow(a,b,c);   

    return 0;
}