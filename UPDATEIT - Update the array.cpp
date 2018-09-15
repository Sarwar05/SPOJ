#include<bits/stdc++.h>
#define mx 10005
long long tree[mx*4],lazy[mx*4];
void update(int pos, int b, int e, int i, int j, long long val)
{
    int m = (b+e)/2;
    int l = pos*2 + 1;
    int r = l+1;
    if(lazy[pos]!=0){
        tree[pos] = tree[pos] + (e-b+1)*lazy[pos];
        if(b!=e){
            lazy[l]+=lazy[pos];
            lazy[r]+=lazy[pos];
        }
        lazy[pos] = 0;
    }
    if(b>e || b>j ||e<i) return;
    if(b>=i && e<=j){
        tree[pos] = tree[pos] + (e-b+1)*val;
        if(b!=e){
            lazy[l]+=val;
            lazy[r]+=val;
        }
        return;
    }
    update(l,b,m,i,j,val);
    update(r,m+1,e,i,j,val);
    tree[pos] = tree[l]+tree[r];
}
long long query(int pos, int b, int e, int i, int j)
{
    int m = (b+e)/2;
    int l = pos*2 + 1;
    int r = l+1;
    if(lazy[pos]!=0){
        tree[pos] = tree[pos] + (e-b+1)*lazy[pos];
        if(b!=e){
            lazy[l]+=lazy[pos];
            lazy[r]+=lazy[pos];
        }
        lazy[pos] = 0;
    }
    if(b>e || b>j ||e<i) return 0;
    if(b>=i && e<=j){
        return tree[pos];
    }
    long long r1 = query(l,b,m,i,j);
    long long r2 = query(r,m+1,e,i,j);
    return (r1+r2);
}
int main()
{
    int tc,n,q,a,b,c,i;
    scanf("%d",&tc);
 
    while(tc--){
        memset(tree,0,sizeof tree);
        memset(lazy,0,sizeof lazy);
        scanf("%d%d",&n,&q);
        for(i=1; i<=q; i++){
            scanf("%d%d%d",&a,&b,&c);
            update(0,0,n-1,a,b,c);
        }
        scanf("%d",&q);
        while(q--){
            scanf("%d",&a);
            printf("%lld\n",query(0,0,n-1,a,a));
        }
    }
    return 0;
}
 