/*
BOJ 10808
Used Algorithms:
Time Complexity: O(N)

핵심 아이디어
- ASCII 이용한 인덱싱

실수
- 

다른관점
-
*/

#include <bits/stdc++.h>
using namespace std;


int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string s;
    cin >> s;

    //.. = {0, }, .. = {} 다 똑같이 0으로 초기화하는 문법
    //만약 alph_idx[26]; 이렇게 main함수 밖에 전역변수로 설정했다면 이와같은 선언만으로 자동으로 0으로 초기화됨. 참고만.
    int alph_idx[26] = {0}; 

    for(char c : s){
        alph_idx[c-'a']++; // c 와 'a'모두 char(singed인지는 컴파일러 따라..), 하지만 산술연산 있으므로 둘다 int로 promotion된다. 
                           // 따라서 결괏값은 int

        //if(c > 96) 조건에서 주어지므로 굳이 필요없다.
        //alph_idx[c-97]++; 도 'a'를 넣으면 가독성 up
    }

    for(int i : alph_idx){
        cout << i << ' ';
    }
    cout << '\n';

    return 0;
}