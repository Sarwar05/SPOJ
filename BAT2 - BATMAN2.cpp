#include<bits/stdc++.h>
using namespace std;
#define mx 102
int arr[mx], n;
int dp[mx][mx][mx];
int fun(int pos, int prevlis, int prevlds)
{
    if(pos>n) return 0 ;
    int& ret = dp[pos][prevlis][prevlds];
    if(ret!=-1) return ret;
    ret = 500;
    if(arr[pos] > prevlis) ret = min(ret, fun(pos+1, arr[pos], prevlds));
    if(arr[pos] < prevlds) ret = min(ret, fun(pos+1, prevlis, arr[pos]));
    ret = min(ret, 1 + fun(pos+1, prevlis, prevlds));
    return ret;
}
int main()
{
    int tc;
    scanf("%d",&tc);
    while(tc--){
        scanf("%d",&n);
        memset(dp, -1, sizeof dp);
        for(int i=1; i<=n; i++)
            scanf("%d",&arr[i]);
        printf("%d\n",n - fun(1,0,201));
    }
}
