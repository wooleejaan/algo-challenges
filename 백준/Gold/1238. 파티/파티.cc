#include <bits/stdc++.h> 
using namespace std; 
int N, M, X, u, v, w, ret;
vector<pair<int, int>> adj[1001], adj2[1001];
int dist[1001], dist2[1001];
bool visited[1001];
const int INF = 987654321;
priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
void dijkstra(int *dist, vector<pair<int, int>> *adj){
    pq.push(make_pair(0, X));
    dist[X] = 0;
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
}
int main(){
    scanf("%d %d %d", &N, &M, &X);
    fill(dist, dist + 1001, INF);
    fill(dist2, dist2 + 1001, INF);
    for(int i=0; i<M; i++){
        scanf("%d %d %d", &u, &v, &w);
        adj[u].push_back(make_pair(w, v));
        adj2[v].push_back(make_pair(w, u));
    }
    dijkstra(dist, adj);
    dijkstra(dist2, adj2);
    for(int i=1; i<=N; i++){
        if(i == X) continue;
        ret = max(ret, dist[i] + dist2[i]);
    }
    printf("%d\n", ret);
    return 0;
}