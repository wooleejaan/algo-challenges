#include<bits/stdc++.h>
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
using namespace std;
int a[101][101], visited[101][101], n, ret = 1;
int dy[4] = {-1, 0, 1, 0}, dx[4] = {0, 1, 0, -1};
void dfs(int y, int x, int d){
    visited[y][x] = 1;
    for(int i=0; i<4; i++){
        int ny = y + dy[i];
        int nx = x + dx[i];
        if(ny < 0 || nx < 0 || ny >= n || nx >= n) continue;
        if(!visited[ny][nx] && a[ny][nx] > d) dfs(ny, nx, d);
    }
    return;
}
int main(){
    fastio;
    cin >> n;
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            cin >> a[i][j];
        }
    }
    for(int d=1; d<101; d++){
        fill(&visited[0][0], &visited[0][0] + 101 * 101, 0);
        int cnt = 0;
        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                if(a[i][j] > d && !visited[i][j]){
                    dfs(i, j, d);
                    cnt++;
                }
            }
        }
        ret = max(ret, cnt);
    }
    cout << ret << "\n";
    return 0;
}