#include<bits/stdc++.h>
using namespace std;
#define mx 100005
int ans[mx], tree[mx*4], arr[mx*10];
void build(int pos, int b, int e)
{
    if(b>e) return;
    if(b==e){
        tree[pos] = arr[b];
        return;
    }
    int m = (b+e)/2;
    int l = (pos*2)+1;
    int r = l+1;
    build(l,b,m);
    build(r,m+1,e);
    tree[pos] = max(tree[l], tree[r]);
}
void update(int pos, int b, int e, int i, int val)
{
    if(b>e || b>i || e<i) return;
    if(b>=i && e<=i){
        tree[pos] = val;
        return;
    }
    int m = (b+e)/2;
    int l = (pos*2)+1;
    int r = l+1;
    update(l,b,m,i,val);
    update(r,m+1,e,i,val);
    tree[pos] = max(tree[l], tree[r]);
}
int main()
{
    int n,k;
    scanf("%d",&n);
    for(int i=0; i<n; i++) scanf("%d", &arr[i]);
    scanf("%d",&k);
    build(0,0,k-1);
    int id = 1;
    ans[id++] = tree[0];
    for(int i = k; i<n; i++){
        update(0,0,k-1,i%k,arr[i]);
        ans[id++] = tree[0];
    }
    printf("%d",ans[1]);
    for(int i=2; i<id; i++)printf(" %d",ans[i]);
    printf("\n");
    return 0;
}