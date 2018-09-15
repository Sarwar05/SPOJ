#include<bits/stdc++.h>
using namespace std;
#define sz 50005
 
struct node
{
    int tot;
    int pre;
    int suf;
    int mx;
}tree[sz*4];
int arr[sz];
node zero;
node merg(node l, node r)
{
    if(l.tot == INT_MIN) return r;
    if(r.tot == INT_MIN) return l;
    node ret;
    ret.tot = l.tot + r.tot;
    ret.pre = max(l.pre, l.tot + r.pre);
    ret.suf = max(r.suf, r.tot + l.suf);
    ret.mx = max( max(l.mx, r.mx), l.suf + r.pre );
    return ret;
}
void build(int pos, int b, int e)
{
    if(b>e) return;
    if(b==e){
        tree[pos].tot = tree[pos].pre = tree[pos].suf = tree[pos].mx = arr[b];
        return;
    }
    int mid = (b+e)/2;
    int l = pos*2;
    int r = l+1;
    build(l,b,mid);
    build(r,mid+1,e);
    tree[pos] = merg(tree[l],tree[r]);
}
node query(int pos, int b, int e, int i, int j)
{
    if(b>j || e<i) return zero;
    if(b>=i && e<=j){
        return tree[pos];
    }
    int mid = (b+e)/2;
    int l = pos*2;
    int r = l+1;
    return merg(query(l, b, mid,i,j),query(r, mid+1, e, i, j) );
}
int main()
{
    int n,q,a,b;
    scanf("%d",&n);
    zero.tot = zero.pre = zero.suf = zero.mx = INT_MIN;
    for(int i=1; i<=n; i++) scanf("%d",&arr[i]);
    scanf("%d",&q);
    build(1,1,n);
    while(q--){
        scanf("%d%d",&a,&b);
        printf("%d\n",query(1,1,n,a,b).mx);
    }
    return 0;
}