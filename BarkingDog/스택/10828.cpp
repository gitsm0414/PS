/*
BOJ 10828

정수를 저장하는 스택을 구현한 다음, 입력으로 주어지는 명령을 처리하는 프로그램을 작성하시오.

명령은 총 다섯 가지이다.

push X: 정수 X를 스택에 넣는 연산이다.
pop: 스택에서 가장 위에 있는 정수를 빼고, 그 수를 출력한다. 만약 스택에 들어있는 정수가 없는 경우에는 -1을 출력한다.
size: 스택에 들어있는 정수의 개수를 출력한다.
empty: 스택이 비어있으면 1, 아니면 0을 출력한다.
top: 스택의 가장 위에 있는 정수를 출력한다. 만약 스택에 들어있는 정수가 없는 경우에는 -1을 출력한다.

입력
첫째 줄에 주어지는 명령의 수 N (1 ≤ N ≤ 10,000)이 주어진다. 둘째 줄부터 N개의 줄에는 명령이 하나씩 주어진다. 주어지는 정수는 1보다 크거나 같고, 100,000보다 작거나 같다. 문제에 나와있지 않은 명령이 주어지는 경우는 없다.

출력
출력해야하는 명령이 주어질 때마다, 한 줄에 하나씩 출력한다.

Used Algorithms:
Time Complexity: O()

핵심 아이디어
- 

실수
- 

다른 관점
-스택명.size()로 size함수부분을 이용할 수 있다. 명심하기.
-스택에서 top(), pop()을 호출할땐 무조건 비어있지 않은지 미리 체크하고 사용해야함을 명심합시다.
*/

#include <bits/stdc++.h>
using namespace std;


int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    stack<int> st;

    int size = 0; //st.size()를 이용하면 되기 때문에 사실상 필요없었다.
    string s;
    int n;
    cin >> n;
    while(n--){
        cin >> s;
        if(s == "push"){
            int num;
            cin >> num;
            st.push(num);
            size++;
        }else if(s == "pop"){//스택에서 가장 위에 있는 정수를 빼고, 그 수를 출력한다. 만약 스택에 들어있는 정수가 없는 경우에는 -1을 출력한다.
            if(st.empty()){
                cout << -1 << '\n';
            } 
            else{
                int num;
                num = st.top();
                cout << num << '\n';
                st.pop();
                size--;
            }
            /*
            여기서 코드 단순화하는 방법
            else{
                cout << st.top() << '\n';
                st.pop();
            }
            */
        }else if(s == "size"){
            cout << size << '\n';

        }else if(s == "empty"){//스택이 비어있으면 1, 아니면 0을 출력한다.
            if(size == 0) cout << 1 << '\n';
            else if(size>0) cout << 0 << '\n';

        }else if(s == "top"){//스택의 가장 위에 있는 정수를 출력한다. 만약 스택에 들어있는 정수가 없는 경우에는 -1을 출력한다.
            if(st.empty()){
                cout << -1 << '\n';
            }else{
                cout << st.top() << '\n';
            }
        }
    }

    

    return 0;
}