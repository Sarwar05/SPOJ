include<bits/stdc++.h>
#define mx 1000006
int tree[mx*4],lazy[mx*4];
void update(int pos, int b, int e, int i, int j, int val)
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
int query(int pos, int b, int e, int i, int j)
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
    int r1 = query(l,b,m,i,j);
    int r2 = query(r,m+1,e,i,j);
    return (r1+r2);
}
int main()
{
    int n,m,w,a,b;
    scanf("%d%d%d",&n,&m,&w);
    while(n--){
        scanf("%d%d",&a,&b);
        update(0,0,w-1,a,b,1);
    }
    while(m--){
        scanf("%d",&a);
        printf("%d\n",query(0,0,w-1,a,a));
    }
    return 0;
}