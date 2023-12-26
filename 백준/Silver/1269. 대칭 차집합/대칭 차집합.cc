#include <bits/stdc++.h>
using namespace std;
int n, m, cnt, temp;
map<int, int> _map;
int main(){
    cin >> n >> m;
    for(int i=0; i<n; i++){
        cin >> temp; 
        _map[temp]++;
    }
    for(int i=0; i<m; i++){
        cin >> temp;
        _map[temp]++;
    }
    for(auto it : _map){
        if(it.second == 1) cnt++;
    }
    cout << cnt << "\n";
    return 0;
}