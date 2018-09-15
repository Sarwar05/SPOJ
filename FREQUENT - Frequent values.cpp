#include<bits/stdc++.h>
using namespace std;
#define mx 100005
int arr[mx];
struct node
{
    int lval;
    int lcnt;
    int rval;
    int rcnt;
    int mcnt;
}tree[mx*4],zero;
node merge(node a, node b)
{
    if(a.mcnt==-1) return b;
    if(b.mcnt==-1) return a;
    node ret;
    if(a.lval == b.rval){
        ret.mcnt = a.mcnt + b.mcnt;
        ret.lval = a.lval;
        ret.lcnt = ret.mcnt;
        ret.rval = a.lval;
        ret.rcnt = ret.mcnt;
    }
    else if(a.rval == b.lval){
        if(a.mcnt >=(a.rcnt + b.lcnt) && a.mcnt>=b.mcnt){
            ret.mcnt = a.mcnt;
            ret.lval = a.lval;
            ret.lcnt = a.lcnt;
            ret.rval = b.rval;
            ret.rcnt = b.rcnt;
        }
        else if(b.mcnt>=(a.rcnt + b.lcnt) && b.mcnt>=a.mcnt){
            ret.mcnt = b.mcnt;
            ret.lval = a.lval;
            ret.lcnt = a.lcnt;
            ret.rval = b.rval;
            ret.rcnt = b.rcnt;
        }else if(a.lval==a.rval){
            ret.mcnt = a.mcnt + b.lcnt;
            ret.lval = a.lval;
            ret.lcnt = ret.mcnt;
            ret.rval = b.rval;
            ret.rcnt = b.rcnt;
        }
        else if(b.rval==b.lval){
            ret.mcnt = b.mcnt + a.rcnt;
            ret.lval = a.lval;
            ret.lcnt = a.lcnt;
            ret.rval = b.rval;
            ret.rcnt = ret.mcnt;
        }
        else{
            ret.mcnt = (a.rcnt + b.lcnt);
            ret.lval = a.lval;
            ret.lcnt = a.lcnt;
            ret.rval = b.rval;
            ret.rcnt = b.rcnt;
        }
    }
    else{
        ret.lval = a.lval;
        ret.lcnt = a.lcnt;
        ret.rval = b.rval;
        ret.rcnt = b.rcnt;
        if(a.mcnt>=b.mcnt){
            ret.mcnt = a.mcnt;
        }
        else{
            ret.mcnt = b.mcnt;
        }
    }
    return ret;
}
void build(int pos, int b, int e)
{
    if(b>e) return;
    if(b==e){
        tree[pos].lval = arr[b];
        tree[pos].lcnt = 1;
        tree[pos].rval = arr[b];
        tree[pos].rcnt = 1;
        tree[pos].mcnt = 1;
        return ;
    }
    int m = (b+e)/2;
    int l = pos*2;
    int r = l+1;
    build(l,b,m);
    build(r,m+1,e);
    tree[pos] = merge(tree[l],tree[r]);
}
node query(int pos, int b, int e, int i, int j)
{
    if(b>e || b>j || e<i) return zero;
    if(b>=i && e<=j) return tree[pos];
    int m = (b+e)/2;
    int l = pos*2;
    int r = l+1;
    node r1 = query(l,b,m,i,j);
    node r2 = query(r,m+1,e,i,j);
    return merge(r1,r2);
}
int main()
{
    int n,q,a,b,c;
    zero.mcnt = -1;
    while(scanf("%d",&n),n){
        scanf("%d",&q);
        for(int i=1; i<=n; i++) scanf("%d",&arr[i]);
        build(1,1,n);
        while(q--){
            scanf("%d%d",&a,&b);
            printf("%d\n",query(1,1,n,a,b).mcnt);
        }
    }
    return 0;
}