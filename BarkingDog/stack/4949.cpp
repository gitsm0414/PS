/*
BOJ 4949

문제
세계는 균형이 잘 잡혀있어야 한다. 양과 음, 빛과 어둠 그리고 왼쪽 괄호와 오른쪽 괄호처럼 말이다.

정민이의 임무는 어떤 문자열이 주어졌을 때, 괄호들의 균형이 잘 맞춰져 있는지 판단하는 프로그램을 짜는 것이다.

문자열에 포함되는 괄호는 소괄호("()") 와 대괄호("[]")로 2종류이고, 문자열이 균형을 이루는 조건은 아래와 같다.

모든 왼쪽 소괄호("(")는 오른쪽 소괄호(")")와만 짝을 이뤄야 한다.
모든 왼쪽 대괄호("[")는 오른쪽 대괄호("]")와만 짝을 이뤄야 한다.
모든 오른쪽 괄호들은 자신과 짝을 이룰 수 있는 왼쪽 괄호가 존재한다.
모든 괄호들의 짝은 1:1 매칭만 가능하다. 즉, 괄호 하나가 둘 이상의 괄호와 짝지어지지 않는다.
짝을 이루는 두 괄호가 있을 때, 그 사이에 있는 문자열도 균형이 잡혀야 한다.
정민이를 도와 문자열이 주어졌을 때 균형잡힌 문자열인지 아닌지를 판단해보자.

입력
각 문자열은 마지막 글자를 제외하고 영문 알파벳, 공백, 소괄호("( )"), 대괄호("[ ]")로 이루어져 있으며, 온점(".")으로 끝나고, 길이는 100글자보다 작거나 같다.

입력의 종료조건으로 맨 마지막에 온점 하나(".")가 들어온다.
출력
각 줄마다 해당 문자열이 균형을 이루고 있으면 "yes"를, 아니면 "no"를 출력한다.

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
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    stack<char> st;
    string s;

    while(getline(cin, s, '.')){//c++에서 getline은 첫번째 인자인 스트림을 리턴한다. 이는 상태가 정상인지 아닌지 bool로써 이용할 수 있다.
        
        if(s == "\n" || s == "") break; //. 과 . 사이에 '\n'만 있거나 .. 이렇게 연속인 경우에 종료신호로 인식한다.

        bool balance = true;
        st = {}; //초기화
        for(char c : s){
            if(!balance) break;

            switch(c){
                case '(':
                    st.push(c);
                    break;

                case '[':
                    st.push(c);
                    break;

                case ')':
                    if(st.empty()){//더이상 뺄 괄호가 없을 경우
                        balance = false;
                    } 
                    else if(st.top() != '('){//괄호는 있는데 쌍이 안맞는 경우
                        balance = false;
                    }
                    else st.pop();//짝 맞는 경우 pop
                    break;

                case ']':
                    if(st.empty()){
                        balance = false;
                    } 
                    else if(st.top() != '['){
                        balance = false; 
                    }
                    else st.pop();
                    break;
            }
        }
        if(!balance) cout << "no\n";
        else if(!st.empty()) cout << "no\n";
        else cout << "yes\n";
    }

    return 0;
}