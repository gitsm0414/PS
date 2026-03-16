#include <bits/stdc++.h>
using namespace std;

//원형큐의 배열을 이용한 간단한 구현
const int MAX = 1000005;
int dat[MAX];
int head = 0;
int tail = 0;

//큐가 비어있는지 확인
bool empty(){
    return head == tail;
}
//큐가 꽉찼는지 확인, 여기서는 1개의 여분이 남은 상태까지만 허용한다. 즉 그상태를 full로 정의한다.
//즉 tail을 한칸 전진했을 때 head와 겹치는가?
bool full(){
    return (tail+1) % MAX == head;
}

void push(int x){
    /*
    if(tail == MAX-1){
        dat[tail] = x;
        tail = 0;
    }else{
        dat[tail++] = x;
    }
    
    1. 원형 큐가 꽊찼을 경우를 고려하지 않았다.
    2. %를 이용해 코드 단순화 가능
    */
    
    if(full()) return;
    dat[tail] = x;
    tail = (tail + 1) % MAX; // tail의 값 업데이트

}

void pop(){
    /*
    if(head == MAX-1) head = 0;
    else head++;
    1. 원형 큐가 꽊찼을 경우를 고려하지 않았다.
    2. %를 이용해 코드 단순화 가능
    */
    if(empty()) return; 
    head = (head + 1) % MAX;

}

int front(){
    return dat[head];
}

int back(){
    //return (tail == 0 ? dat[MAX-1] : dat[tail-1]);
    //다음과 같이 단순화 가능
    return dat[(tail - 1 + MAX) % MAX]; //tail - 1이 음수가 되는 것을 막기 위해 + MAX를 함으로 써 한바퀴 더 돌려준다.
}

int size(){
    //만약 tail값이 head보다 작은 경우 음수가 나오므로 tail을 한바꾸 더 돌려서 거기서 tail - head를 하면 올바른 양수값이 나온다.
    //이를 모든 경우에 대해 대응하도록 식을 짜면 다음과 같다. (tail + MAX - head) % MAX;
    return (tail + MAX - head) % MAX;
}


int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);



    return 0;
}