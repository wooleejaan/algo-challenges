#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int n, k;
ll ret;
int main(){
    ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    cin >> n >> k;
    vector<pair<int, int>> v(n);
    vector<int> vv(k);
    for(int i=0; i<n; i++){
        cin >> v[i].first >> v[i].second;
    }
    for(int i=0; i<k; i++) cin >> vv[i];
    sort(v.begin(), v.end());
    sort(vv.begin(), vv.end());
    priority_queue<int> pq;
    int j=0; 
    for(int i=0; i<k; i++){
        while(j<n && v[j].first <= vv[i]) pq.push(v[j++].second);
        if(pq.size()){
            ret += pq.top();
            pq.pop();
        }
    }
    cout << ret << "\n";
    return 0;
}