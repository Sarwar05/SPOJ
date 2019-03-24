#include<bits/stdc++.h>
using namespace std;
#define mx 10004
int dist[mx];
vector<int> adj[mx];
int node, cost;
void dfs(int u, int p, int d)
{
    if(d>cost){
        cost = d;
        node = u;
    }
    for(int i=0; i<adj[u].size(); i++){
        int v = adj[u][i];
        if(v==p) continue;
        dfs(v,u,d+1);
    }
}
int main()
{
    int n,a,b;
    scanf("%d", &n);
    for(int i=1; i<n; i++){
        scanf("%d%d", &a, &b);
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    cost = -1;
    dfs(1,-1,0);
    cost = -1;
    dfs(node, -1, 0);
    printf("%d\n", cost);
}
