#include<bits/stdc++.h>
using namespace std;
#define mx 1003
vector<int> adj[mx];
int vis[mx], arr[mx];
vector<int> ind, val;
void dfs(int s)
{
    ind.push_back(s);
    val.push_back(arr[s]);
    vis[s] = 1;
    for(int i=0; i<(int)adj[s].size(); i++){
        int v = adj[s][i];
        if(vis[v]==0){
            dfs(v);
        }
    }
}
int main()
{
    int tc,n,m,a,b;
    scanf("%d", &tc);
    while(tc--){
        scanf("%d%d", &n, &m);
        for(int i=1; i<=n; i++){
            scanf("%d", &arr[i]);
            vis[i] = -1;
            adj[i].clear();
        }
        for(int i=1; i<=m; i++){
            scanf("%d%d", &a, &b);
            adj[a].push_back(b);
            adj[b].push_back(a);
            vis[a] = vis[b] = 0;
        }
        for(int i=1; i<=n; i++){
            if(vis[i]==0){
                ind.clear();
                val.clear();
                dfs(i);
                sort(ind.begin(), ind.end());
                sort(val.begin(), val.end());
                int sz = ind.size();
                for(int j=0; j<sz; j++){
                    arr[ ind[j] ] = val[j];
                }
            }
        }
        printf("%d", arr[1]);
        for(int i=2; i<=n; i++){
            printf(" %d", arr[i]);
        }
        printf("\n");
    }
}