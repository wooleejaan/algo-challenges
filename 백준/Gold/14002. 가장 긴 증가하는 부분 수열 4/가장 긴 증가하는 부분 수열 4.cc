#include <bits/stdc++.h>
using namespace std;
int n, a[1001], ret = 1, cnt[1001], idx;
int prev_list[1001];
void go(int idx){
    if(idx == -1) return;
    go(prev_list[idx]);
    printf("%d ", a[idx]);
    return;
}
int main(){
    scanf("%d", &n);
    for(int i=0; i<n; i++){
        scanf("%d", &a[i]);
    }
    fill(prev_list, prev_list + 1001, -1);
    fill(cnt, cnt + 1001, 1);
    for(int i=0; i<n; i++){
        for(int j=0; j<i; j++){
            if(a[j] < a[i] && cnt[i] < cnt[j] + 1){
                cnt[i] = cnt[j] + 1;
                prev_list[i] = j;
                if(ret < cnt[i]){
                    ret = cnt[i];
                    idx = i;
                }
            }
        }
    }
    printf("%d\n", ret);
    go(idx);
    return 0;
}