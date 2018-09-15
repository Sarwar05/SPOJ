#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define mx 500005
int tree[mx*4] = {0}, arr[mx];
void update(int pos, int b, int e, int i, int j, int val)
{
    if(b>e || b>j || e<i) return;
    if(b>=i && e<=j){
        tree[pos] += val;
        return;
    }
    int m = (b+e)/2;
    int l = pos*2;
    int r = l+1;
    update(l,b,m,i,j,val);
    update(r,m+1,e,i,j,val);
    tree[pos] = tree[l] + tree[r];
}
int query(int pos, int b, int e, int i, int j)
{
    if(b>e || b>j || e<i) return 0;
    if(b>=i && e<=j)
        return tree[pos];
    int m = (b+e)/2;
    int l = pos*2;
    int r = l+1;
    return query(l,b,m,i,j) + query(r,m+1,e,i,j);
}
int main()
{
    int n,p,a;
    scanf("%d%d",&n,&p);
    set<int> st;
    for(int i=1; i<=n; i++){
        scanf("%d",&arr[i]);
        st.insert(arr[i]);
    }
    int val = 0;
    unordered_map<int, int> mp;
    for(auto x:st)
        mp[x] = ++val;
    int start = 1;
    ll inversion = 0, inv;
    for(int i=1; i<=p; i++){
        int now = mp[ arr[i] ];
        int sum = query(1,1,val,now+1,val);
        inversion+=sum;
        update(1,1,val,now,now,1);
    }
    ll curr = inversion;
    //cout<<curr<<endl;
    for(int i = p+1; i<=n; i++){
        int now = mp[ arr[i] ];
        int out = mp[arr[i-p]];
        update(1,1,val,out,out,-1);
        out = query(1,1,val,1,out-1);
        curr-=out;
        //cout<<arr[i-p]<<" out: "<<out<<endl;
        curr+=query(1,1,val,now+1,val);
        update(1,1,val,now,now,1);
        if(curr>inversion){
            inversion = curr;
            start = i-p+1;
        }
        //cout<<"curr :"<< curr<<endl;
    }
    printf("%d %lld\n",start, inversion);
}