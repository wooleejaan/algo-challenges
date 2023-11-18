#include <bits/stdc++.h>
using namespace std;
bool che[4000001];
int n, a[2000001], p, lo, hi, ret, sum;
int main(){
    scanf("%d", &n);
    for(int i=2; i<=n; i++){
        if(che[i]) continue;
        for(int j=2*i; j<=n; j+=i){
            che[j] = 1;
        }
    }
    for(int i=2; i<=n; i++){
        if(!che[i]) a[p++] = i;
    }
    while(1){
        if(sum >= n) sum -= a[lo++];
        else if(hi == p) break;
        else sum += a[hi++];

        if(sum == n) ret++;
    }
    printf("%d\n", ret);
    return 0;
}