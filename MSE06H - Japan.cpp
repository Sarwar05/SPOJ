#include<bits/stdc++.h>
using namespace std;
#define mx 1002
#define ll long long
int tree[mx*4];
int arr[mx];
void update(int pos, int b, int e, int i, int j)
{
    if(b>e||b>j||e<i) return;
    if(b>=i && e<=j){
        tree[pos]++;
        return;
    }
    int m = (b+e)/2;
    int l = pos*2;
    int r = l+1;
    update(l,b,m,i,j);
    update(r,m+1,e,i,j);
    tree[pos] = tree[l] + tree[r];
}
int query(int pos, int b, int e, int i, int j)
{
    if(b>e||b>j||e<i) return 0;
    if(b>=i && e<=j)
        return tree[pos];
    int m = (b+e)/2;
    int l = pos*2;
    int r = l+1;
    return query(l,b,m,i,j) + query(r,m+1,e,i,j);
}
vector<int> adj[mx];
int main()
{
    int tc,n,m,k,a,b, cs=1;
    scanf("%d",&tc);
    while(tc--){
        scanf("%d%d%d",&n,&m,&k);
        int mxx = max(n,m);
        for(int i=1; i<=mxx; i++)
            adj[i].clear();
        for(int i=1; i<=k; i++){
            scanf("%d%d",&a,&b);
            adj[a].push_back(b);
        }
        for(int i=1; i<=mxx; i++)
            sort(adj[i].begin(), adj[i].end());
        ll ans = 0;
        memset(tree, 0, sizeof tree);
        for(int i=1; i<=n; i++){
            for(int j=0; j<(int)adj[i].size(); j++){
                int to = adj[i][j];
                ans+=query(1,1,m,to+1,m);
                update(1,1,m,to,to);
            }
        }
        printf("Test case %d: %lld\n",cs++, ans);
    }
}