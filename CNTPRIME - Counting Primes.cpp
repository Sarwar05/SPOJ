#include<bits/stdc++.h>
using namespace std;
#define mxx 1000006
#define mx 10004
int prime[mxx] = {0};
void sieve()
{
    prime[0] = prime[1] = 1;
    for(int i=4; i<mxx; i+=2) prime[i] = 1;
    for(long long j=3; j<mxx; j+=2){
        if(prime[j]==0){
            for(long long i = j*j; i<mxx; i+=j) prime[i] = 1;
        }
    }
}
int tree[mx*4], lazy[mx*4],arr[mx];
void build(int pos, int b, int e)
{
    if(b>e) return;
    if(b==e){
        tree[pos] = arr[b];
        return;
    }
    int m = (b+e)/2;
    int l = pos*2;
    int r = l+1;
    build(l,b,m);
    build(r,m+1,e);
    tree[pos] = tree[l] + tree[r];
}
void update(int pos, int b, int e, int i, int j, int p)
{
    int m = (b+e)/2;
    int l = pos*2;
    int r = l+1;
    if(lazy[pos]!=-1){
        tree[pos] = (e-b+1)*lazy[pos];
        if(b!=e){
            lazy[l] = lazy[pos];
            lazy[r] = lazy[pos];
        }
        lazy[pos] = -1;
    }
    if(b>e || b>j || e<i) return;
    if(b>=i && e<=j){
        tree[pos] = p*(e-b+1);
        if(b!=e){
            lazy[l] = p;
            lazy[r] = p;
        }
        return;
    }
    update(l,b,m,i,j,p);
    update(r,m+1,e,i,j,p);
    tree[pos] = tree[l] + tree[r];
}
int query(int pos, int b, int e, int i, int j)
{
    int m = (b+e)/2;
    int l = pos*2;
    int r = l+1;
    if(lazy[pos]!=-1){
        tree[pos] = (e-b+1)*lazy[pos];
        if(b!=e){
            lazy[l] = lazy[pos];
            lazy[r] = lazy[pos];
        }
        lazy[pos] = -1;
    }
    if(b>e || b>j || e<i) return 0;
    if(b>=i && e<=j){
        return tree[pos];
    }
    return query(l,b,m,i,j) + query(r,m+1,e,i,j);
}
int main()
{
    sieve();
    int tc,n,q,a,b,c,d,cs=1;
    scanf("%d",&tc);
    while(tc--){
        memset(lazy,-1,sizeof lazy);
        scanf("%d%d",&n,&q);
        for(int i=1; i<=n; i++){
            scanf("%d",&a);
            arr[i] = !prime[a];
        }
        build(1,1,n);
        printf("Case %d:\n\n",cs++);
        while(q--){
            scanf("%d",&d);
            if(d==0){
                scanf("%d%d%d",&a,&b,&c);
                update(1,1,n,a,b,!prime[c]);
            }
            else{
                scanf("%d%d",&a,&b);
                printf("%d\n\n",query(1,1,n,a,b));
            }
        }
    }
    return 0;
}
/*
1
5 3
78 2 13 12 3
1 1 2
0 4 4 5
1 1 5
*/