#include<bits/stdc++.h>
using namespace std;
#define mx 100005
#define ll long long
int tree[mx*4];
int arr[mx];
void update(int pos, int b, int e, int i, int j, int val)
{
    if(b>e||b>j||e<i) return;
    if(b>=i && e<=j){
        tree[pos] = min(val, tree[pos]);
        return;
    }
    int m = (b+e)/2;
    int l = pos*2;
    int r = l+1;
    update(l,b,m,i,j,val);
    update(r,m+1,e,i,j,val);
    tree[pos] = min(tree[l], tree[r]);
}
int query(int pos, int b, int e, int i, int j)
{
    if(b>e||b>j||e<i) return 10000000;
    if(b>=i && e<=j)
        return tree[pos];
    int m = (b+e)/2;
    int l = pos*2;
    int r = l+1;
    return min(query(l,b,m,i,j),query(r,m+1,e,i,j));
}
int main()
{
    int tc,n;
    scanf("%d",&tc);
    while(tc--){
        scanf("%d",&n);
        set<int> st;
        for(int i=1; i<=n; i++){
            scanf("%d",&arr[i]);
            st.insert(arr[i]);
        }
        int val = 0;
        unordered_map<int, int> mp;
        for(auto x:st)
            mp[x] = ++val;
        ll ans = 0;
        for(int i=1; i<=(val*4); i++)
            tree[i] = 10000000;
        for(int i=1; i<=n; i++){
            int now = mp[ arr[i] ];
            int id = query(1,1,val,now, val);
            update(1,1,val,now,now,i);
            if(id<1 || id>n) continue;
            ans = max(ans, 1LL*(i-id)*arr[i]);
        }
        for(int i=1; i<=(val*4); i++)
            tree[i] = 10000000;
        for(int i=n; i>=1; i--){
            int now = mp[ arr[i] ];
            int id = -query(1,1,val,now, val);
            update(1,1,val,now,now,-i);
            if(id<1 || id>n) continue;
            ans = max(ans, 1LL*(id-i)*arr[i]);
        }
        printf("%lld\n",ans);
    }
}