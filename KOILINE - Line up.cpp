#include<bits/stdc++.h>
using namespace std;
#define mx 100005
int arr[mx];
int tree[mx*4];
int ans[mx];
int val[mx];
void build(int pos, int b, int e)
{
    if(b>e) return;
    if(b==e){
        tree[pos] = 1;
        return;
    }
    int m = (b+e)/2;
    int l = pos*2;
    int r = l+1;
    build(l,b,m);
    build(r,m+1,e);
    tree[pos] = tree[l]  +tree[r];
}
int query(int pos, int b, int e, int k)
{
    if(b==e) return b;
    int m = (b+e)/2;
    int l = pos*2;
    int r = l+1;
    if(tree[l]>=k) return query(l,b,m,k);
    else return query(r,m+1,e,k-tree[l]);
}
void update(int pos, int b, int e,int i, int j)
{
    if(b>e || b>j || e<i) return;
    if(b==e){
        tree[pos] = 0;
        return;
    }
    int m = (b+e)/2;
    int l = pos*2;
    int r = l+1;
    update(l,b,m,i,j);
    update(r,m+1,e,i,j);
    tree[pos] = tree[l] + tree[r];
}
int main()
{
    int n;
    scanf("%d",&n);
    for(int i=1; i<=n; i++) scanf("%d",&val[i]);
    sort(val+1,val+n+1);
    for(int i=1; i<=n; i++){
        scanf("%d",&arr[i]);
    }
    build(1,1,n);
    for(int i=n; i>=1; i--){
        int put = arr[i]+1;
        int id = query(1,1,n,put);
        update(1,1,n,id,id);
        ans[i] = id;
    }
    for(int i=1; i<=n; i++) printf("%d\n",val[ans[i]]);
 
    return 0;
}