#include<bits/stdc++.h>
using namespace std;
int n, m, a[10][10], ret = 987654321;
vector<pair<int, int>> v;
const int dy[] = {-1, 0, 1, 0};
const int dx[] = {0, 1, 0, -1};
bool isNotWall(int ny, int nx){
    if(a[ny][nx] == 0) return true;
    return false;
}
bool canGo(int ny, int nx){
    if(ny>=0 && ny<n && nx>=0 && nx<m && a[ny][nx] != 6){
        return true;
    }
    return false;
}
vector<pair<int, int>> extendCCTV(int here, int dir){
    vector<pair<int, int>> _change;
    int y = v[here].first;
    int x = v[here].second;
    if(a[y][x] == 1){
        while(true){
            int ny = y + dy[dir];
            int nx = x + dx[dir];
            if(canGo(ny, nx)){
                if(isNotWall(ny, nx)){
                    a[ny][nx] = 8;
                    _change.push_back({ny, nx});
                }
                y = ny;
                x = nx;
            }else break;
        }
    }else if(a[y][x] == 2){
        for(int i=0; i<=2; i+=2){
            int _y = y;
            int _x = x;
            while(true){
                int ny = _y + dy[(dir + i) % 4];
                int nx = _x + dx[(dir + i) % 4];
                if(canGo(ny, nx)){
                    if(isNotWall(ny, nx)){
                        a[ny][nx] = 8;
                        _change.push_back({ny, nx});
                    }
                    _y = ny;
                    _x = nx;
                }else break;
            }
        }
    }else if(a[y][x] == 3){
        for(int i=0; i<2; i++){
            int _y = y;
            int _x = x;
            while(true){
                int ny = _y + dy[(dir + i) % 4];
                int nx = _x + dx[(dir + i) % 4];
                if(canGo(ny, nx)){
                    if(isNotWall(ny, nx)){
                        a[ny][nx] = 8;
                        _change.push_back({ny, nx});
                    }
                    _y = ny;
                    _x = nx;
                }else break;
            }
        }
    }else if(a[y][x] == 4){
        for(int i=0; i<3; i++){
            int _y = y;
            int _x = x;
            while(true){
                int ny = _y + dy[(dir + i) % 4];
                int nx = _x + dx[(dir + i) % 4];
                if(canGo(ny, nx)){
                    if(isNotWall(ny, nx)){
                        a[ny][nx] = 8;
                        _change.push_back({ny, nx});
                    }
                    _y = ny;
                    _x = nx;
                }else break;
            }
        }
    }else if(a[y][x] == 5){
        for(int i=0; i<4; i++){
            int _y = y;
            int _x = x;
            while(true){
                int ny = _y + dy[(dir + i) % 4];
                int nx = _x + dx[(dir + i) % 4];
                if(canGo(ny, nx)){
                    if(isNotWall(ny, nx)){
                        a[ny][nx] = 8;
                        _change.push_back({ny, nx});
                    }
                    _y = ny;
                    _x = nx;
                }else break;
            }
        }
    }
    return _change;
}
void dfs(int here){
    if(here == v.size()){
        int cnt = 0;
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(a[i][j] == 0) cnt++;
            }
        }
        ret = min(cnt, ret);
        return;
    }
    for(int k=0; k<4; k++){
        vector<pair<int, int>> _change = extendCCTV(here, k);
        dfs(here + 1);
        for(auto b : _change) a[b.first][b.second] = 0;
    }
}
int main(){
    cin >> n >> m;
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            cin >> a[i][j];
            if(a[i][j] != 6 && a[i][j] != 0) v.push_back({i, j});
        }
    }
    dfs(0);
    cout << ret << "\n";
    return 0;
}