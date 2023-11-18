#include <bits/stdc++.h>
using namespace std;
long long s, e, cnt[100001], n, a[100001], ret;
int main(){
    scanf("%d", &n);
    for(int i=0; i<n; i++){
        scanf("%lld", a + i);
    }
    while(e < n){
        if(!cnt[a[e]]){
            cnt[a[e]]++;
            e++;
        } else {
            ret += (e - s);
            cnt[a[s]]--;
            s++;
        }
    }
    ret += (long long)(e - s) * (e - s + 1) / 2; 
    printf("%lld\n", ret);
    return 0;
}