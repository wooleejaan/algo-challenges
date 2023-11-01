#include <bits/stdc++.h>
using namespace std;
int n, ret=987654321, v[20][20], p[20][20], dy[4]={-1,1,0,0}, dx[4]={0,0,-1,1};
int setFlower(int y, int x){
    v[y][x]=1;
    int s = p[y][x];
    for(int i=0; i<4; i++){
        int ny=y+dy[i];
        int nx=x+dx[i];
        v[ny][nx]=1;
        s+=p[ny][nx];
    }
    return s;
}
bool check(int y, int x){
    if(v[y][x]) return 0;
    for(int i=0; i<4; i++){
        int ny=y+dy[i];
        int nx=x+dx[i];
        if(ny<0 || ny>=n || nx<0 || nx>=n || v[ny][nx]){
            return 0;
        }
    }
    return 1;
}
void eraseFlower(int y, int x){
    v[y][x]=0;
    for(int i=0; i<4; i++){
        int ny=y+dy[i];
        int nx=x+dx[i];
        v[ny][nx]=0;
    }
}
void flower(int cnt, int hap){
    if(cnt == 3){
        ret = min(ret, hap);
        return;
    }
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            if(check(i,j)){
                flower(cnt+1, hap + setFlower(i, j));
                eraseFlower(i, j);
            }
        }
    }
}
int main(){
    ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    cin >> n;
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            cin >> p[i][j];
        }
    }
    flower(0, 0);
    cout << ret;
    return 0;
}