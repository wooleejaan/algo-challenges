#include <bits/stdc++.h>
using namespace std; 
int t, n, m, tree[200004], temp;
map<int, int> mp;
void update(int idx, int value){
    while(idx <= 200004){
        tree[idx] += value; 
        idx += (idx & -idx);
    }
}
int sum(int idx){
    int ret = 0;
    while(idx > 0){
        ret += tree[idx];
        idx -= (idx & -idx);
    }
    return ret; 
}
int main(){
    ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    cin >> t;
    while(t--){
        cin >> n >> m;
        memset(tree, 0, sizeof(tree));
        mp.clear();
        int update_idx = 100001;
        for(int i=1; i<=n; i++){
            update(i+update_idx, 1);
            mp[i] = i+update_idx;
        }
        for(int i=0; i<m; i++){
            cin >> temp;
            int idx = mp[temp];
            cout << sum(idx) - 1 << " ";
            update(idx, -1);
            update(--update_idx, 1);
            mp[temp] = update_idx;
        }
        cout << "\n";
    }
    return 0;
}