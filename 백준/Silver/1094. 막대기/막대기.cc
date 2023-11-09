#include <bits/stdc++.h>
using namespace std;
int n, ret = 1;
int main(){
    cin >> n;
    while(n != 1){
        if(n & 1) ret++;
        n /= 2;
    }
    cout << ret << "\n";
    return 0;
}