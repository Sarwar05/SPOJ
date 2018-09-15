#include<bits/stdc++.h>
using namespace std;
#define mx 10005
#define mod 1000000007
#define ll long long
char str[mx];
long long tree[50];
void update(int pos, int b, int e, int i, int j,int val)
{
    if(b>e || b>j || e<i) return;
    if(b>=i && e<=j){
        tree[pos] = (tree[pos]+val)%mod;
        return;
    }
    int m = (b+e)/2;
    int l = pos*2;
    int r = l+1;
    update(l,b,m,i,j,val);
    update(r,m+1,e,i,j,val);
    tree[pos] = (tree[l] + tree[r])%mod;
}
long long query(int pos, int b, int e, int i, int j)
{
    if(b>e || b>j || e<i) return 0;
    if(b>=i && e<=j) return tree[pos];
    int m = (b+e)/2;
    int l = pos*2;
    int r = l+1;
    long long r1 = query(l,b,m,i,j);
    long long r2 = query(r,m+1,e,i,j);
    return (r1+r2)%mod;
}
int main()
{
    int tc,cs=1,a;
    scanf("%d",&tc);
    while(tc--){
        memset(tree,0,sizeof tree);
        scanf("%s",str);
        int len = strlen(str);
        ll ans = 0,add;
        for(int i=0; i<len; i++){
            a = str[i]-'0';
            add = query(1,1,10,1,a-1) + 1;
            ans = (ans + add)%mod;
            update(1,1,10,a,a,add);
        }
        printf("Case %d: %lld\n",cs++,ans);
    }
    return 0;
}