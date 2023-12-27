#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n, atk, t, a, h, H, mx, damage;
int main(){
    ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    cin >> n >> atk;
    for(int i=0; i<n; i++){
        cin >> t >> a >> h;
        if(t == 1){
            damage = a * (ceil((double)h/atk)-1);
            if(H < damage){
                mx += damage - H;
                H = 0;
            } else H -= damage;
        } else {
            atk += a;
            H = min(H+h, mx);
        }
    }
    cout << mx + 1 << "\n";
    return 0;
}