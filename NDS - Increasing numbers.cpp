
#include<bits/stdc++.h>
using namespace std;
#define mx 1000006
int tree[mx*4], arr[mx];
void update(int pos, int b, int e, int i, int j, int val)
{
    if(b>e || b>j || e<i) return;
    if(b>=i && e<=j){
        tree[pos] = max(tree[pos], val);
        return;
    }
    int m = (b+e)/2;
    int l = pos*2;
    int r = l+1;
    update(l,b,m,i,j,val);
    update(r,m+1,e,i,j,val);
    tree[pos] = max(tree[l], tree[r]);
}
int query(int pos, int b, int e, int i, int j)
{
    if(b>e || b>j || e<i) return 0;
    if(b>=i && e<=j){
        return tree[pos];
    }
    int m = (b+e)/2;
    int l = pos*2;
    int r = l+1;
    return max(query(l,b,m,i,j), query(r,m+1,e,i,j));
}
int main()
{
    int tc,n,a,l;
    scanf("%d",&tc);
    while(tc--){
        scanf("%d",&n);
        for(int i=1; i<=n; i++){
            scanf("%d",&arr[i]);
        }
        int ans = mx;
        scanf("%d",&l);
        memset(tree, 0, sizeof tree);
        for(int i=1; i<=n; i++){
            int prev = query(1,1,1000001,1,arr[i]);
            if(prev+1 == l)
                ans = min(ans, arr[i]);
            update(1,1,1000001, arr[i]+1, arr[i]+1, prev+1);
        }
        if(ans>1000001) ans = -1;
        printf("%d\n",ans);
    }
}
