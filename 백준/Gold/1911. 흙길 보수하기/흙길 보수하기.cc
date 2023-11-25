#include<bits/stdc++.h>
using namespace std;
int n, m, idx, ret, b;
int main(){
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    cin >> n >> m;
    vector<pair<int, int>> a(n);
    for(int i=0; i<n; i++) cin >> a[i].first >> a[i].second;
    sort(a.begin(), a.end());
    for(int i=0; i<n; i++){
        if(a[i].second <= idx) continue;
        if(idx < a[i].first){
            int length = a[i].second - a[i].first;
            b = length / m + (length % m ? 1 : 0);
            idx = a[i].first + b * m;
        } else {
            int length = a[i].second - idx;
            b = length / m + (length % m ? 1 : 0);
            idx = idx + b * m;
        }
        ret += b;
    }
    cout << ret << "\n";
    return 0;
}