#include<bits/stdc++.h>
using namespace std;
#define mx 100005
struct str
{
    int zero, one, two;
};
str tree[mx*4];
str init;
int lazy[mx*4];
void build(int pos, int b, int e)
{
    if(b>e) return;
    if(b==e){
        tree[pos].zero = 1;
        return;
    }
    int mid = (b+e)/2;
    int l = pos*2;
    int r = l+1;
    build(l, b, mid);
    build(r, mid+1, e);
    tree[pos].zero = tree[l].zero + tree[r].zero;
}
void update(int pos, int b, int e, int i, int j)
{
    if(b>e) return;
    int mid = (b+e)/2;
    int l = pos*2;
    int r = l+1;
    if(lazy[pos] != 0){
        lazy[pos]%=3;
        for(int ind = 1; ind<=lazy[pos]; ind++){
            swap(tree[pos].zero, tree[pos].two);
            swap(tree[pos].one, tree[pos].two);
        }
 
        if(b!= e){
            lazy[l] += lazy[pos];
            lazy[r] += lazy[pos];
        }
        lazy[pos] = 0;
    }
    if(b>j || e<i) return;
    if(b>=i && e<=j){
        swap(tree[pos].zero, tree[pos].two);
        swap(tree[pos].one, tree[pos].two);
        if(b!= e){
            lazy[l]++;
            lazy[r]++;
        }
        return;
    }
    update(l, b, mid, i, j);
    update(r, mid+1, e, i, j);
    tree[pos].one = tree[l].one + tree[r].one;
    tree[pos].two = tree[l].two + tree[r].two;
    tree[pos].zero = tree[l].zero + tree[r].zero;
}
int query(int pos, int b, int e, int i, int j)
{
    if(b>e) return 0;
    int mid = (b+e)/2;
    int l = pos*2;
    int r = l+1;
    if(lazy[pos] != 0){
        lazy[pos]%=3;
        for(int ind = 1; ind<=lazy[pos]; ind++){
            swap(tree[pos].zero, tree[pos].two);
            swap(tree[pos].one, tree[pos].two);
        }
 
        if(b!= e){
            lazy[l] += lazy[pos];
            lazy[r] += lazy[pos];
 
        }
        lazy[pos] = 0;
    }
    if(b>j || e<i) return 0;
    if(b>=i && e<=j){
        return tree[pos].zero;
    }
    int q1 = query(l, b, mid, i, j);
    int q2 = query(r, mid+1, e, i, j);
    return q1 + q2;
}
int main()
{
    int tc,n,q,a,b,c, cs=1;
    init.zero = init.one = init.two = 0;
    tc = 1;//scanf("%d", &tc);
    while(tc--){
        //printf("Case %d:\n", cs++);
        for(int i=0; i<mx*4; i++){
            lazy[i] = 0;
            tree[i] = init;
        }
        scanf("%d%d", &n, &q);
        build(1,1,n);
        while(q--){
            scanf("%d%d%d", &c, &a, &b);
            if(c==0){
                update(1,1,n,a+1, b+1);
                //cout<<"top: "<<tree[1].zero<<endl;
            }
            else{
                printf("%d\n", query(1,1,n,a+1, b+1));
            }
        }
    }
    return 0;
}