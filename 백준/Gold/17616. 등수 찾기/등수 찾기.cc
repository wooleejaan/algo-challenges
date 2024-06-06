#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int n, m, x, a, b, visited[100005];
vector<int> h[100005], l[100005];
int bfs(int here, vector<int> adj[]) {
  queue<int> q;
  visited[here] = 1;
  q.push(here);
  int ret = 0;
  while (q.size()) {
    int _here = q.front();
    q.pop();
    for (int there : adj[_here]) {
      if (visited[there]) continue;
      visited[there] = 1;
      q.push(there);
      ret++;
    }
  }
  return ret;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  cin >> n >> m >> x;
  for (int i = 0; i < m; i++) {
    cin >> a >> b;
    h[a].push_back(b);
    l[b].push_back(a);
  }
  int ans1 = bfs(x, l);
  fill(visited, visited + 100005, 0);
  int ans2 = bfs(x, h);
  cout << ans1 + 1 << " " << n - ans2 << "\n";
  return 0;
}