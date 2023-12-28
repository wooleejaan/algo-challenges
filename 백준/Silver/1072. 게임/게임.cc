#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll a, b, mid, ret = -1;
int main(){
    cin >> a >> b;
    ll z = b * 100 / a;
    ll lo = 1, hi = 1e9;
    while(lo <= hi){
        mid = (lo + hi) / 2;
        if((b+mid)*100/(a+mid) > z){
            ret = mid;
            hi = mid - 1;
        } else lo = mid + 1;
    }
    cout << ret << "\n";
    return 0;
}