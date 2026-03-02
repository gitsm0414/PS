#include<stdio.h>

int main(){
    int n; int res;
    res = 0;
    scanf("%d",&n);

    for(int i=1; i<=n; i++){
        if(i%3==0 || i%5==0) res+=i;
    }
    printf("%d", res);
    return 0;
}