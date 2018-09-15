#include<bits/stdc++.h>
using namespace  std;
#define mx 704
vector<int> adj[mx];
int low[mx],disco[mx],tme,vis[mx],root = 1;
vector< pair<int,int> > ans;
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
void bridge(int u, int par)
{
    vis[u] = 1;
    low[u] = disco[u] = ++tme;
    for(int i=0; i<adj[u].size(); i++){
        int v = adj[u][i];
        if(v==par) continue;
        if(vis[v]==0){
            bridge(v,u);
            low[u] = min(low[u], low[v]);
            if(disco[u]<low[v]){
                int a = u, b = v;
                if(a>b) swap(a,b);
                ans.push_back(make_pair(a,b));
            }
        }
        else{
            low[u] = min(low[u],disco[v]);
        }
    }
}
int main()
{
    int n,m,a,b,tc,cs=1;
    scanf("%d",&tc);
    while(tc--){
        clear();
        scanf("%d%d",&n,&m);
        for(int i=1; i<=m; i++){
            scanf("%d%d",&a, &b);
            adj[a].push_back(b);
            adj[b].push_back(a);
        }
        bridge(1,-1);
        printf("Caso #%d\n",cs++);
        sort(ans.begin(),ans.end());
        if(ans.size()==0) printf("Sin bloqueos\n");
        else{
        	cout<<ans.size()<<endl;
            for(int i=0; i<ans.size() ; i++){
                printf("%d %d\n",ans[i].first, ans[i].second);
            }
        }
    }
    return 0;
} 