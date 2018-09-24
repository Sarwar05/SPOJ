#include<bits/stdc++.h>
using namespace std;
#define mx 100002
#define pii pair<int, int>
/// AC -> 0.70
int parent[mx][17],mxtree[mx][17],mntree[mx][17], level[mx];
vector<pii>adj[mx];
void dfs(int u, int p, int l)
{
    parent[u][0] = p;
    level[u] = l;
    for(int i=0; i<adj[u].size(); i++){
        int v = adj[u][i].first;
        if(v==p) continue;
        mxtree[v][0] = mntree[v][0] = adj[u][i].second;
        dfs(v,u, l+1);
    }
}
pii query(int p, int q)
{
    int mxe = 0, mne = 1000006;
    if(level[p] < level[q])
        swap(p,q);
    for(int j=16; j>=0; j--){
        if(level[p] - (1<<j) >=level[q] && parent[p][j]!=-1){
            mxe = max(mxe, mxtree[p][j]);
            mne = min(mne, mntree[p][j]);
            p = parent[p][j];
        }
    }
    if(p!=q){
        for(int j=16; j>=0; j--){
            if(parent[p][j]!=-1 && parent[p][j]!=parent[q][j]){
                mxe = max(mxe, mxtree[p][j]);
                mne = min(mne, mntree[p][j]);
                mxe = max(mxe, mxtree[q][j]);
                mne = min(mne, mntree[q][j]);
                p = parent[p][j];
                q = parent[q][j];
            }
        }
        mxe = max(mxe, mxtree[p][0]);
        mne = min(mne, mntree[p][0]);
        mxe = max(mxe, mxtree[q][0]);
        mne = min(mne, mntree[q][0]);
    }
    return {mne, mxe};
}
int main()
{
    int n,a,b,c,q;
    scanf("%d",&n);
    for(int i=1; i<=n; i++)
        adj[i].clear();
    for(int i=1; i<n; i++){
        scanf("%d%d%d",&a,&b,&c);
        adj[a].push_back({b,c});
        adj[b].push_back({a,c});
    }
    memset(parent, -1, sizeof parent)
    dfs(1,-1, 0);
    for(int j=1; (1<<j) <=n ; j++){
        for(int i=1; i<=n; i++){
            if(parent[i][j-1] != -1){
                parent[i][j] = parent[ parent[i][j-1] ][j-1];
                mxtree[i][j] = max(mxtree[i][j-1], mxtree[ parent[i][j-1] ][j-1]);
                mntree[i][j] = min(mntree[i][j-1], mntree[ parent[i][j-1] ][j-1]);
            }
        }
    }
    scanf("%d",&q);
    while(q--){
        scanf("%d%d",&a,&b);
        pii ans = query(a,b);
        printf("%d %d\n", ans.first, ans.second);
    }
}
/**
// AC-> 0.55
#include<bits/stdc++.h>
using namespace std;
#define mx 100002
#define pii pair<int, int>
int parent[17][mx],mxtree[17][mx],mntree[17][mx], level[mx];
vector<pii>adj[mx];
void dfs(int u, int p, int l)
{
    parent[0][u] = p;
    level[u] = l;
    for(int i=0; i<adj[u].size(); i++){
        int v = adj[u][i].first;
        if(v==p) continue;
        mxtree[0][v] = mntree[0][v] = adj[u][i].second;
        dfs(v,u, l+1);
    }
}
pii query(int p, int q)
{
    int mxe = 0, mne = 1000006;
    if(level[p] < level[q])
        swap(p,q);
    for(int j=16; j>=0; j--){
        if(level[p] - (1<<j) >=level[q] && parent[j][p]!=-1){
            mxe = max(mxe, mxtree[j][p]);
            mne = min(mne, mntree[j][p]);
            p = parent[j][p];
        }
    }
    if(p!=q){
        for(int j=16; j>=0; j--){
            if(parent[j][p]!=-1 && parent[j][p]!=parent[j][q]){
                mxe = max(mxe, mxtree[j][p]);
                mne = min(mne, mntree[j][p]);
                mxe = max(mxe, mxtree[j][q]);
                mne = min(mne, mntree[j][q]);
                p = parent[j][p];
                q = parent[j][q];
            }
        }
        mxe = max(mxe, mxtree[0][p]);
        mne = min(mne, mntree[0][p]);
        mxe = max(mxe, mxtree[0][q]);
        mne = min(mne, mntree[0][q]);
    }
    return {mne, mxe};
}
int main()
{
    int n,a,b,c,q;
    scanf("%d",&n);
    for(int i=1; i<=n; i++)
        adj[i].clear();
    for(int i=1; i<n; i++){
        scanf("%d%d%d",&a,&b,&c);
        adj[a].push_back({b,c});
        adj[b].push_back({a,c});
    }
    memset(parent, -1, sizeof parent);
    dfs(1,-1, 0);
    for(int j=1; (1<<j) <=n ; j++){
        for(int i=1; i<=n; i++){
            if(parent[j-1][i] != -1){
                parent[j][i] = parent[j-1][ parent[j-1][i] ];
                mxtree[j][i] = max(mxtree[j-1][i], mxtree[j-1][ parent[j-1][i] ]);
                mntree[j][i] = min(mntree[j-1][i], mntree[j-1][ parent[j-1][i] ]);
            }
        }
    }
    scanf("%d",&q);
    while(q--){
        scanf("%d%d",&a,&b);
        pii ans = query(a,b);
        printf("%d %d\n", ans.first, ans.second);
    }
}


*/
