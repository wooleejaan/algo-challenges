#include<bits/stdc++.h>
using namespace std;

int n, m, j, lft, rgt, temp, ret;
int main(){
    ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    cin >> n >> m >> j; 
    lft = 1;
    for(int i=0; i<j; i++){
        rgt = lft + m - 1;
        cin >> temp; 
        if(temp >= lft && temp <= rgt) continue;
        else {
            if(temp < lft){ // left move 
                ret += (lft - temp);
                lft = temp;
            } else { // right move
                ret += (temp - rgt);
                lft += (temp - rgt);
            }
        }
    }
    cout << ret << "\n";
    return 0;
}