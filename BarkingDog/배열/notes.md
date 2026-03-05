배열의 성질
1. O(1)에 k번째 원소를 확인/변경 가능
2. 추가적으로 소모되는 메모리의 양(= overhead)가 거의 없음
3. Cashe hit rate가 높음
4. 메모리상에 연속한 구간을 잡아야해서 할당에 제약이 걸림


임의의 원소를 확인/변경, 마지막에 원소 추가, 마지막에 원소 제거: O(1)
임의의 위치에 원소를 삽입/제거: O(n)


<배열의 초기화>
1. memset() >> 비추
2. for문 직접 돌려 하나하나 넣기 >> 실수여지 없음
3. fill()

int a[21];
int b[21][21];

//a초기화(0으로)
fill(a, a+21, 0);

//b초기화(0으로)
for(int i = 0; i < 21; i++){
    fill(b[i], b[i]+21, 0);
}


<STL vector>
활용 예시: vector_ex.cpp를 참고하실것

vector로 for문을 돌리는 잘못된 예시:
*vector의 size메소드는 반환 타입이 unsigned(컴파일러 따라서 int or long long)이다. 따라서 vec.size() - 1을 보면,
만약 vec가 빈 벡터라면 vec.size() = 0 (unsigned)이다. 이때 0(u) - 1 
즉, unsigned 와 signed가 만나는 연산일 경우 unsigned로 자동 형변환 처리되어 결과값이 4294967295가 되버린다.
따라서 for문을 계속해서 돌다가( vec[0], vec[1], ... ) 런타임 에러가 발생한다. 



