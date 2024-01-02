#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int t, n, m, temp;
int check(int temp, vector<int> &v){
    int l = 0, r = v.size() - 1;
    int mid;
    while(l <= r){
        mid = (l + r) / 2;
        if(v[mid] > temp) r = mid - 1;
        else if(v[mid] == temp) return 1;
        else l = mid + 1;
    }
    return 0;
}
int main(){
    scanf("%d", &t);
    while(t--){
        vector<int> v;
        scanf("%d", &n);
        for(int i=0; i<n; i++){
            scanf("%d", &temp), v.push_back(temp);
        }
        sort(v.begin(), v.end());
        scanf("%d", &m);
        for(int i=0; i<m; i++){
            scanf("%d", &temp), cout << check(temp, v) << "\n";
        }
    }
    return 0;
}