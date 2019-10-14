#include<bits/stdc++.h>
using namespace std;
int fee[102], fun[102];
int dp[102][502];
int solve(int pos, int rem)
{
    if(pos<=0 || rem==0) return 0;
    int& ret = dp[pos][rem];
    if(ret!=-1) return ret;
    ret = solve(pos-1,rem);
    if(rem>=fee[pos])
        ret = max(ret,fun[pos] + solve(pos-1, rem-fee[pos]));
    return ret;
}
int main()
{
    int s,n;
    while(1){
        scanf("%d%d",&s,&n);
        if(s==0 && n==0) break;
        for(int i=1; i<=n; i++)
            scanf("%d%d",&fee[i], &fun[i]);
        memset(dp, -1, sizeof dp);
        int lim = solve(n,s);
        int lo = 0, hi = s, mid,ans=s;
        while(lo<=hi){
            mid = (lo+hi)/2;
            memset(dp, -1, sizeof dp);
            if(solve(n,mid) == lim){
                ans= min(ans, mid);
                hi = mid-1;
            }
            else lo = mid+1;
        }
        printf("%d %d\n",ans, lim);
    }
}
