#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
#define mx  100004
int tree[3][mx*4], lazy[3][mx*4];
 
void update(int pos,  int b, int e, int i, int j, int id)
{
    int m = (b+e)/2;
    int l = pos*2+1;
    int r = l+1;
    if(lazy[id][pos]){
        tree[id][pos] = (e-b+1) - tree[id][pos];
        if(b!=e){
            lazy[id][l]^=1;
            lazy[id][r]^=1;
        }
        lazy[id][pos] = 0;
    }
    if(b>e || b>j || e<i) return;
    if(b>=i && e<=j){
        tree[id][pos] = (e-b+1) - tree[id][pos];
        if(b!=e){
            lazy[id][l]^=1;
            lazy[id][r]^=1;
        }
        return;
    }
    update(l,b,m,i,j,id);
    update(r,m+1,e,i,j,id);
    tree[id][pos] = tree[id][l] + tree[id][r];
}
int query(int pos, int b, int e, int i, int j, int id)
{
    int m = (b+e)/2;
    int l = pos*2+1;
    int r = l+1;
    if(lazy[id][pos]){
        tree[id][pos] = (e-b+1) - tree[id][pos];
        if(b!=e){
            lazy[id][l]^=1;
            lazy[id][r]^=1;
        }
        lazy[id][pos] = 0;
    }
    if(b>e || b>j || e<i) return 0;
    if(b>=i && e<=j){
        return tree[id][pos];
    }
    return (query(l,b,m,i,j,id) + query(r,m+1,e,i,j,id));
}
int main()
{
    int tc,x[2],y[2],z[2],a,b,c,n[3],m;
    scanf("%d", &tc);
    while(tc--){
        for(int i=0; i<3; i++) scanf("%d", &n[i]);
        scanf("%d", &m);
        while(m--){
            scanf("%d", &a);
            if(a==3){
                scanf("%d%d%d",&x[0], &y[0], &z[0]);
                scanf("%d%d%d",&x[1], &y[1], &z[1]);
                ll rx = query(0,0,n[0]-1,x[0],x[1],0);
                ll ry = query(0,0,n[1]-1,y[0],y[1],1);
                ll rz = query(0,0,n[2]-1,z[0],z[1],2);
                ll gx = (x[1]-x[0])+1 - rx;
                ll gy = (y[1]-y[0])+1 - ry;
                ll gz = (z[1]-z[0])+1 - rz;
                ll ans = (rx*ry*rz) + (gx*gy*rz) + (gx*ry*gz) + (rx*gy*gz);
                printf("%lld\n",ans);
            }
            else{
                scanf("%d%d", &b, &c);
                update(0,0,n[a]-1,b,c,a);
            }
        }
        if(tc>0){
            memset(tree, 0, sizeof tree);
            memset(lazy, 0, sizeof lazy);
        }
    }
    return 0;
}