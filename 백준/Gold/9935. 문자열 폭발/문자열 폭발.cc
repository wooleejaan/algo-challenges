#include <bits/stdc++.h>
using namespace std;
string S, T, ret;
stack<char> stk;
int main(){
    cin >> S >> T;
    for(char a : S){
        stk.push(a);
        if(stk.size() >= T.size() && stk.top() == T[T.size() - 1]){
            string ss = "";
            for(char i : T){
                ss += stk.top(); stk.pop();
            }
            reverse(ss.begin(), ss.end());
            if(T != ss){
                for(char i : ss){
                    stk.push(i);
                }
            }
        }
    }
    if(stk.size() == 0){
        cout << "FRULA\n";
    } else {
        while(stk.size()){
            ret += stk.top(); stk.pop();
        } 
        reverse(ret.begin(), ret.end());
        cout << ret << "\n";
    }
    return 0;
}