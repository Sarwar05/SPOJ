#include<bits/stdc++.h>
using namespace std;
#define mx 202
int cap[mx][mx],passed[mx][mx];
vector<int> adj[mx];
int par[mx];
int source,sink;
bool bfs()
{
    memset(par,-1,sizeof par);
    par[source] = -5;
    queue<int> q;
    q.push(source);
    while(!q.empty()){
        int u = q.front();
        q.pop();
        for(int i=0; i<adj[u].size(); i++){
            int v = adj[u][i];
            if(par[v]==-1 && cap[u][v]-passed[u][v] > 0){
                par[v] = u;
                if(v==sink) return true;
                q.push(v);
            }
        }
    }
    return false;
}
int getMaxFlow()
{
    int maxflow = 0,flow;
    while(bfs()){
        int now = sink;
        flow = 1000000;
        while(now!=source){
            int prev = par[now];
            flow = min(flow,cap[prev][now] - passed[prev][now]);
            now = prev;
        }
        maxflow+=flow;
        now = sink;
        while(now!=source){
            int prev = par[now];
            passed[prev][now]+=flow;
            passed[now][prev]-=flow;
            now = prev;
        }
    }
    return maxflow;
}
int main()
{
    int tc,n,a,b;
    scanf("%d",&tc);
    while(tc--){
        scanf("%d",&n);
        for(int i=0; i<mx; i++) adj[i].clear();
        memset(cap,0,sizeof cap);
        memset(passed, 0, sizeof passed);
        source = 1,sink = n;
        for(int i=1; i<n; i++){
            scanf("%d",&a);
            while(a--){
                scanf("%d",&b);
                cap[i][b] = ( (i!=1 && b!=n) ? 10000000 :1 );
 
                adj[i].push_back(b);
                adj[b].push_back(i);
            }
        }
        printf("%d\n",getMaxFlow());
    }
    return 0;
}