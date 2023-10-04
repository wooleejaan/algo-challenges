#include <string>
#include <vector>
#include <algorithm>

#define MAX 105 
using namespace std;

int parent[MAX];
vector<pair<int, pair<int, int>>> edge;

int findParent(int a)
{
    if(a == parent[a]) return a;
    return parent[a] = findParent(parent[a]);
}

bool isSameParent(int a, int b)
{
    a = findParent(a);
    b = findParent(b);
    
    if(a == b) return true;
    return false;
}

void unionParent(int a, int b)
{
    a = findParent(a);
    b = findParent(b);
    parent[b] = a;
}

int solution(int n, vector<vector<int>> costs)
{
    int answer = 0;
    for(int i=0; i<n; i++) parent[i] = i; 
    for(int i=0; i<costs.size(); i++)
    {
        int node1 = costs[i][0];
        int node2 = costs[i][1];
        int cost = costs[i][2];
        
        edge.push_back(make_pair(cost, make_pair(node1, node2)));
    }
    
    sort(edge.begin(), edge.end());
    
    for(int i=0; i<edge.size(); i++)
    {
        int cost = edge[i].first;
        int node1 = edge[i].second.first;
        int node2 = edge[i].second.second;
        
        if(isSameParent(node1, node2) == false)
        {
            unionParent(node1, node2);
            answer = answer + cost;
        }
    }
    
    return answer;
}