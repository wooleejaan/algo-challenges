#include<bits/stdc++.h>
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
using namespace std; 
int n, m, a[15001], cnt;
int main(){
    fastio;
    cin >> n >> m;
    for(int i=0; i<n; i++) cin >> a[i];
    for(int i=0; i<n; i++){
        for(int j=i+1; j<n; j++){
            if(a[i] + a[j] == m) cnt++;
        }
    }
    cout << cnt << "\n";
    return 0;
}