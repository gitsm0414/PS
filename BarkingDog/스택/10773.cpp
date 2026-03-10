/*
BOJ 10773

문제
나코더 기장 재민이는 동아리 회식을 준비하기 위해서 장부를 관리하는 중이다.

재현이는 재민이를 도와서 돈을 관리하는 중인데, 애석하게도 항상 정신없는 재현이는 돈을 실수로 잘못 부르는 사고를 치기 일쑤였다.

재현이는 잘못된 수를 부를 때마다 0을 외쳐서, 가장 최근에 재민이가 쓴 수를 지우게 시킨다.

재민이는 이렇게 모든 수를 받아 적은 후 그 수의 합을 알고 싶어 한다. 재민이를 도와주자!

입력
첫 번째 줄에 정수 K가 주어진다. (1 ≤ K ≤ 100,000)

이후 K개의 줄에 정수가 1개씩 주어진다. 정수는 0에서 1,000,000 사이의 값을 가지며, 정수가 "0" 일 경우에는 가장 최근에 쓴 수를 지우고, 아닐 경우 해당 수를 쓴다.

정수가 "0"일 경우에 지울 수 있는 수가 있음을 보장할 수 있다.

출력
재민이가 최종적으로 적어 낸 수의 합을 출력한다. 최종적으로 적어낸 수의 합은 231-1보다 작거나 같은 정수이다.

Used Algorithms:
Time Complexity: O()

핵심 아이디어
- 

실수
-for문의 조건 부분에서 i < st.size() 라는 조건을 적었다. 이때 간과한 두가지, 첫번째로 비교 대상인 둘의 타입이 다르다는 점(하나는 unsigned), 
두번째로 for문을 한번 반복하고 돌아올 때마다 st.size()라는 함수가 계속 호출될 것이라는것. 이것 또한 치명적인 실수인데, 이는 불필요한 함수 호출을
여러번 반복할 뿐만 아니라, 스택의 경우 매 반복마다 st.size()의 값이 줄어들어 논리적 오류가 발생했다.

다른 관점
-
*/

#include <bits/stdc++.h>
using namespace std;


int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    stack<int> st;

    int sum = 0;
    int k;
    cin >> k;

    while(k--){
        int num;
        cin >> num;
        if(num == 0){
            st.pop();  
        } 
        else{
            st.push(num);           
        } 
    }

    size_t repeat = st.size();
    for(size_t i = 0; i < repeat; i++){//여기서 i < st.size()를 해버리는 치명적 실수를 저지름. 이러면 논리적으로 오류 생김.
        sum += st.top();
        st.pop();
    }

    /*
    st.size()는 std::stack<int>::size_type이다. 이와 int간의 비교연산은 변수가 발생할 수 있기 때문에 다음과같이 대처한다.
    1. i를 size_t로 만들기
    for(size_t i = 0; i < repeat; i++)
    2. static_cast이용
    for(int i = 0; i < static_cast<int>(repeat); i++)
    */

    cout << sum << '\n';
    

    return 0;
}