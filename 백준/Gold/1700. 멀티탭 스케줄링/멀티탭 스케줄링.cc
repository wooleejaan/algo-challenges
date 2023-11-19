#include <bits/stdc++.h>
using namespace std;
int k, n, a[104], visited[104], cnt;
const int INF = 987654321;
vector<int> v;
int main(){
    ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    cin >> k >> n;
    for(int i=0; i<n; i++) cin >> a[i];
    for(int i=0; i<n; i++){
        if(!visited[a[i]]){
            if(v.size() == k){
                int last_idx = 0, pos;
                for(int _a : v){
                    int here_pick = INF;
                    for(int j=i+1; j<n; j++){
                        if(_a == a[j]){
                            here_pick = j; break;
                        }
                    }
                    if(last_idx < here_pick){
                        last_idx = here_pick;
                        pos = _a;
                    }
                }
                visited[pos] = 0;
                cnt++;
                v.erase(find(v.begin(), v.end(), pos));
            }
            v.push_back(a[i]); visited[a[i]]=1;
        }
    }
    cout << cnt << "\n";
    return 0;
}