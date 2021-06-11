#include<bits/stdc++.h>
using namespace std;
#define MAX(a,b) ((a>b)?a:b)
#define MIN(a,b) ((a<b)?a:b)
typedef long long ll;
int max_depth = 0;
int depth[2001];
bool visited[2005];
vector<int> Adj[10000];
void dfs(int node, int d)
{
    if(visited[node])
    {
        return;
    }
    visited[node] = true;
    depth[node] = d+1;
    max_depth = MAX(max_depth, depth[node]);
    for(auto i:Adj[node])
    {
        dfs(i, depth[node]);
    }
}
int main()
{
    for(int i = 0; i<2005;i++)visited[i] = false;
    int n,x;
    cin>>n;
    for(int i = 0;i<n;i++)
    {
        cin>>x;
        if(x<0)
        {
            Adj[0].push_back(i+1);
        }
        else
        {
            Adj[x].push_back(i+1);
        }
    }
    for(auto i:Adj[0])
    {
        depth[i] = 0;
    }
    for(int i = 0; i<=n;i++)
        for(auto j:Adj[i])
        {
            dfs(j,depth[j]);
        }
    cout<<(max_depth);
    return 0;
}