/*
BOJ 15650 nm2
Used Algorithms:
Time Complexity: O()

핵심 아이디어
- 

실수
- 

다른 관점
>>set insert의 특성을 이용
void f(int idx) {
    if (idx == M) {
        // insert는 (iterator, 성공여부) 쌍을 반환합니다.
        // 이미 있으면 .second가 false, 새로 들어갔으면 true입니다.
        if (lib.insert(res).second) { 
            for (int i = 0; i < M; i++) cout << res[i] << ' ';
            cout << '\n';
        }
        return;
    }
    // ... 이하 동일 이 경우 isRedundant()도 필요없다.
}
다른 사람의 제출 코드

#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int n,m;
    cin >> n >> m;
    
    vector<int> v(n);
    for(int i=0;i<n;i++)
        cin >> v[i];
    
    sort(v.begin(),v.end());
    
    vector<int> pick(m);
    vector<char> used(n,0);
    
    string out;
    
    function<void(int)> dfs = [&](int depth)
    {
        if(depth == m)
        {
            for(int i=0;i<m;i++)
            {
                if(i) out += ' ';
                out += to_string(pick[i]);
            }
            out += '\n';
            return;
        }
        //cout을 매번 부르는 대신, string에 모든 결과를 다 담아두었다가 마지막에 딱 한 번만 출력합니다. 
        //데이터 양이 많을 때 출력 속도를 비약적으로 높이는 기법입니다.

        for(int i=0;i<n;i++)
        {
            if(used[i]) continue;
            
            //인풋v가 정렬돼있다는 특징으로부터 나오는 규칙성을 잘 이용한 부분. 이로인해 나와달리 set<vector<int>>필요없음. 공간절약가능.
            //v[i] == v[i - 1] && !used[i-1]이말은 전에도 이미 똑같은 값의 수열 pick이 진행되었음을 알수있다.
            
            if (v[i] == v[i - 1] && !used[i-1]) continue;
            
            used[i] = 1;
            pick[depth] = v[i];
            dfs(depth+1);
            used[i] = 0;
        }
        
    };
    
    dfs(0);
    cout << out;
   
    return 0;
}
*/

/*
vector의 resize() 이해돕기위한 예시. 보통 벡터를 인덱스로 미리 접근하고싶을 때 사용한다. 새 원소를 생성/초기화 한다.
이떄 reserve()는 메모리 공간만 미리 빌려두는 개념으로, 인덱스 미리접근시 오류가나고, 이는 그저 push_back()성능을 올리기 위한 함수임을 알아두자.

vector<int> v = {1, 2, 3};

// 1. 크기를 5로 늘리기 (나머지는 0으로 채워짐)
v.resize(5);  // {1, 2, 3, 0, 0}

// 2. 크기를 8로 늘리되, 새 원소를 7로 채우기
v.resize(8, 7); // {1, 2, 3, 0, 0, 7, 7, 7}

// 3. 크기를 2로 줄이기
v.resize(2); // {1, 2}
*/

#include <bits/stdc++.h>
using namespace std;

int N, M;
int isused[10];
int input[10];
vector<int> res;
set<vector<int>> lib;

bool isRedundant(const vector<int> &v){//is it redundant?
    if(lib.find(v) == lib.end()) return false;
    else return true;
}

void f(int idx){
    if(idx == M){
        if(isRedundant(res)) return;
        //add to lib
        lib.insert(res);
        //print
        for(int i = 0; i < M; i++) cout << res[i] << ' ';
        cout << '\n';

        return;
    }
    for(int i = 0; i < N; i++){
        if(isused[i]) continue;
        res[idx] = input[i];
        isused[i] = 1;
        f(idx+1);
        isused[i] = 0;
    }

}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> N >> M;
    for(int i = 0; i < N; i++){
        cin >> input[i];
    }
    sort(input, input+N);
    
    res.resize(M); // 중요: 인덱스 접근(res[idx])을 위해 미리 크기를 M으로 고정
    f(0);

    return 0;
}