#include<bits/stdc++.h>
using namespace std;
#define mx 1000005
int tree[mx*4];
void update(int pos, int b, int e, int i, int j)
{
    if(b>e || b>j || e<i) return;
    if(b>=i && e<=j){
        tree[pos] = tree[pos]+1;
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
    if(b>e || b>j || e<i) return 0;
    if(b>=i && e<=j) return tree[pos];
    int m = (b+e)/2;
    int l = pos*2;
    int r = l+1;
    int r1 = query(l,b,m,i,j);
    int r2 = query(r,m+1,e,i,j);
    return (r1+r2);
}
int main()
{
    int tc,n,a,add;
    scanf("%d",&tc);
    while(tc--){
        long long ans = 0;
        memset(tree, 0, sizeof tree);
        scanf("%d",&n);
        while(n--){
            scanf("%d",&a);
            add = query(1,1,mx-2,a+1,mx-2);
            ans = ans + add;
            update(1,1,mx-2,a,a);
        }
        printf("%lld\n",ans);
    }
    return 0;
}