/*
BOJ 15650 nm2
Used Algorithms:
Time Complexity: O()

핵심 아이디어
- 

실수
- 

다른 관점
>>다른사람의 방식을 내 코드에 접합시킴
#include <bits/stdc++.h>
using namespace std;


int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;

    vector<int> v(n);
    //원래 vector<int> used(n,0)있었지만 여기선 필요없다. 하지만 이런 특별한 조건에서만 가능하므로 isused를 사용하는게 더 보편적이고 융통성있는
    //코드를 짤 수 있다는것만 알아두자. 따라서 이 주석의 코드보다는 아래에 내가 직접 쓴 코드가 좀더 유연하다.
    vector<int> pick(m);

    for(int i = 0; i < n; i++) cin >> v[i];

    sort(v.begin(), v.end());

    string out = "";

    
    function<void(int, int)> backtrack = [&](int idx, int st)
    {
        if(idx == m){
            for(int i = 0; i < m; i++){
                out += to_string(pick[i]);
                out += ' ';
            }
            out += '\n';
            return;
        }
        int last_val = -1;//현재 idx에서 가장 최근에 쓰인 값, 이값과 v[i]가 동일하다면 중복을 의미한다.

        for(int i = st; i < n; i++){
            if(last_val == v[i]) continue;

            pick[idx] = v[i];
            last_val = v[i];      
            backtrack(idx+1, i+1);
            
        }
    };
    backtrack(0,0);
    cout << out;

    return 0;
}
*/

#include <bits/stdc++.h>
using namespace std;


int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;

    vector<int> v(n);
    vector<int> used(n,0);
    vector<int> pick(m);

    for(int i = 0; i < n; i++){
        cin >> v[i];
        //v.push_back(tmp); 이미 앞에서 v(n)으로 0을 n개 넣고 초기화했으므로 이러면 원소가 2n개 되버린다.
    }
    sort(v.begin(), v.end());

    string out = "";

    //cf. function<void(int, int)>쓸려면 원래는 #include<fucntional> 해야함
    function<void(int, int)> backtrack = [&](int idx, int st)
    {//람다함수 앞에 function<void(int,int)>명시해줌으로써 함수안에서 재귀 가능하게한다.
        if(idx == m){
            for(int i = 0; i < m; i++){
                out += to_string(pick[i]); //include<string>
                out += ' ';
            }
            out += '\n';
            return;
        }
        for(int i = st; i < n; i++){
            //v[i] == v[i-1]라면 v[i-1]가 v[i]의 역할을 이미 전에 했을 수도 있다. 가능성이 있다.
            //v[i-1]이 현재 pick에 쓰이지 않았다면 이전 pick에서 이미 현재 v[i]의 역할을 수행한것이다. 즉 v[i]는 지금 뒷북치는 상황이다.
            if(i>0 && v[i] == v[i-1] && !used[i-1]) continue;
            pick[idx] = v[i];
            used[i] = 1;
            backtrack(idx+1, i+1);
            used[i] = 0;
        }
    };
    backtrack(0,0);
    cout << out;

    return 0;
}
