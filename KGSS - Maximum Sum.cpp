#include<bits/stdc++.h>
using namespace std;
#define mx 100005
struct node
{
    int first;
    int second;
}tree[mx*4],zero;
int arr[mx];
node merge(node a, node b)
{
    int aa[4];
    aa[0] = a.first;
    aa[1] = a.second;
    aa[2] = b.first;
    aa[3] = b.second;
    sort(aa,aa+4);
    node ret;
    ret.first = aa[3];
    ret.second = aa[2];
    return ret;
}
void build(int pos, int b, int e)
{
    if(b>e) return;
    if(b==e){
        tree[pos].first = arr[b];
        tree[pos].second = -1;
        return;
    }
    int m = (b+e)/2;
    int l = pos*2;
    int r = l+1;
    build(l,b,m);
    build(r,m+1,e);
    tree[pos] = merge(tree[l],tree[r]);
}
void update(int pos, int b, int e, int i, int j, int val)
{
    if(b>e || b>j || e<i) return;
    //cout<<"update call "<<b<<" "<<e<<endl;
    if(b==e){
        tree[pos].first = val;
        tree[pos].second = -1;
        return;
    }
    int m = (b+e)/2;
    int l = pos*2;
    int r = l+1;
    update(l,b,m,i,j,val);
    update(r,m+1,e,i,j,val);
    tree[pos] = merge(tree[l],tree[r]);
}
node query(int pos, int b, int e, int i, int j)
{
    if(b>e || b>j || e<i) return zero;
    //cout<<"query call "<<b<<" "<<e<<endl;
    if(b>=i && e<=j){
        return tree[pos];
    }
    int m = (b+e)/2;
    int l = pos*2;
    int r = l+1;
    node n1 = query(l,b,m,i,j);
    node n2 = query(r,m+1,e,i,j);
    return merge(n1,n2);
}
int main()
{
    zero.first = zero.second = -1;
    int n,q,a,b,c;char ch;
    scanf("%d",&n);
    for(int i=1; i<=n; i++) scanf("%d",&arr[i]);
    build(1,1,n);
    scanf("%d",&q);
    while(q--){
        scanf("%*c%c%d%d",&ch,&a,&b);
        if(ch=='U') update(1,1,n,a,a,b);
        else{
            node nn = query(1,1,n,a,b);
            printf("%d\n",nn.first + nn.second);
        }
    }
    return 0;
}