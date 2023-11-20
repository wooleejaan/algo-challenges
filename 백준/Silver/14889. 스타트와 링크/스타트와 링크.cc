#include <bits/stdc++.h>
using namespace std;
const int INF = 987654321;
int s[24][24], ret = INF, n;
int go(vector<int> &a, vector<int> &b){
    pair<int, int> ret2;
    for(int i=0; i<n/2; i++){
        for(int j=0; j<n/2; j++){
            if(i == j) continue;
            ret2.first += s[a[i]][a[j]];
            ret2.second += s[b[i]][b[j]];
        }
    }
    return abs(ret2.first - ret2.second);
}
int main(){
    cin >> n; 
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            cin >> s[i][j];
        }
    }
    for(int i=0; i<(1<<n); i++){
        if(__builtin_popcount(i) != n/2) continue;
        vector<int> start, link;
        for(int j=0; j<n; j++){
            if(i & (1<<j)) start.push_back(j);
            else link.push_back(j);
        }
        ret = min(ret, go(start, link));
    }
    cout << ret << "\n";
    return 0;
}