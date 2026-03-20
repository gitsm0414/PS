//배열을 이용한 deque의 구현, pop, front, back에서 덱이 비어있는지 미리 체크하는 부분은
//함수 바깥에서 체크하도록 의도한다면 굳이 꼭 포함시킬 필요는 없다. 하지만 여기선 포함시켰다.

#include <bits/stdc++.h>
using namespace std;

const int MX = 1000005;
const int MAX = 2*MX + 1;
int dat[MAX];
int head = MX;
int tail = MX;
//사실 덱을 원형으로 구현했기 때문에 head, tail의 시작위치는 상관없다. 0으로 해도 괜찮다.

bool empty(){
    return tail == head;
}

bool full(){
    return (tail + 1) % MAX == head;
}

int size(){
    return (tail + MAX - head) % MAX;
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

void pop_front(){
    if(empty()) return;
    head = (head + 1) % MAX;
}

void pop_back(){
    if(empty()) return;
    tail = (tail - 1 + MAX) % MAX;
}

// front와 back의 경우 return type int이기 때문에 그냥 return은 컴파일 에러를 일으킨다.
int front(){
    if(empty()) return -1;
    return dat[head];

}

int back(){
    if(empty()) return -1;
    return (tail == 0 ? dat[MAX-1] : dat[tail-1]); //연산속도는 이게 빠름
    //return dat[(tail - 1 + MAX) % MAX];
}

int main(){
    

    return 0;
}