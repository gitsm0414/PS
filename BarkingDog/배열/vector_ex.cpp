#include <bits/stdc++.h>
using namespace std;

int main(void){
    vector<int> v1(3,5); // {5, 5, 5}
    cout << v1.size() << '\n'; // 3
    v1.push_back(7); //{5, 5, 5, 7}

    vector<int> v2(2); // {0, 0}
    v2.insert(v2.begin()+1, 3); // {0, 3, 0}

    vector<int> v3 = {1, 2, 3, 4};
    v3.erase(v3.begin()+2); // {1, 2, 4}

    vector<int> v4; // {}
    v4 = v3; // {1,2,4}
    cout << v4[0] << v4[1] << v4[2] << '\n';
    v4.pop_back(); //{1, 2}
    v4.clear(); // {} 아예 태초로 돌아간다. 0초기화 상태가 아니라.
    

    vector<int> vec = {1,2,3,4,5,6};

    //range-based for-loop
    for(int e : vec){ // int& e : vec도 가능
        cout << e << ' ';
    }

    //not bad
    for(int i = 0; i < vec.size(); i++){
        cout << vec[i] << ' ';
    }

    //WRONG! check the notes.md
    for(int i = 0; i <= vec.size()-1; i++){
        cout << vec[i] << ' ';
    }
}
