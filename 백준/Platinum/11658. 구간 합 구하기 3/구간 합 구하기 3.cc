#include <bits/stdc++.h>
#define max_n 1025 
int n, m;
int a[max_n][max_n], bit[max_n][max_n];
void update(int y, int x, int value){
    while(y <= n){
        int j = x;
        while(j <= n){
            bit[y][j] += value;
            j += (j & -j);
        }
        y += (y & -y);
    }
    return;
}
int sum(int y, int x){
    int s = 0; 
    while(y > 0){
        int j = x; 
        while(j > 0){
            s += bit[y][j];
            j -= (j & -j);
        }
        y -= (y & -y);
    }
    return s;
}
int main(){
    scanf("%d%d", &n, &m);
    for(int i=1; i<=n; i++){
        for(int j=1; j<=n; j++){
            scanf("%d", &a[i][j]);
            update(i, j, a[i][j]);
        }
    }
    for(int i=0; i<m; i++){
        int type;
        scanf("%d", &type);
        if(type){
            int y1, x1, y2, x2;
            scanf("%d%d%d%d", &y1, &x1, &y2, &x2);
            printf("%d\n", sum(y2, x2) - sum(y1-1, x2) - sum(y2, x1-1) + sum(y1-1, x1-1));
        } else {
            int y, x, value; 
            scanf("%d%d%d", &y, &x, &value);
            update(y, x, value - a[y][x]), a[y][x] = value; 
        }
    }
    return 0;
}