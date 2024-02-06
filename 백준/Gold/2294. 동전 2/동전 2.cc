#include <bits/stdc++.h>
using namespace std;
int n, k, a[10001], temp, INF = 987654321;
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> n >> k;
    fill(a, a + 10001, INF);
    a[0] = 0;
    for(int i=0; i<n; i++){
        cin >> temp;
        for(int j=temp; j<=k; j++){
            a[j] = min(a[j], a[j - temp] + 1);
        }
    }
    if(a[k] == INF) cout << -1 << "\n";
    else cout << a[k] << "\n";
    return 0;
}