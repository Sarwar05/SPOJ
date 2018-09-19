#include<bits/stdc++.h>
using namespace std;
#define mx 100005
int tree[mx*4];
void update(int pos, int b, int e, int i, int j)
{
    if(b>e|| b>j||e<i) return;
    if(b>=i && e<=j){
        tree[pos]++;
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
    if(b>e|| b>j||e<i) return 0;
    if(b>=i && e<=j)
        return tree[pos];
    int m = (b+e)/2;
    int l = pos*2;
    int r = l+1;
    return query(l,b,m,i,j)+query(r,m+1,e,i,j);
}
int main()
{
    int tc,n,x,y,k;
    scanf("%d",&tc);
    while(tc--){
        scanf("%d%d",&n,&k);
        vector<pair<int, int> >v;
        map<int, int> mp;
        set<int> st;
        for(int i=1; i<=n; i++){
            scanf("%d%d",&x,&y);
            v.push_back({x,y});
            st.insert(y);
        }
        sort(v.begin(), v.end());
        int val = 0;
        for(auto a:st)
            mp[a] = ++val;
        memset(tree, 0, sizeof tree);
        int ans = 0;
        for(int i=0; i<v.size(); i++){
            int now = mp[v[i].second];
            int dom = query(1,1,val,1,now-1);
            int ndom = n-1-dom;
            if(abs(dom-ndom)>=k) ans++;
            update(1,1,val,now,now);
        }
        printf("%d\n",ans);
    }
}