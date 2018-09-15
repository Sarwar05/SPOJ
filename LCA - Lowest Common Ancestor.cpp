#include<bits/stdc++.h>
using namespace std;
#define mx 100005
#define lg 10
vector<int> adj[mx];
int lev[mx];
int par[mx];
int table[mx][ lg+1 ];
void dfs(int p, int s, int l)
{
    par[s] = p;
    lev[s] = l;
    for(int i=0; i<(int)adj[s].size(); i++){
        int v = adj[s][i];
        if(v==p) continue;
        dfs(s,v,l+1);
    }
}
void getTable(int n)
{
    dfs(-1,1,0);
    for(int i=0; i<=n; i++){
        table[i][0] = par[i];
    }
    for(int j=1; (1<<j) <= n; j++){
        for(int i=0; i<=n; i++){
            if(table[i][j-1] != -1){
                table[i][j] = table[ table[i][j-1] ][j-1];
            }
        }
    }
}
int getLCA(int p, int q, int n)
{
    if(lev[p]<lev[q]) swap(p,q);
    int log = lg;
    for(int i=log; i>=0; i--){
        if(lev[p] - (1<<i) >= lev[q]){
            p = table[p][i];
        }
    }
    if(p==q) return q;
    for(int i=log; i>=0; i--){
        if( table[p][i] !=-1 && table[p][i] != table[q][i] ){
            p = table[p][i];
            q = table[q][i];
        }
    }
    return par[p];
}
void refresh(int n=mx-1)
{
    for(int i=0; i<=n; i++)
        adj[i].clear();
    memset(lev, -1, sizeof lev);
    memset(par, -1, sizeof par);
    memset(table, -1, sizeof table);
}
int main()
{
    int tc;;scanf("%d",&tc);
    int n=0,a,b,q,cs=1;
    while(tc--){
        refresh(n);
        scanf("%d",&n);
        for(int i=1; i<=n; i++){
            scanf("%d",&b);
            while(b--){
                scanf("%d",&a);
                adj[i].push_back(a);
                adj[a].push_back(i);
            }
        }
        getTable(n);
        scanf("%d",&q);
        printf("Case %d:\n",cs++);
        while(q--){
            scanf("%d%d",&a,&b);
            printf("%d\n",getLCA(a,b,n));
        }
    }
    return 0;
}
 