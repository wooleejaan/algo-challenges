#include<bits/stdc++.h>
using namespace std;
#define plus pp
#define minus mm
int n, a[12], plus, minus, mult, divi, ret = -1000000001, ret2 = 1000000001;
void go(int idx, int cur, int pl, int mi, int mu, int di){
    if(idx == n-1){
        ret = max(ret, cur);
        ret2 = min(ret2, cur);
        return;
    }
    if(pl) go(idx + 1, cur + a[idx + 1], pl - 1, mi, mu, di);
    if(mi) go(idx + 1, cur - a[idx + 1], pl, mi - 1, mu, di);
    if(mu) go(idx + 1, cur * a[idx + 1], pl, mi, mu - 1, di);
    if(di) go(idx + 1, cur / a[idx + 1], pl, mi, mu, di - 1);
    return;
}
int main(){
    scanf("%d", &n);
    for(int i=0; i<n; i++){
        scanf("%d", &a[i]);
    }
    scanf("%d %d %d %d", &plus, &minus, &mult, &divi);
    go(0, a[0], plus, minus, mult, divi);
    printf("%d\n%d\n", ret, ret2);
    return 0;
}