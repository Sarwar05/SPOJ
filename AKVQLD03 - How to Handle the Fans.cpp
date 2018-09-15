#include<bits/stdc++.h>
using namespace std;
#define mx 1000006
#define ll long long
ll tree[mx*4] = {0};
void update(int pos, int b, int e, int i, int j,int val)
{
    if(b>e || b>j || e<i) return;
    if(b>=i && e<=j){
        tree[pos]+=val;
        return;
    }
    int m = (b+e)/2;
    int l = pos*2;
    int r = l+1;
    update(l,b,m,i,j,val);
    update(r,m+1,e,i,j,val);
    tree[pos] = tree[l] + tree[r];
}
ll query(int pos, int b, int e, int i, int j)
{
    if(b>e || b>j || e<i) return 0;
    if(b>=i && e<=j){
        return tree[pos];
    }
    int m = (b+e)/2;
    int l = pos*2;
    int r = l+1;
    return (query(l,b,m,i,j) + query(r,m+1,e,i,j));
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n,q;
    string s;
    int a,b;
    cin>>n>>q;
    for(int i=1; i<=q; i++){
        cin>>s>>a>>b;
        if(s=="find"){
            cout<<query(1,1,n,a,b)<<endl;
        }
        else
            update(1,1,n,a,a,b);
    }
 
    return 0;
}