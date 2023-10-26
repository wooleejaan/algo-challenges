#include <bits/stdc++.h>
using namespace std;
int visited[54][54], a[54][54], n, l, r, sum, cnt; 
const int dy[]={-1,0,1,0};
const int dx[] ={0,1,0,-1}; 
vector<pair<int,int>>v;
void dfs(int y,int x,vector<pair<int,int>> &v){ 
    for(int i=0; i<4; i++){
        int ny = y+dy[i];
        int nx = x+dx[i];
        if(nx<0 || nx>=n || ny<0 || ny>=n || visited[ny][nx])continue;
				// 결국 뻗어나가는 조건이 r보다 작고, l보다 크다는 지문으로 등장한 것 뿐이다. 
        if(abs(a[ny][nx]- a[y][x]) >= l && abs(a[ny][nx] - a[y][x]) <= r){
            visited[ny][nx] =1;
            v.push_back({ny,nx});
            sum += a[ny][nx];
            dfs(ny,nx,v);
        }
    }
}

int main(){ 
    cin>>n>>l>>r;
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            cin>>a[i][j];
        }
    }
		// 계속해서 인구이동이 있는한 반복해야 하니까 무한루프가 필요하다. while(true){}
    while(true){ // 계속 특정 map에 대해 반복해야 하므로 
        bool flag =0;
        fill(&visited[0][0], &visited[0][0] + 54 * 54, 0);
        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                if(!visited[i][j]){
                    v.clear(); // vector 초기화. 
                    visited[i][j] = 1;
                    v.push_back({i,j});
                    sum = a[i][j]; // 일단 각 정점의 값을 더해주는 게 중요하다. 
                    dfs(i,j,v);
                    if(v.size() == 1) continue;  
                    for(pair<int,int> b : v){ // vector에 연결된 노드들이 담긴다. 
                        a[b.first][b.second] = sum / v.size();
                        flag = 1; // 인구 이동 발생했다.
                    }
                } 
            }
        }
				// flag가 1이 아니라는 건, 인구 이동이 발생하지 않았다는 의미. 
        if(!flag) break;  
        cnt++;
    } 
    cout<< cnt << "\n";
    return 0;
}