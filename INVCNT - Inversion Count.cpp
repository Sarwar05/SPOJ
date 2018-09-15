#include<bits/stdc++.h>
using namespace std;
#define mx 200005
int tree[mx*4], arr[mx],arr2[mx];
void update(int pos, int b, int e, int i, int j)
{
    if(b>e || b>j || e<i) return;
    if(b>=i && e<=j){
        tree[pos] = tree[pos]+1;
        return;
    }
    int m = (b+e)/2;
    int l = pos*2;
    int r = l+1;
    update(l,b,m,i,j);
    update(r,m+1,e,i,j);
    tree[pos] = tree[l] + tree[r];
}
int query(int pos, int b, int e, int i, int j)
{
    if(b>e || b>j || e<i) return 0;
    if(b>=i && e<=j) return tree[pos];
    int m = (b+e)/2;
    int l = pos*2;
    int r = l+1;
    int r1 = query(l,b,m,i,j);
    int r2 = query(r,m+1,e,i,j);
    return (r1+r2);
}
int main()
{
    int tc,n,add,a;
    scanf("%d",&tc);
    while(tc--){
        memset(tree,0,sizeof tree);
        scanf("%d",&n);
        for(int i=1; i<=n; i++){
            scanf("%d",&arr[i]);
            arr2[i-1] = arr[i];
        }
        sort(arr2,arr2+n);
        int val = 0;
        map<int, int> mp;
        for(int i=0; i<n; i++){
            if(mp.find(arr2[i])==mp.end())
                mp[ arr2[i] ] = ++val;
        }
        long long ans =0;
        for(int i=n; i>0; i--){
            a = mp[ arr[i] ];
            add = query(1,1,val,1,a-1);
            ans = ans + add;
            update(1,1,val,a,a);
        }
        printf("%lld\n",ans);
    }
    return 0;
}