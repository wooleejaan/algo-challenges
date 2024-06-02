#include <bits/stdc++.h>
using namespace std; 
int T, dist[2004], n, m, t, s, g, h, a, b, d;
const int INF = 987654322;
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> T;
    while(T--){
        vector<pair<int, int>> adj[2004];
        cin >> n >> m >> t >> s >> g >> h;
        for(int i=0; i<m; i++){
            cin >> a >> b >> d;
            d *= 2;
            if(a == g && b == h){
                d--;
            } else if(a == h && b == g){
                d--;
            }
            adj[a].push_back(make_pair(d, b));
            adj[b].push_back(make_pair(d, a));
        }
        int candi[t+1];
        for(int i=0; i<t; i++){
            cin >> candi[i];
        }
        sort(candi, candi + t);
        fill(dist, dist + 2004, INF);
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        pq.push(make_pair(0, s));
        dist[s] = 0;
        while(pq.size()){
            int here = pq.top().second;
            int here_dist = pq.top().first;
            pq.pop();
            if(dist[here] != here_dist) continue;
            for(pair<int, int> there : adj[here]){
                int _dist = there.first;
                int _there = there.second;
                if(dist[_there] > dist[here] + _dist){
                    dist[_there] = dist[here] + _dist;
                    pq.push(make_pair(dist[_there], _there));
                }
            }
        }
        for(int i=0; i<t; i++){
            if(dist[candi[i]] % 2 == 1) cout << candi[i] << "\n";
        }
    }
    return 0;
}