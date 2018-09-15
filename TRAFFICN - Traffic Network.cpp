#include<bits/stdc++.h>
#define inf 1000000000
#define mx 10004
using namespace std;
vector<int> adj[mx], cost[mx], xtra[mx],xcost[mx];
int dist[mx][2];
struct node
{
    int u;
    int w;
    int x;
    node(int _u, int _w, int _x)
    {
        u = _u;
        w = _w;
        x = _x;
    }
    bool operator<(const node& ob)const
    {
        return w>ob.w;
    }
};
void dij(int s, int t)
{
    dist[s][0] = 0;
    queue<node>q;
    q.push(node(s,0,0));
    while(!q.empty()){
        node ob = q.front();
        q.pop();
        int u = ob.u;
        int w = ob.w;
        int x = ob.x;
        if(dist[u][x] < w) continue;
        for(int i=0; i<adj[u].size(); i++){
            int v = adj[u][i];
            int wt = cost[u][i];
            if(dist[v][x]>w+wt){
                dist[v][x] = w + wt;
                q.push(node(v, dist[v][x], x));
            }
        }
        if(x==1) continue;
        for(int i=0; i<xtra[u].size(); i++){
            int v = xtra[u][i];
            int wt = xcost[u][i];
            if(dist[v][x+1]>w+wt){
                dist[v][x+1] = w + wt;
                q.push(node(v, dist[v][x+1], x+1));
            }
        }
    }
}
int main()
{
    int tc,n,m,k,s,t,a,b,c;
    scanf("%d", &tc);
    while(tc--){
        scanf("%d%d%d%d%d", &n, &m, &k, &s, &t);
        for(int i=1; i<=n; i++){
            adj[i].clear();
            cost[i].clear();
            xtra[i].clear();
            xcost[i].clear();
            dist[i][0] = dist[i][1] = inf;
        }
        for(int i=1; i<=m; i++){
            scanf("%d%d%d",&a,&b, &c);
            adj[a].push_back(b);
            cost[a].push_back(c);
        }
        for(int i=1; i<=k; i++){
            scanf("%d%d%d",&a,&b, &c);
            xtra[a].push_back(b);
            xcost[a].push_back(c);
            xtra[b].push_back(a);
            xcost[b].push_back(c);
        }
        dij(s,t);
        int ans = min(dist[t][0], dist[t][1]);
        if(ans==inf) ans = -1;
        printf("%d\n", ans);
    }
    return 0;
}