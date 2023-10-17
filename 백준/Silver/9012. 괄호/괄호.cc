#include<bits/stdc++.h>
using namespace std;
int n;
string s;
bool check(string s){
    stack<char> stk;
    for(char c : s){
        if(c == '(') stk.push(c);
        else {
            if(!stk.empty()) stk.pop();
            else return false;
        }
    }
    return stk.empty();
}
int main(){
    ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    cin >> n;
    for(int i=0; i<n; i++){
        cin >> s;
        if(check(s)) cout << "YES\n";
        else cout << "NO\n";
    }
    return 0;
}