#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define inf 1e18
#define vi vector<int>
/**
https://youtu.be/M6cm8UeeziI
https://cp-algorithms.com/graph/dinic.html
*/
/// 0 based
struct Edge
{
    int from;
    int to;
    ll cap;
    ll flow = 0;
    Edge(int _from, int _to, ll _cap)
    {
        from = _from;
        to = _to;
        cap = _cap;
    }
};
struct Dinic
{
    vector<Edge> edges;
    vector<vi> adj;
    int n, m=0;
    int source,sink;
    vi level, ptr;
    queue<int> q;
    Dinic(int _n, int _source, int _sink)
    {
        n = _n;
        source = _source;
        sink = _sink;
        adj.resize(n);
        level.resize(n);
        ptr.resize(n);
    }
    void addEdge(int from, int to, ll cap)
    {
        edges.push_back(Edge(from, to, cap));
        adj[from].push_back(m++);
        edges.push_back(Edge(to, from, 0));
        adj[to].push_back(m++);
    }
    bool bfs()
    {
        while(!q.empty()){
            int from = q.front();
            q.pop();
            for(int i=0; i<adj[from].size(); i++){
                int id = adj[from][i];
                int to = edges[id].to;
                if(edges[id].cap - edges[id].flow ==0)
                    continue;
                if(level[ to ] != -1) continue;
                level[to] = level[from] + 1;
                q.push(to);
            }
        }
        return level[sink] != -1;
    }
    ll dfs(int from, ll pushed)
    {
        if(pushed==0) return 0;
        if(from==sink) return pushed;
        for(int& cid = ptr[from]; cid<(int)adj[from].size(); cid++){
            int id = adj[from][cid];
            int to = edges[id].to;
            if(level[from]+1 != level[to] || edges[id].cap - edges[id].flow == 0)
                continue;
            ll tempFlow = dfs(to, min(pushed, edges[id].cap - edges[id].flow));
            if(tempFlow==0) continue;
            edges[id].flow +=tempFlow;
            edges[id^1].flow -=tempFlow;
            return tempFlow;
        }
        return 0;
    }
    ll getFlow()
    {
        ll maxFlow = 0;
        while(true){
            fill(level.begin(), level.end(), -1);
            level[source] = 0;
            while(!q.empty()) q.pop();
            q.push(source);
            if(bfs()==false) break;
            fill(ptr.begin(), ptr.end(), 0);
            while(ll pushed = dfs(source, inf))
                maxFlow+=pushed;
        }
        //cout<<maxFlow<<endl;
        return maxFlow;
    }
};
int main()
{
    int tc,n,m,a,b;
    scanf("%d",&tc);
    while(tc--){
        scanf("%d",&n);
        scanf("%d",&m);
        int sink = 2*n + 1;
        Dinic dinic(2*n + 5, 2, sink);
        for(int i=1; i<=n; i++){
            if(i==2)dinic.addEdge(i, n+i, 2);
            else dinic.addEdge(i, n+i, 1);
        }
        while(m--){
            scanf("%d%d",&a,&b);
            if(a>=1 && a<=n && b>=1 && b<=n){
                dinic.addEdge(a+n, b, 1);
                dinic.addEdge(b+n, a, 1);
            }
        }
        dinic.addEdge(n+1, sink, 1);
        dinic.addEdge(n+3, sink, 1);
        if(dinic.getFlow()>=2){
            printf("YES\n");
        }
        else{
            printf("NO\n");
        }
    }
    return 0;
}
