#include <bits/stdc++.h>
using namespace std;
const int max_n = 40; 
int f[max_n] = {0, 5, 13}, m;
string s = "Messi Gimossi";
int main(){
    ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    cin >> m; m--;
    for(int i=3; i<=max_n; i++){
        f[i] = f[i-1] + f[i-2] + 1;
    }
    for(int i=max_n; i>=2; i--){
        if(m >= f[i]) m -= (f[i] + 1);
    }
    if(m == 5 || m == -1) cout << "Messi Messi Gimossi" << "\n";
    else cout << s[m] << "\n";
    return 0;
}