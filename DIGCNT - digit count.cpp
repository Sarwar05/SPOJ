#include<bits/stdc++.h>
using namespace std;
long long dp[18][2][2][2][18];
int v1[18], v2[18];
int val;
long long fun(int pos, int small, int big, int strt, int ans)
{
    if(pos==17) return ans;
    long long &ret = dp[pos][small][big][strt][ans];
    if(ret!=-1) return ret;
    ret = 0;
    int lo = 0, hi = 9;
    if(small==0) hi = v1[pos];
    if(big==0) lo = v2[pos];
    for(int i=lo; i<=hi; i++){
        ret+=(fun(pos+1, small||(i<hi), big||(i>lo),strt||(i>0),ans+(val==i && (strt||i>0))));
    }
    return ret;
}
inline void solve(long long a, long long b)
{
    for(int i=16; i>=0; i--){
        v1[i] = a%10;
        a/=10;
    }
    a = b;
    for(int i=16; i>=0; i--){
        v2[i] = a%10;
        a/=10;
    }
    for(val=0; val<=9; val++){
        memset(dp, -1, sizeof dp);
        printf("%lld",fun(0,0,0,0,0));
        if(val==9) printf("\n");
        else printf(" ");
    }
}
int main()
{
    long long a,b;
    while(scanf("%lld%lld",&a,&b)){
        if(a==b && a==0) break;
        if(a>b) swap(a,b);
        solve(b,a);
    }
}
