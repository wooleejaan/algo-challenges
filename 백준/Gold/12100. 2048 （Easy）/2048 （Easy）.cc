#include<bits/stdc++.h>
using namespace std;
int ret, n;
struct Board {
    int a[24][24];
    void _rotate90(){
        int temp[24][24];
        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                temp[i][j] = a[n-j-1][i];
            }
        }
        memcpy(a, temp, sizeof(a));
    }
    void _move(){
        int temp[24][24];
        for(int i=0; i<n; i++){
            int c=-1, d=0;
            for(int j=0; j<n; j++){
                if(a[i][j] == 0) continue;
                if(d && a[i][j] == temp[i][c]) temp[i][c]*=2, d=0;
                else temp[i][++c] = a[i][j], d=1;
            }
            for(c++; c<n; c++) temp[i][c]=0;
        }
        memcpy(a, temp, sizeof(a));
    }
    void get_max(){
        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                ret = max(ret, a[i][j]);
            }
        }
    }
};
void go(Board c, int here){
    if(here == 5){
        c.get_max();
        return;
    }
    for(int i=0; i<4; i++){
        Board d = c;
        d._move();
        go(d, here + 1);
        c._rotate90();
    }
    return;
}
int main(){
    ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    cin >> n;
    Board c;
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            cin >> c.a[i][j];
        }
    }
    go(c, 0);
    cout << ret << "\n";
    return 0;
}