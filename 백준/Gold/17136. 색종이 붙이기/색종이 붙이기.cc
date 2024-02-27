#include <bits/stdc++.h>
using namespace std; 
void f(){
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
}
const int INF = 987654321;
int a[104][104], ret = INF, n = 10;
map<int, int> mp;
bool check(int y, int x, int cnt){
    if(y + cnt > n || x + cnt > n) return false;
    for(int i=y; i<y+cnt; i++){
        for(int j=x; j<x+cnt; j++){
            if(a[i][j] == 0) return false;
        }
    }
    return true;
}
void draw(int y, int x, int cnt, int value){
    for(int i=y; i<y+cnt; i++){
        for(int j=x; j<x+cnt; j++){
            a[i][j]=value;
        }
    }
}
void dfs(int y, int x, int cnt){
    if(cnt >= ret) return;
    if(x == n){
        dfs(y + 1, 0, cnt);
        return;
    }
    if(y == n){
        ret = min(cnt, ret);
        return;
    }
    if(a[y][x] == 0){
        dfs(y, x + 1, cnt);
        return;
    }
    for(int _size = 5; _size >= 1; _size--){
        if(mp[_size] == 5) continue;
        if(check(y, x, _size)){
            mp[_size]++;
            draw(y, x, _size, 0);
            dfs(y, x + _size, cnt + 1);
            draw(y, x, _size, 1);
            mp[_size]--;
        }
    }
}
int main(){
    f();
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            cin >> a[i][j];
        }
    }
    dfs(0, 0, 0);
    cout << (ret == INF ? -1 : ret) << "\n";
    return 0;
}