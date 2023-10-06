#include<bits/stdc++.h>
using namespace std;   
string s, temp; 
int main(){
    cin >> s; 
    temp = s; 
    reverse(temp.begin(), temp.end()); 
    if(temp == s) cout << 1 << "\n"; 
    else cout << 0 << "\n"; 
      
    return 0; 
}