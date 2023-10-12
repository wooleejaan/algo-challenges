#include<bits/stdc++.h>
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
using namespace std;
const int max_len = 51;
int n, M, N, K, y, x, ret;
int a[max_len][max_len];
bool visited[max_len][max_len];
int dy[4] = {-1, 0, 1, 0};
int dx[4] = {0, 1, 0, -1};

void dfs(int Y, int X){
    visited[Y][X] = 1;
    for(int i=0; i<4; i++){
        int ny = Y + dy[i];
        int nx = X + dx[i];
        if(ny < 0 || ny >= N || nx < 0 || nx >= M) continue;
        if(a[ny][nx] == 1 && !visited[ny][nx]){
            dfs(ny, nx);
        }
    }
    return;
}
int main(){
    fastio;
    cin >> n;
    for(int i=0; i<n; i++){
        fill(&a[0][0], &a[0][0] + 51 * 51, 0);
        fill(&visited[0][0], &visited[0][0] + 51 * 51, 0);
        ret = 0;
        cin >> M >> N >> K;
        for(int j=0; j<K; j++){
            cin >> x >> y;
            a[y][x] = 1;
        }

        for(int i=0; i<N; i++){
            for(int j=0; j<M; j++){
                if(a[i][j] == 1 && !visited[i][j]){
                    ret++; 
                    dfs(i, j);
                }
            }
        }   
        cout << ret << "\n";
    }

    return 0;
}