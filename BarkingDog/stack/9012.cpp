/*
BOJ 9012

문제
괄호 문자열(Parenthesis String, PS)은 두 개의 괄호 기호인 ‘(’ 와 ‘)’ 만으로 구성되어 있는 문자열이다. 
그 중에서 괄호의 모양이 바르게 구성된 문자열을 올바른 괄호 문자열(Valid PS, VPS)이라고 부른다. 한 쌍의 괄호 기호로 된 “( )” 문자열은 기본 VPS 이라고 부른다. 
만일 x 가 VPS 라면 이것을 하나의 괄호에 넣은 새로운 문자열 “(x)”도 VPS 가 된다. 그리고 두 VPS x 와 y를 접합(concatenation)시킨 새로운 문자열 
xy도 VPS 가 된다. 예를 들어 “(())()”와 “((()))” 는 VPS 이지만 “(()(”, “(())()))” , 그리고 “(()” 는 모두 VPS 가 아닌 문자열이다. 

여러분은 입력으로 주어진 괄호 문자열이 VPS 인지 아닌지를 판단해서 그 결과를 YES 와 NO 로 나타내어야 한다. 

입력
입력 데이터는 표준 입력을 사용한다. 입력은 T개의 테스트 데이터로 주어진다. 입력의 첫 번째 줄에는 입력 데이터의 수를 나타내는 정수 T가 주어진다. 
각 테스트 데이터의 첫째 줄에는 괄호 문자열이 한 줄에 주어진다. 하나의 괄호 문자열의 길이는 2 이상 50 이하이다. 

출력
출력은 표준 출력을 사용한다. 만일 입력 괄호 문자열이 올바른 괄호 문자열(VPS)이면 “YES”, 아니면 “NO”를 한 줄에 하나씩 차례대로 출력해야 한다. 

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


int main(){
    ios::sync_with_stdio(false); // C/C++의 stdio 동기화가 끊긴다. 따라서 이거 써져있으면 섞어쓰지말고 둘중하나만 선택
    cin.tie(nullptr);

    stack<char> st;
    int t;
    cin >> t;

    while(t--){//사실 여기서 C말고 C++방식으로 바꾸긴 해야함. 아니면 ios::sync_with_stdio(false);를 지우던가.
        char str[51] = {};
        scanf("%s", str);
        //getchar();는 필요없다. 왜냐하면 scanf("%s", str)은 맨 앞에 ' ' '\t' '\n'등을 만날 경우 이것들이 아닌 문자가
        //처음으로 나올 때 까지 걔네들을 읽지 않고 버린다. 따라서 필요없다. 이는 scanf("%c")나 getline()등의 경우에 필요하다.

        st = {}; //스택 초기화 안해서 틀림
        bool vps = true;
        for(char* p = str; *p != '\0'; p++){
            if(*p == '('){
                st.push(*p);
            }else if(*p == ')'){
                if(st.empty() || st.top() != '('){//왼쪽이 true면 오른쪽은 보지도않는다.
                    vps = false;
                    break;
                }
                else st.pop();
            }
        }
        if(!vps) cout << "NO\n";
        else if(!st.empty()) cout << "NO\n";
        else cout << "YES\n";
    }

    return 0;
}