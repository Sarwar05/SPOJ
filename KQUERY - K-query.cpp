#include<bits/stdc++.h>
using namespace std;
#define mx 30005
int tree[mx*4] = {0};
struct leaf
{
    int val;
    int ind;
}arr[mx];
bool compl1(leaf ob1, leaf ob2)
{
    return ob1.val>ob2.val;
}
struct query
{
    int k;
    int l;
    int r;
    int id;
 
}q[200005];
int ans[200005];
bool compq1(query ob1, query ob2)
{
    return ob1.k>ob2.k;
}
void update(int pos, int b, int e, int i, int j)
{
    if(b>e || b>j || e<i) return;
    if(b>=i && e<=j){
        tree[pos] = 1;
        return;
    }
    int l = pos*2+1;
    int r = l+1;
    int mid = (b+e)/2;
    update(l,b,mid,i,j);
    update(r, mid+1,e,i,j);
    tree[pos] = tree[l]+tree[r];
}
int Query(int pos, int b, int e, int i, int j)
{
    if(b>j || e<i || b>e) return 0;
    if(b>=i && e<=j) return tree[pos];
    int l = pos*2+1;
    int r = l+1;
    int mid = (b+e)/2;
    int r1 = Query(l,b,mid,i,j);
    int r2 = Query(r, mid+1,e,i,j);
    return r1 + r2;
}
int main()
{
    int n,qr,a;
    scanf("%d",&n);
    for(int i=0; i<n; i++){
        scanf("%d",&arr[i].val);
        arr[i].ind = i;
    }
    sort(arr, arr+n,compl1);
    int idl = 0;
    scanf("%d",&qr);
    for(int i=0; i<qr; i++){
        scanf("%d%d%d",&q[i].l,&q[i].r,&q[i].k);
        q[i].id=i;
        q[i].l--;
        q[i].r--;
    }
    sort(q,q+qr,compq1);
    for(int i=0; i<qr; i++){
        for(idl; idl<n && arr[idl].val> q[i].k; idl++){
            update(0,0,n-1,arr[idl].ind,arr[idl].ind);
        }
        ans[q[i].id] = Query(0,0,n-1,q[i].l, q[i].r);
    }
    for(int i=0; i<qr; i++){
        printf("%d\n",ans[i]);
    }
    return 0;
}