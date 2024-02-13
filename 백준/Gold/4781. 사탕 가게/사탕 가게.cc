#include <bits/stdc++.h>
using namespace std;
int cost, n, m1, m2, c;
int dp[100004];
int main(){
    while(1){
        scanf("%d %d.%d", &n, &m1, &m2);
        if(n == 0) break; 
        int cost = m1 * 100 + m2;
        memset(dp, 0, sizeof(dp));
        for(int i=0; i<n; i++){
            scanf("%d %d.%d", &c, &m1, &m2);
            int p = m1 * 100 + m2;
            for(int j=p; j<=cost; j++){
                dp[j] = max(dp[j], dp[j-p] + c);
            }
        }
        printf("%d\n", dp[cost]);
    }
    return 0;
}