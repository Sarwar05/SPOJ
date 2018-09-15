#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=5005;
const int M=30005*2;
const ll INF=100000000000LL;
int u[M],v[M],first[N],Next[M],e;
ll cap[M] = {0},flow[M];
int q[N],dist[N],work[N],source,sink;
int dirx[]={0,1,0,-1};
int diry[]={1,0,-1,0};
void init()
{
    memset(first,-1,sizeof(first));
    e=0;
}
void insert(int f,int t,ll val)
{
    u[e]=f; v[e]=t; cap[e]=max(cap[e],val); flow[e]=0;
    Next[e]=first[u[e]]; first[u[e]]=e++;
    u[e]=t; v[e]=f; cap[e]=max(cap[e],val); flow[e]=0;
    Next[e]=first[u[e]]; first[u[e]]=e++;
}
bool bfs()
{
    memset(dist,-1,sizeof(dist));
    dist[source]=0;
    int l=0,r=0;
    q[r++]=source;
    while(l<r){
        int x=q[l++];
        for(int i=first[x];i+1;i=Next[i]){
            if(flow[i]<cap[i]&&dist[v[i]]==-1){
                dist[v[i]]=dist[x]+1;
                q[r++]=v[i];
            }
        }
    }
    return dist[sink]!=-1;
}
int dfs(int x,ll val)
{
    if(x==sink) return val;
    for(int &i=work[x];i+1;i=Next[i]){
        int y=v[i]; ll tmp;
        if(flow[i]<cap[i]&&dist[y]==dist[x]+1&&(tmp=dfs(y,min(val,cap[i]-flow[i])))>0){
            flow[i]+=tmp;
            flow[i^1]-=tmp;
            return tmp;
        }
    }
    return 0;
}
ll dinic()
{
    ll ans=0;
    while(bfs()){
        for(int i=0;i<N;i++) work[i]=first[i];
        while(1){
            ll tmp=dfs(source,INF);
            if(tmp==0) break;
            ans+=tmp;
        }
    }
    return ans;
}
int main()
{
    int n,m,a,b,c;
    scanf("%d%d",&n,&m);
    init();
    source = 1, sink = n;
    while(m--){
        scanf("%d%d%d",&a,&b,&c);
        if(a!=b){
            insert(a,b,c);
        }
    }
    printf("%lld\n",dinic());
    return 0;
}