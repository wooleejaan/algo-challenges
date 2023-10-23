#include<bits/stdc++.h>
using namespace std;
int n, a[1000004], ret[1000004];
stack<int> stk;
int main(){
    ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    cin >> n;
    memset(ret, -1, sizeof(ret));
    for(int i=0; i<n; i++){
        cin >> a[i];
        while(stk.size() && a[stk.top()] < a[i]){
            ret[stk.top()] = a[i];
            stk.pop();
        }
        stk.push(i);
    }
    for(int i=0; i<n; i++) cout << ret[i] << " ";
    return 0;
}