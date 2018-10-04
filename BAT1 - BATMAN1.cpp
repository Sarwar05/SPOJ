#include<bits/stdc++.h>
using namespace std;
int open[22], cost[22][22], rating[22][22],n,m,dp[22][22][1002];
int fun(int pos, int item, int rem)
{
    if(pos>n) return 0;
    int& ret = dp[pos][item][rem];
    if(ret!=-1) return ret;
    ret = 0;
    if(item==0){
        if(open[pos]<=rem)
            ret = max(ret, fun(pos,1,rem-open[pos]));
    }
    else if(item>m) ret = max(ret, fun(pos+1,0,rem));
    else{
        if(cost[pos][item]<=rem)
            ret = max(ret,rating[pos][item] + fun(pos, item,rem-cost[pos][item]));
        ret = max(ret,fun(pos, item+1,rem));
    }
    ret = max(ret, fun(pos+1,0,rem));
    return ret;
}
int main()
{
    ios_base::sync_with_stdio(0);
    int tc,k;
    cin>>tc;
    for(int cs=1; cs<=tc; cs++){
        cin>>n>>m>>k;
        for(int i=1; i<=n; i++) cin>>open[i];
        for(int i=1; i<=n; i++) for(int j=1; j<=m; j++) cin>>cost[i][j];
        for(int i=1; i<=n; i++) for(int j=1; j<=m; j++) cin>>rating[i][j];
        memset(dp, -1, sizeof dp);
        cout<<fun(1,0,k)<<endl;
    }
}
