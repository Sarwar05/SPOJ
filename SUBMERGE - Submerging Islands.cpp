#include<bits/stdc++.h>
using namespace  std;
#define mx 10004
vector<int> adj[mx];
int low[mx],disco[mx],tme,vis[mx],root = 1;
set<int> ans;
void clear()
{
    ans.clear();
    tme = 0;
    for(int i=1; i<mx; i++){
        adj[i].clear();
        vis[i] = 0;
        low[i] = disco[i] = 0;
    }
}
void dfs(int u, int par)
{
    vis[u]=1;
    low[u] = disco[u] = ++tme;
    int child = 0;
    for(int i=0; i<adj[u].size(); i++){
        int v = adj[u][i];
        if(v==par) continue;
        if(vis[v]==0){
            dfs(v,u);
            low[u] = min(low[u], low[v] );
            if(disco[u]<=low[v] && u!=root) ans.insert(u);
            child++;
        }
        else{
            low[u] = min(low[u], disco[v]);
        }
    }
    if(child>1 && u == root) ans.insert(u);
}
int main()
{
    int n,m,a,b;
    while(scanf("%d%d",&n,&m)){
        if(n==0 && m==0) return 0;
        else clear();
        for(int i=1; i<=m; i++){
            scanf("%d%d",&a, &b);
            adj[a].push_back(b);
            adj[b].push_back(a);
        }
        dfs(1,-1);
        printf("%d\n",ans.size());
    }
    return 0;
}