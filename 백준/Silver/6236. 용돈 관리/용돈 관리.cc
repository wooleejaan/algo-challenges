#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n, m, a[100005], mx, ret, lo, hi;
bool check(int mid){
    int cnt = 1, temp = mid;
    for(int i=0; i<n; i++){
        if(mid - a[i] < 0){
            mid = temp;
            cnt++;
        }
        mid -= a[i];
    }
    return cnt <= m;
}
int main(){
    ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    cin >> n >> m;
    for(int i=0; i<n; i++){
        cin >> a[i];
        mx = max(a[i], mx);
    }
    lo = mx, hi = 1000000004;
    while(lo <= hi){
        int mid = (lo + hi) / 2;
        if(check(mid)){
            hi = mid - 1;
            ret = mid;
        } else lo = mid + 1;
    }
    cout << ret << "\n";
    return 0;
}