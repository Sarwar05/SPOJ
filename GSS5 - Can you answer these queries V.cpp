#include<bits/stdc++.h>
using namespace std;
#define mx 10004
#define inf 1000000000
int max3(int a, int b, int c)
{
    return max(a,max(b,c));
}
int max4(int a, int b, int c, int d)
{
    return max(a,max3(b,c,d));
}
struct Node
{
    int tot;
    int pre;
    int suf;
    int best;
}tree[mx*4],neg;
int arr[mx];
Node merge(Node a, Node b)
{
    if(a.tot==-inf) return b;
    if(b.tot ==-inf) return a;
    Node ret;
    ret.tot = a.tot + b.tot;
    ret.pre = max(a.pre, a.tot+b.pre);
    ret.suf = max(b.suf, b.tot+a.suf);
    ret.best = max3(a.best,b.best,a.suf+b.pre);
    return ret;
}
void build(int pos, int b, int e)
{
    if(b>e) return;
    int m = (b+e)/2;
    int l = pos*2;
    int r = l+1;
    if(b==e){
        tree[pos].tot = tree[pos].pre = tree[pos].suf = tree[pos].best = arr[b];
        return;
    }
    build(l,b,m);
    build(r,m+1,e);
    tree[pos] = merge(tree[l],tree[r]);
}
Node query(int pos, int b, int e, int i, int j)
{
    if(b>e || b>j || e<i) return neg;
    int m = (b+e)/2;
    int l = pos*2;
    int r = l+1;
    if(b>=i && e<=j){
        return tree[pos];
    }
    return merge(query(l,b,m,i,j), query(r,m+1,e,i,j));
}
int main()
{
    int tc,n,q,a,b,c,d;
    neg.tot = -inf;
    scanf("%d", &tc);
    while(tc--){
        scanf("%d", &n);
        for(int i=1; i<=4*n; i++){
            tree[i].tot = -inf;
        }
        for(int i=1; i<=n; i++){
            scanf("%d", &arr[i]);
        }
        build(1,1,n);
        scanf("%d", &q);
        while(q--){
            scanf("%d%d%d%d", &a, &b,&c, &d);
            int add = 0,ans=-inf;
            if((b+1)<c){/// gape
                Node rm = query(1,1,n,b+1,c-1);
                add = rm.tot;
                Node rl = query(1,1,n,a,b);
                Node rr = query(1,1,n,c,d);
                ans = max4(add+rl.suf+rr.pre, add+rl.tot+rr.pre,add+rl.suf+rr.tot, add+rl.tot+rr.tot);
            }
            else if((b+1)==c){/// no gape
                Node rl = query(1,1,n,a,b);
                Node rr = query(1,1,n,c,d);
                ans = max4(add+rl.suf+rr.pre, add+rl.tot+rr.pre,add+rl.suf+rr.tot, add+rl.tot+rr.tot);
            }
            else{/// overlap
                int x = c-1;
                int y = b+1;
                Node ro = query(1,1,n,c,b);
                Node rl = query(1,1,n,a,x);
                Node rr = query(1,1,n,y,d);
                ans = max4(ro.best,rl.suf+ro.pre,ro.suf+rr.pre,ro.tot+rl.suf+rr.pre);
            }
            printf("%d\n",ans);
        }
    }
    return 0;
}