#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int n, m, x, y, visited[100001], v[100001], flag;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  cin >> n >> m;
  for (int i = 0; i < m; i++) {
    cin >> x >> y;
    v[x]++;
    v[y]--;
  }
  for (int i = 1; i <= n; i++) {
    v[i] += i;
    visited[v[i]]++;
  }
  for (int i = 1; i <= n; i++) {
    if (visited[i] >= 2) flag = 1;
  }
  if (flag)
    cout << -1 << "\n";
  else {
    for (int i = 1; i <= n; i++) cout << v[i] << " ";
  }
  return 0;
}