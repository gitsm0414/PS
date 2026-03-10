<스택>
스택, 덱, 큐의 공통점을 묶어 Restricted Structure라고 부르기도한다.

1. 원소의 추가 O(1)
2. 원소의 제거 O(1)
3. 제일 상단의 원소확인 O(1)
4. 제일 상단이 아닌 나머지 원소들의 확인/변경이 원칙적으로 불가


<STL stack>
using namespace std;
...
stack<int> S;
S.push(10);
S.pop();
if(S.empty()) ...
cout << S.top() << '\n';

>> 만약 스택이 비어있는데, pop() 혹은 top()을 호출하면 런타임에러가 발생하니 이를 방지할 수 있도록 코드를짜자.


