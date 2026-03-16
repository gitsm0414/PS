#include <bits/stdc++.h>
using namespace std;


int main(){
    queue<int> Q;
    Q.push(10);
    Q.push(20);
    Q.push(30);//10 20 30
    cout << Q.size() << '\n'; // 3

    if(Q.empty()) cout << "Q is empty\n";
    else cout << "Q is not empty\n";

    Q.pop();// 20 30
    cout << Q.front() << '\n'; //20
    cout << Q.back() << '\n'; //30
    
    while(!Q.empty()) Q.pop();
    //이때 Q.pop(), Q.front(), Q.back()호출하면 런타임 에러

    return 0;
}