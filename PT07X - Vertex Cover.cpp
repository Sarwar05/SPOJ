#include<bits/stdc++.h>
using namespace std;
#define mx 100005
int dp[mx][2];
int vis[mx];
vector<int> adj[mx];
int fun(int u, int par, int cnt)
{
    vis[u] = 1;
    if(adj[u].size()==0) return 0;
    if(dp[u][cnt]!=-1) return dp[u][cnt];
    int ret=0;
    for(int i=0; i<adj[u].size(); i++){
        int v = adj[u][i];
        if(v==par) continue;
        if(cnt==0){
            ret+=fun(v,u,1);
        }
        else{
            ret+=min(fun(v,u,1), fun(v,u,0));
        }
    }
    return dp[u][cnt] = ret+cnt;
}
int main()
{
    int n,a,b;
    scanf("%d",&n);
    for(int i=1; i<n; i++){
        scanf("%d%d",&a,&b);
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    memset(vis,0,sizeof vis);
    memset(dp,-1,sizeof dp);
    int ans = 0;
    for(int i=1; i<=n; i++){
        if(vis[i]==0){
            ans+=min(fun(i,-1,0),fun(i,-1,1));
        }
    }
    printf("%d\n",ans);
    return 0;
}