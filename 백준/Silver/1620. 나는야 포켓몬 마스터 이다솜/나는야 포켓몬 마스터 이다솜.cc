#include<bits/stdc++.h>
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
using namespace std; 
int n, m;
string s;
map<string, int> mp;
string a[100004];
int main(){
    fastio;
    cin >> n >> m;
    for(int i=0; i<n; i++){
        cin >> s;
        mp[s] = i + 1;
        a[i + 1] = s;
    }
    for(int i=0; i<m; i++){
        cin >> s;
        if(atoi(s.c_str()) == 0){
            cout << mp[s] << "\n";
        } else {
            cout << a[atoi(s.c_str())] << '\n';
        }
    }
    return 0;
}