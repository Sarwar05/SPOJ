#include<bits/stdc++.h>
using namespace std;
#define mx 10004
#define lg 15
int lev[mx],cost[mx],par[mx];
int table[mx][lg];
vector<int> adj[mx],wt[mx];
void dfs(int p,int s, int l, int w)
{
    lev[s] = l;
    par[s] = p;
    cost[s] = w;
    for(int i=0; i<(int)adj[s].size(); i++){
        int v = adj[s][i];
        if(v==p) continue;
        dfs(s,v,l+1,w+wt[s][i]);
    }
}
void getTable(int n)
{
    dfs(-1,1,0,0);
    memset(table, -1, sizeof table);
    for(int i=1; i<=n; i++)
        table[i][0] = par[i];
    for(int j=1; (1<<j) <=n; j++){
        for(int i=1; i<=n; i++){
            if( table[i][j-1] != -1 )
                table[i][j] = table[ table[i][j-1] ][j-1];
        }
    }
}
int getLCA(int p, int q, int n)
{
    if(lev[p]<lev[q]) swap(p,q);
    for(int i = lg; i>=0; i--){
        if(lev[p] - (1<<i) >= lev[q])
            p = table[p][i];
    }
    if(p==q) return p;
    for(int i = lg; i>=0; i--){
        if( (1<<i) <=lev[p] && table[p][i]!=-1 && table[p][i] != table[q][i] ){
            p = table[p][i];
            q = table[q][i];
        }
    }
    return par[p];
}
int dist(int p, int q, int n)
{
    int lca = getLCA(p,q,n);
    return ((-2)*cost[lca] + cost[p] + cost[q]);
}
int liftUp(int a, int k)
{
    //cout<<"up: "<<a<<" to "<<k<<endl;
    for(int i=lg; i>=0; i--){
        if((1<<i)<=k){
            a = table[a][i];
            k-=(1<<i);
        }
    }
    return a;
}
int kth(int p, int q, int n, int k)
{
    int lca = getLCA(p,q,n);
    if(lca==p){
        return liftUp(q,(lev[q] - lev[p])-k+1);
    }
    else if(lca==q){
        return liftUp(p,k-1);
    }
    if(lev[p] - lev[lca] >= k){
        return liftUp(p,k-1);
    }
    else{
        k = k - (lev[p] - lev[lca]);
        k = lev[q] - lev[lca] - k;
        return liftUp(q,k+1);
    }
}
void refresh(int n = mx-1)
{
    for(int i=1; i<=n; i++){
        adj[i].clear();
        wt[i].clear();
        lev[i] = -1;
        cost[i] = 1000000007;
        par[i] = -1;
    }
}
int main()
{
    int tc,n,a,b,c;
    char str[5];
    scanf("%d",&tc);
    while(tc--){
        scanf("%d",&n);
        refresh(n);
        for(int i=1; i<n; i++){
            scanf("%d%d%d",&a, &b, &c);
            adj[a].push_back(b);
            adj[b].push_back(a);
            wt[a].push_back(c);
            wt[b].push_back(c);
        }
        getTable(n);
        while(scanf("%s",str)){
            if(strcmp(str, "DONE") == 0)
                break;
            else if(strcmp(str,"DIST")==0){
                scanf("%d%d",&a,&b);
                printf("%d\n",dist(a,b,n));
            }
            else{
                scanf("%d%d%d",&a,&b,&c);
                printf("%d\n",kth(a,b,n,c));
            }
        }
    }
    return 0;
}