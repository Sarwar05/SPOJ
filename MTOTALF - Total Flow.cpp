#include<bits/stdc++.h>
using namespace std;
#define mx 55
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
    ios_base::sync_with_stdio(0);
    map<char, int > id;
    int val=0;
    for(char i='a'; i<='z'; i++){
        id[i] = ++val;
    }
    for(char i='A'; i<='Z'; i++){
        id[i] = ++val;
    }
    int tc,n,a,b,c;
    char ch1,ch2;
    cin>>n;
    for(int i=0; i<mx; i++) adj[i].clear();
    memset(cap,0,sizeof cap);
    memset(passed, 0, sizeof passed);
    source = 27,sink = 52;
    for(int i=1; i<=n; i++){
        cin>>ch1>>ch2>>c;
        a = id[ch1];
        b = id[ch2];
        cap[a][b] += c;
        cap[b][a] += c;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    cout<<getMaxFlow()<<endl;;
    return 0;
}