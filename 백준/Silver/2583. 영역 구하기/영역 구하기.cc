#include<bits/stdc++.h>
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
using namespace std;
const int maxl = 104;
int m,n,k, a[maxl][maxl], visited[maxl][maxl], y, x, yy, xx;
vector<int> v;
int dy[4] = {-1, 0, 1, 0}, dx[4] = {0, 1, 0, -1};
int dfs(int y, int x){
    visited[y][x] = 1;
    int ret = 1;
    for(int i=0; i<4; i++){
        int ny = y + dy[i];
        int nx = x + dx[i];

        if(ny < 0 || ny >= m || nx < 0 || nx >= n || a[ny][nx] == 1) continue;
        if(a[ny][nx] == 0 && !visited[ny][nx]){
            ret += dfs(ny, nx);
        }

    }
    return ret;
}
int main(){
    fastio;
    cin >> m >> n >> k;
    for(int i=0; i<k; i++){
        cin >> x >> y >> xx >> yy;
        for(int j=y; j<yy; j++){
            for(int z=x; z<xx; z++){
                a[j][z] = 1;
            }
        }
    }

    for(int i=0; i<m; i++){
        for(int j=0; j<n; j++){
            if(a[i][j] != 1 && visited[i][j] == 0){
                int cnt = dfs(i, j);
                v.push_back(cnt);
            }
        }
    }
    cout << v.size() << "\n";
    sort(v.begin(), v.end());
    for(auto i : v){
        cout << i << " ";
    }

    return 0;
}