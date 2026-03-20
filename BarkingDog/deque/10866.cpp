/*
BOJ 10866

문제
정수를 저장하는 덱(Deque)를 구현한 다음, 입력으로 주어지는 명령을 처리하는 프로그램을 작성하시오.


push_front X: 정수 X를 덱의 앞에 넣는다.
push_back X: 정수 X를 덱의 뒤에 넣는다.
pop_front: 덱의 가장 앞에 있는 수를 빼고, 그 수를 출력한다. 만약, 덱에 들어있는 정수가 없는 경우에는 -1을 출력한다.
pop_back: 덱의 가장 뒤에 있는 수를 빼고, 그 수를 출력한다. 만약, 덱에 들어있는 정수가 없는 경우에는 -1을 출력한다.
size: 덱에 들어있는 정수의 개수를 출력한다.
empty: 덱이 비어있으면 1을, 아니면 0을 출력한다.
front: 덱의 가장 앞에 있는 정수를 출력한다. 만약 덱에 들어있는 정수가 없는 경우에는 -1을 출력한다.
back: 덱의 가장 뒤에 있는 정수를 출력한다. 만약 덱에 들어있는 정수가 없는 경우에는 -1을 출력한다.

입력
첫째 줄에 주어지는 명령의 수 N (1 ≤ N ≤ 10,000)이 주어진다. 둘째 줄부터 N개의 줄에는 명령이 하나씩 주어진다. 
주어지는 정수는 1보다 크거나 같고, 100,000보다 작거나 같다. 문제에 나와있지 않은 명령이 주어지는 경우는 없다.

출력
출력해야하는 명령이 주어질 때마다, 한 줄에 하나씩 출력한다.

Used Algorithms: 배열을 이용한 원형 deque의 구현
Time Complexity: O()

핵심 아이디어
- deque.cpp에서 구현한 내용을 재활용했다. 다만 함수를 너무 많이 활용하여 비효율적인 부분은 있다.

실수
- 

다른 관점
-
*/

#include <bits/stdc++.h>
using namespace std;

const int MAX = 10005;
int dat[MAX];
int head = 0;
int tail = 0;

int empty(){
    return (tail == head ? 1 : 0);
}

int full(){
    return ((tail + 1) % MAX == head ? 1 : 0);
}

int size(){
    return (tail + MAX - head) % MAX;
}

int front(){
    if(empty()) return -1;
    return dat[head];
}

int back(){
    if(empty()) return -1;
    return (tail == 0 ? dat[MAX-1] : dat[tail-1]); // tail = 0 ? 이것 때문에 런타임에러 발생
}

void push_front(int x){
    if(full()) return;
    head = (head - 1 + MAX) % MAX;
    dat[head] = x;
}

void push_back(int x){
    if(full()) return;
    dat[tail] = x;
    tail = (tail + 1) % MAX;
}

int pop_front(){
    int i = front();
    if(i == -1) return -1;
    else{
        head = (head + 1) % MAX;
        return i;
    }
}

int pop_back(){
    int i = back();
    if(i == -1) return -1;
    else{
        tail = (tail - 1 + MAX) % MAX;
        return i;
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    int x;
    while(n--){
        
        string s;
        cin >> s;

        if(s == "push_front"){
            cin >> x;
            push_front(x);
        }
        else if(s == "push_back"){
            cin >> x;
            push_back(x);
        }
        else if(s == "pop_front"){
            cout << pop_front() << '\n';
        }
        else if(s == "pop_back"){
            cout << pop_back() << '\n';
        }
        else if(s == "size"){
            cout << size() << '\n';
        }
        else if(s == "empty"){
            cout << empty() << '\n';
        }
        else if(s == "front"){
            cout << front() << '\n';
        }
        else if(s == "back"){
            cout << back() << '\n';
        }
    }

    return 0;
}