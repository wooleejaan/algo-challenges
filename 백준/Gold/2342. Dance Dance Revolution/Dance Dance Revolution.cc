#include <bits/stdc++.h>
#define MAX_N 100001
using namespace std;
int dp[5][5][MAX_N], n;
vector<int> v;
int check(int from, int to){
    // 처음 2
    if(from == 0) return 2;
    // 다시 누르면 1
    if(from == to) return 1;
    // 반대일 경우 4 
    if(abs(from - to) == 2) return 4;
    // 인접할 경우 
    return 3;
}
int solve(int l, int r, int target){
    if(target == n) return 0;
    if(dp[l][r][target] != -1) return dp[l][r][target];

    int left = solve(v[target], r, target + 1) + check(l, v[target]);
    int right = solve(l, v[target], target + 1) + check(r, v[target]);
    return dp[l][r][target] = min(left, right);
}
int main(){
    while(true){
        int num;
        cin >> num;
        if(num == 0){
            break;
        }
        v.push_back(num);
    }
    memset(dp, -1, sizeof(dp));
    n = v.size();
    cout << solve(0, 0, 0) << "\n";
    return 0;
}