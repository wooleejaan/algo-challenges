#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int n, m, c, a[24], dp[24][1 << 14][24];
int go(int here, int yamyam, int capacity){
    if(here == m) return 0;
    int &ret = dp[here][yamyam][capacity];
    if(ret) return ret;
    ret = max(ret, go(here + 1, yamyam, c));
    for(int i=0; i<n; i++){
        bool isbeforeYAM = (1 << i) & yamyam;
        bool isYAMCAN = (capacity - a[i]) >= 0;
        if(!isbeforeYAM && isYAMCAN){
            ret = max(ret, go(here, yamyam | (1 << i), capacity - a[i]) + 1);
        }
    }
    return ret;
}
int main(){
    ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
    cin >> n >> m >> c;
    for(int i=0; i<n; i++) cin >> a[i];
    cout << go(0, 0, c) << "\n";
    return 0;
}