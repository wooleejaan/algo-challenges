#include <bits/stdc++.h>
using namespace std;
int dp[1000004], n;
const int INF = 987654321;
void go(int here){
    if(here == 0) return;
    printf("%d ", here);
    if(here % 3 == 0 && dp[here] == (dp[here / 3] + 1)) go(here / 3);
    else if(here % 2 == 0 && dp[here] == (dp[here / 2] + 1)) go(here / 2);
    else if((here - 1 >= 0) && (dp[here] == dp[here - 1] + 1)) go(here - 1);
    return;
}
int main(){
    scanf("%d", &n);
    fill(dp, dp + 1000004, INF);
    dp[1] = 0;
    for(int i=1; i<=n; i++){
        if(!(i%3)) dp[i] = min(dp[i/3]+1, dp[i]);
        if(!(i%2)) dp[i] = min(dp[i/2]+1, dp[i]);
        dp[i] = min(dp[i-1]+1, dp[i]);
    }
    printf("%d\n", dp[n]);
    go(n);
    return 0;
}