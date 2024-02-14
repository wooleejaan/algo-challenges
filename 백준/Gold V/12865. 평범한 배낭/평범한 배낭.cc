#include <bits/stdc++.h>
using namespace std;
int dp[100001];
int n, k, w, v;
int main(){
    scanf("%d %d", &n, &k);
    while(n--){
        scanf("%d %d", &w, &v);
        for(int i=k; i>=w; i--){
            dp[i] = max(dp[i], dp[i - w] + v);
        }
    }
    printf("%d\n", dp[k]);
    return 0;
}