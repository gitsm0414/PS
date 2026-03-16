/*
야매 링크드리스트 테스트

시각화를 하고 코드를 짜는 게 도움된다.
*/

#include <bits/stdc++.h>
using namespace std;

const int MX = 1000005;
int dat[MX], pre[MX], nxt[MX];
int unused = 1;

void insert(int addr, int num){//새 노드를 addr주소 상의 바로 다음 위치에 삽입한다.
    
  //삽입할 노드의 데이터 추가
  dat[unused] = num;
  //추가된 노드의 화살표를 이어주기
  pre[unused] = addr;
  nxt[unused] = nxt[addr];

  //기존 화살표들을 새로 삽입된 데이터의 주소를 가리키게끔하기
  if(nxt[addr] != -1) pre[nxt[addr]] = unused;//얘를 먼저해야함. 순서 중요.
  nxt[addr] = unused;
          
  unused++;
  }

void erase(int addr){//이 코드보다 아래 함수를 쓸 수 있도록 하자 앞으로.
  if(nxt[addr] != -1){//만약 중간에 있는 값을 제거할 시 앞뒤 노드의 정보를 모두 수정한다.
    nxt[pre[addr]] = nxt[addr];
    pre[nxt[addr]] = pre[addr];
  }else{//아닌 경우 새로운 말단이 되는 데이터의 nxt화살표를 초기화시킨다.
    nxt[pre[addr]] = -1;
  }
}
/*
cf. 이와같이 코드를 좀더 단순화시킬 수 있다. 이 코드와 사고과정을 익히도록하자.
void erase(int addr){
    // 1. 이전 노드의 nxt를 나의 nxt로 연결
    nxt[pre[addr]] = nxt[addr];
    
    // 2. 다음 노드의 pre를 나의 pre로 연결 (다음 노드가 존재할 때만)
    if(nxt[addr] != -1) pre[nxt[addr]] = pre[addr];
}
*/

void traverse(){
  int cur = nxt[0];
  while(cur != -1){
    cout << dat[cur] << ' ';
    cur = nxt[cur];
  }
  cout << "\n\n";
}

void insert_test(){
  cout << "****** insert_test *****\n";
  insert(0, 10); // 10(address=1)
  traverse();
  insert(0, 30); // 30(address=2) 10
  traverse();
  insert(2, 40); // 30 40(address=3) 10
  traverse();
  insert(1, 20); // 30 40 10 20(address=4)
  traverse();
  insert(4, 70); // 30 40 10 20 70(address=5)
  traverse();
}

void erase_test(){
  cout << "****** erase_test *****\n";
  erase(1); // 30 40 20 70
  traverse();
  erase(2); // 40 20 70
  traverse();
  erase(4); // 40 70
  traverse();
  erase(5); // 40
  traverse();
}

int main(void) {
  fill(pre, pre+MX, -1);
  fill(nxt, nxt+MX, -1);
  
  insert_test();
  erase_test();
}