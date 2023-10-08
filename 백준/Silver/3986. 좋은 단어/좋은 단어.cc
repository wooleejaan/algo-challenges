#include<bits/stdc++.h>
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
using namespace std; 
int n, ret;
string s;
char c;
int main(){
    fastio;
    cin >> n;
    for(int i=0; i<n; i++){
        cin >> s;
        stack<char> stk;
        for(char a : s){
            if(stk.size() && stk.top() == a) stk.pop();
            else stk.push(a);
        }
        if(stk.size() == 0) ret++;
    }
    cout << ret << "\n";
    return 0;
}