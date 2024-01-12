#include <bits/stdc++.h>
using namespace std;
int n, lis[1004], len, num;
int main(){
    scanf("%d", &n);
    for(int i=0; i<n; i++){
        scanf("%d", &num);  
        auto lowerPos = lower_bound(lis, lis + len, num);
        if(*lowerPos == 0) len++;
        *lowerPos = num;
    }
    printf("%d\n", len);
    return 0;
}