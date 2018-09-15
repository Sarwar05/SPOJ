#include<bits/stdc++.h>
using namespace std;
#define mx 100005
int tree[mx*4]={0}, lazy[mx*4]={0};
void update(int pos, int b, int e, int i, int j)
{
    if(b>e) return;
    int m = (b+e)/2;
    int l = pos*2;
    int r = l+1;
    if(lazy[pos]!=0){
        lazy[pos]%=2;
        if(lazy[pos]==1){
            tree[pos] = (e-b+1) - tree[pos];
            if(b!=e){
                lazy[l]++;
                lazy[r]++;
                lazy[l]%=2;
                lazy[r]%=2;
            }
            lazy[pos] = 0;
        }
    }
    if(b>j || e<i) return;
    if(b>=i && e<=j){
        tree[pos] = (e-b+1) - tree[pos];
        if(b!=e){
            lazy[l]++;
            lazy[r]++;
            lazy[l]%=2;
            lazy[r]%=2;
        }
        return;
    }
    update(l, b, m, i, j);
    update(r, m+1, e, i, j);
    tree[pos] = tree[l] + tree[r];
}
int query(int pos, int b, int e, int i, int j)
{
    if(b>e) return 0;
    int m = (b+e)/2;
    int l = pos*2;
    int r = l+1;
    if(lazy[pos]!=0){
        lazy[pos]%=2;
        if(lazy[pos]==1){
            tree[pos] = (e-b+1) - tree[pos];
            if(b!=e){
                lazy[l]++;
                lazy[r]++;
                lazy[l]%=2;
                lazy[r]%=2;
            }
            lazy[pos] = 0;
        }
    }
    if(b>j || e<i) return 0;
    if(b>=i && e<=j){
        return tree[pos];
    }
    int q1 = query(l, b, m, i, j);
    int q2 = query(r, m+1, e, i, j);
    return q1 + q2;
}
int main()
{
    int n,m,c,a,b;
    scanf("%d%d", &n, &m);
    while(m--){
        scanf("%d%d%d", &c, &a, &b);
        if(c==0){
            update(1,1,n,a,b);
        }
        else{
            printf("%d\n", query(1,1,n,a,b));
        }
    }
    return 0;
}