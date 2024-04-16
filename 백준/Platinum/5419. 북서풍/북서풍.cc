#include <bits/stdc++.h>
#define max_n 75004
typedef long long ll; 
using namespace std; 
int n, x, y, t;
vector<int> tree, _y;
vector<pair<int, int>> a; 

int sum (int idx){
    int ret = 0;
    while(idx > 0){
        ret += tree[idx];
        idx -= (idx & -idx);
    }
    return ret;
}
void update(int pos, int value){
    int idx = pos;
    while(idx <= n){
        tree[idx] += value; 
        idx += (idx & -idx);
    }
    return; 
}
int find_index(const vector<int> & _y, int value){
    int lo = 0, hi = _y.size() - 1;
    while(lo <= hi){
        int mid = (lo + hi) / 2;
        if(_y[mid] == value) return mid;
        if(_y[mid] < value) lo = mid + 1;
        else hi = mid - 1;
    }
}
int main(){
    ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    cin >> t;
    while(t--){
        cin >> n;
        a.clear(); _y.clear(); tree.clear(); tree.resize(n+1);
        for(int i=0; i<n; i++){
            cin >> x >> y;
            a.push_back({ x, y * -1 });
            _y.push_back(y * -1);
        }
        sort(a.begin(), a.end());
        sort(_y.begin(), _y.end());
        ll ret = 0;
        update(find_index(_y, a[0].second) + 1, 1);
        for(int i=1; i<n; i++){
            int idx = find_index(_y, a[i].second) + 1;
            ret += 1LL * sum(idx);
            update(idx, 1);
        }
        cout << ret << "\n";
    }
    return 0;
}