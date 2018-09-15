#include<bits/stdc++.h>
using namespace std;
typedef vector<int> vi;
#define mx  30005
int arr[mx];
vi tree[mx*4];
vi merge(vi a, vi b)
{
    int alen = a.size();
    int blen = b.size();
    int i=0,j=0;
    vi ret;
    while(i<alen && j<blen){
        if(a[i]<b[j]){
            ret.push_back(a[i]);
            i++;
        }
        else{
            ret.push_back(b[j]);
            j++;
        }
    }
    while(i<alen){
        ret.push_back(a[i]);
        i++;
    }
    while(j<blen){
        ret.push_back(b[j]);
        j++;
    }
    return ret;
}
void build(int pos, int b, int e)
{
    if(b>e) return;
    if(b==e){
        tree[pos].push_back(arr[b]);
        return;
    }
    int m = (b+e)/2, l = pos*2;
    build(l,b,m);
    build(l+1,m+1,e);
    tree[pos] = merge(tree[l], tree[l+1]);
}
int query(int pos, int b, int e, int i, int j, int k)
{
    if(b>e || b>j || e<i) return 0;
    if(b>=i && e<=j){
        return tree[pos].end() - upper_bound(tree[pos].begin(),tree[pos].end(),k);
    }
    int m = (b+e)/2, l = pos*2;
    return (query(l,b,m,i,j,k) + query(l+1,m+1,e,i,j,k));
}
int main()
{
    int n,a,b,c,q;
    scanf("%d", &n);
    for(int i=1; i<=n; i++) scanf("%d", &arr[i]);
    build(1,1,n);
    scanf("%d", &q);
    int ans = 0;
    while(q--){
        scanf("%d%d%d", &a, &b, &c);
        a^=ans;
        b^=ans;
        c^=ans;
        if(a<1) a = 1;
        if(b>n) b = n;
        if(a>b){
            ans = 0;
        }
        else{
            ans = query(1,1,n,a,b,c);
        }
        printf("%d\n",ans);
    }
    return 0;
}