#include <bits/stdc++.h>
using namespace std; 
int n, k, id, cost_time, _time, idx;
long long ret; 
struct Cacher {
    int id, maxTime, cacher_id;
};
struct comp {
    bool operator()(Cacher &a, Cacher &b){
        if(a.maxTime == b.maxTime){
            return a.cacher_id > b.cacher_id;
        }
        return a.maxTime > b.maxTime;
    }
};
bool cmp2(const Cacher &a, const Cacher &b){
    if(a.maxTime == b.maxTime){
        return a.cacher_id > b.cacher_id;
    }
    return a.maxTime < b.maxTime;
}
priority_queue<Cacher, vector<Cacher>, comp> pq;
vector<Cacher> v;
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> n >> k;
    for(int i=0; i<n; i++){
        cin >> id >> cost_time;
        if(i < k){
            pq.push({ id, cost_time, i+1 });
            continue;
        }
        pq.push({ id, cost_time + pq.top().maxTime, pq.top().cacher_id });
        v.push_back(pq.top());
        pq.pop();
    }
    while(pq.size()){
        v.push_back(pq.top());
        pq.pop();
    }
    sort(v.begin(), v.end(), cmp2);
    for(int i=0; i<v.size(); i++){
        ret += 1LL * (i + 1) * v[i].id;
    }
    cout << ret << "\n";
    return 0;
}