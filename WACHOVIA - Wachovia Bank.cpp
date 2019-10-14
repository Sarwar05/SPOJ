#include<bits/stdc++.h>
using namespace std;
#define mx 2002
#define ll long long
int sze[52], val[52];
int dp[52][1002];
int solve(int pos, int rem)
{
    if(pos<=0 || rem==0) return 0;
    int& ret = dp[pos][rem];
    if(ret!=-1) return ret;
    ret = solve(pos-1,rem);
    if(rem>=sze[pos])
        ret = max(ret,val[pos] + solve(pos-1, rem-sze[pos]));
    return ret;
}
int main()
{
    int tc;
    scanf("%d",&tc);
    while(tc--){
        int k,m;
        scanf("%d%d",&k,&m);
        for(int i=1; i<=m; i++) scanf("%d%d",&sze[i], &val[i]);
        memset(dp, -1, sizeof dp);
        printf("Hey stupid robber, you can get %d.\n", solve(m,k));
    }
}
