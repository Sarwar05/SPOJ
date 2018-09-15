#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define mx 100005
ll arr[mx];
ll tree[mx*4];
ll mtree[mx*4];
void build(int pos, int b, int e)
{
    if(b>e) return;
    if(b==e){
        tree[pos] = arr[b];
        mtree[pos] = arr[b];
        return ;
    }
    int mid = (b+e)/2;
    int left = pos*2;
    int right = left+1;
    build(left, b, mid);
    build(right,mid+1,e);
    tree[pos] = tree[left] + tree[right];
    mtree[pos]  = max(mtree[left], mtree[right]);
}
void update(int pos, int b, int e, int i, int j)
{
    if(b>e || b>j || e<i) return;
    if(mtree[pos]==1) return;
    if(b>=i && e<=j && b==e){
        tree[pos] = sqrt(tree[pos]);
        mtree[pos] = tree[pos];
        return;
    }
    int mid = (b+e)/2;
    int left = pos*2;
    int right = left+1;
    update(left,b,mid,i,j);
    update(right,mid+1,e,i,j);
    tree[pos] = tree[left] + tree[right];
    mtree[pos]  = max(mtree[left], mtree[right]);
}
ll query(int pos, int b, int e, int i, int j)
{
    if(b>e || b>j || e<i) return 0;
    if(b>=i && e<=j)return tree[pos];
    int mid = (b+e)/2;
    int left = pos*2;
    int right = left+1;
    return (query(left,b,mid,i,j)+query(right,mid+1,e,i,j));
}
int main()
{
    int n,l,r,q,c;
    int a;
    int tc=1;
    while(scanf("%d",&n)!=EOF){
        memset(tree,0,sizeof tree);
        memset(mtree,0,sizeof mtree);
        for(int i=1; i<=n; i++){
            scanf("%lld",&arr[i]);
        }
        build(1,1,n);
        scanf("%d",&q);
        printf("Case #%d:\n",tc++);
        while(q--){
            scanf("%d%d%d",&a, &l,&r);
            if(l>r) swap(l,r);
            if(a==0)
                update(1,1,n,l,r);
            else
                printf("%lld\n",query(1,1,n,l,r));
        }
        printf("\n");
    }
    return 0;
}