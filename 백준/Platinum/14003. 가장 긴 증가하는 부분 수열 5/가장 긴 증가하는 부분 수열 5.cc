#include <bits/stdc++.h>
using namespace std;
int n, lis[1000004], len, num;
pair<int, int> ans[1000004];
stack<int> stk;
const int INF = 1e9 + 4;
int main(){
    fill(lis, lis + 1000004, INF);
    scanf("%d", &n);
    for(int i=0; i<n; i++){
        scanf("%d", &num);
        auto lowerPos = lower_bound(lis, lis + len, num);
        int _pos = (int)(lower_bound(lis, lis + len, num) - lis);
        if(*lowerPos == INF) len++;
        *lowerPos = num;
        ans[i].first = _pos;
        ans[i].second = num;
    }
    printf("%d\n", len);
    for(int i=n-1; i>=0; i--){
        if(ans[i].first == len - 1){
            stk.push(ans[i].second);
            len--;
        }
    }
    while(stk.size()){
        printf("%d\n", stk.top());
        stk.pop();
    }
    return 0;
}