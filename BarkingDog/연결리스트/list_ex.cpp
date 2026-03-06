/*
STL list 사용하기
*/

#include <bits/stdc++.h>
using namespace std;


int main(){
    list<int> L = {1,2}; // 1 2
    list<int>::iterator t = L.begin(); // t는 1을 가리키는 중
    
    L.push_front(10); // 10 1 2
    cout << *t << '\n'; // t가 가리키는값 = 1을 출력

    L.push_back(5); // 10 1 2 5
    L.insert(t, 6); // 10 6 1 2 5
    t++; //t가 한칸 전진, 현재 t는 2를 가리킨다.
    
    //t가 가리키는 값 제거. erase함수는 제거완료 후 iterator type을 반환한다.
    //이때 t가 가리키는 값은 2가 사라진 자리를 매꾼 5이다. 따라서 지금 함수의 반환값은 5의 위치이다.
    t = L.erase(t); 
    
    //c++11이상 가능
    for(auto i : L) cout << i << ' ';
    cout << '\n';

    //iterator를 사용하는 방식
    for(list<int>::iterator it = L.begin(); it != L.end(); it++){
        cout << *it << ' ';
    }
    return 0;
}
