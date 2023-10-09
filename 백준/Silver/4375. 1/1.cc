#include<bits/stdc++.h>
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
using namespace std; 
int n;
int main(){
    fastio;
    while(scanf("%d", &n) != EOF){
        int cnt = 1, ret = 1;
        while(true){
            if(cnt % n == 0){
                printf("%d\n", ret);
                break;
            } else {
                cnt = (cnt * 10) + 1;
                cnt %= n;
                ret++;
            }
        }
    }
    return 0;
}