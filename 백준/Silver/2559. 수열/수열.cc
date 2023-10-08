#include<bits/stdc++.h>
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
using namespace std; 
int n, k, temp, psum[100001], ret = -10000004;
int main(){
    fastio;
    cin >> n >> k;
    for(int i=1; i<=n; i++){
        cin >> temp;
        psum[i] = psum[i - 1] + temp;
    }
    for(int i=k; i<=n; i++){
        ret = max(ret, psum[i] - psum[i - k]);
    }
    cout << ret << "\n";
    return 0;
}