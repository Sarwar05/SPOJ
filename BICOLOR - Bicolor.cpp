#include<bits/stdc++.h>
using namespace std;
#define mx 1030
vector<int> adj[mx];
int color[mx];
bool dfs(int u, int col)
{
    bool ret = true;
    color[u] = col;
    for(int i=0; i<adj[u].size(); i++){
        int v = adj[u][i];
        if(color[v]==-1){
            ret&=dfs(v, (col+1)%2);
        }
        else if(col==color[v]) return false;
    }
    return ret;
}
int main()
{
    int n,m,a,b;
    scanf("%d",&n);
    if(n==0) return 0;
    scanf("%d",&m);
    for(int i=1; i<=n; i++){
        adj[i].clear();
        color[i] = 0-1;
    }
    while(m--){
        scanf("%d%d",&a,&b);
        ++a, ++b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    if(!dfs(1,0)) printf("NOT ");
    printf("BICOLORABLE\n");
    main();
}
