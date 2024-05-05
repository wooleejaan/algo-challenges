#include <bits/stdc++.h> 
using namespace std; 
#define ll long long 
int n, m, k, t1, t2, t3;
ll t4;
ll sum(vector<ll> &tree, int i){
    ll ans = 0;
    while(i > 0){
        ans += tree[i];
        i -= (i & -i);
    }
    return ans;
}
void update(vector<ll> &tree, int i, ll diff){
    while(i < tree.size()){
        tree[i] += diff;
        i += (i & -i);
    }
}
int main(){
    scanf("%d %d %d", &n, &m, &k);
    vector<ll> a(n+1);
    vector<ll> tree(n+1);
    for(int i=1; i<=n; i++){
        scanf("%lld", &a[i]);
        update(tree, i, a[i]);
    }
    m += k;
    while(m--){
        scanf("%d", &t1);
        if(t1 == 1){
            scanf("%d %lld", &t2, &t4);
            ll diff = t4 - a[t2];
            a[t2] = t4;
            update(tree, t2, diff);
        } else {
            int t2, t3;
            scanf("%d %d", &t2, &t3);
            printf("%lld\n", sum(tree, t3) - sum(tree, t2-1));
        }
    }
    return 0;
}