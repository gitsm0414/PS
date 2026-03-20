<deque>: double ended queue (덱)
1. 원소의 추가 O(1)
2. 원소의 제거 O(1)
3. 앞/뒤 원소 확인 O(1)
4. 양끝이 아닌 원소들은 원칙적으로 확인 불가 but STL queue에서는 인덱스로 원소를 확인가능


STL deque: 
vector와 상당히 유사하다. 
덱인데도 불구하고, insert(), erase(), 혹은 인덱스로 접근이 가능하다.
다만 vector와 달리 STL deque는 원소들이 연속적으로 위치하고있지 않다는 특징이 있다. 
따라서 꼭 앞쪽에서도 원소의 삽입/제거가 필요한 경우가 아니라면 vector를 쓰는 것이 효율적이다.