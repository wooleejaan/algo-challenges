#include<bits/stdc++.h>
using namespace std;
int n;
int main(){
    cin >> n;
    vector<pair<int, int>> a(n);
    for(int i=0; i<n; i++) cin >> a[i].first >> a[i].second;
    sort(a.begin(), a.end());
    int realTime = a[0].first + a[0].second;
    for(int i=1; i<a.size(); i++){
        realTime = max(realTime, a[i].first);
        realTime += a[i].second;
    }
    cout << realTime << "\n";
    return 0;
}