#include<bits/stdc++.h>
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
typedef long long ll;
using namespace std; 
int t, n;
string a, b;
int main(){
    fastio;
    cin >> t;
    while(t--){
        map<string, int> _map;
        cin >> n;
        for(int i=0; i<n; i++){
            cin >> a >> b;
            _map[b]++;
        }
        ll ret = 1;
        for(auto c : _map){
            ret *= ((ll)c.second + 1);
        }
        ret--;
        cout << ret << "\n";
    }
    return 0;
}