#include <bits/stdc++.h>
using namespace std;


int main(){
    deque<int> DQ;

    DQ.push_front(10);
    DQ.push_back(50);
    DQ.push_front(24);
    //24 10 50
    
    for(auto x : DQ) cout << x << ' ';
    cout << DQ.size() << '\n';

    if(DQ.empty()) cout << "DQ is empty\n";

    DQ.pop_front();
    DQ.pop_back();
    //10
    DQ.push_front(15);
    //15 10

    //DQ[2] = 12; //인덱스 범위는 유효한 범위여야한다. 현재 size: 2이므로 경계를 벗어난다.
    //즉 인덱스로 접근한다는 것은 "이미 존재하는 index:2 칸의 값을 바꿔라"로 해석할 수 있다. 다만 insert의 경우 다르다.

    DQ.insert(DQ.begin()+1, 5); //15 5 10
    DQ.insert(DQ.begin()+3, 7); //15 5 10 7
    /*
    인덱스와 달리 insert는 맨끝 원소 한칸 뒤에도 원소를 새로 삽입할 수 있었다. 왜냐하면 insert는
    "?번째 칸을 새로 추가해 값을 넣어라"로 해석되기 때문이다. 실제로 마지막 상황에서 DQ.begin()+3 = DQ.end() 였다.
    다만 다른 원소들이 밀려나기 때문에 O(N)이다.
    */
    DQ.erase(DQ.begin()+1); //15 10 7
    DQ.clear(); //모든 원소 제거

    return 0;
}