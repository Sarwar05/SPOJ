#include<bits/stdc++.h>
using namespace std;
int grid[105][105];
int dp[105][105];
int r,c;
int fun(int x, int y)
{
    if(x==r) return grid[x][y];
    if(dp[x][y]!=-1) return dp[x][y];
    int xx = x+1, yy = y;
    int ret1=0,ret2=0,ret3=0;
    ret1 = grid[x][y] + fun(xx,yy);
    xx = x+1, yy = y+1;
    if(yy<=c)ret2 = grid[x][y] + fun(xx,yy);
    xx = x+1, yy = y-1;
    if(yy>=1)ret3 = grid[x][y] + fun(xx,yy);
    return dp[x][y] = max(ret1,max(ret2,ret3));
}
int main()
{
    int tc;
    scanf("%d",&tc);
    while(tc--){
        scanf("%d%d",&r,&c);
        for(int i=1; i<=r; i++){
            for(int j=1; j<=c; j++){
                scanf("%d",&grid[i][j]);
            }
        }
        memset(dp,-1,sizeof dp);
        int ans = 0;
        for(int i=1; i<=c; i++){
            ans = max(ans,fun(1,i));
        }
        printf("%d\n",ans);
    }
    return 0;
}