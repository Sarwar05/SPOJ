#include<bits/stdc++.h>
using  namespace std;
char grid[52][52];
int dp[52][52];
int n,m;
int dirx[]={+0,+0,+1,-1,-1,+1,-1,+1};
int diry[]={-1,+1,+0,+0,+1,+1,-1,-1};
int fun(int x,int y)
{
    if(dp[x][y]!=-1) return dp[x][y];
    int ret = 0,tem;
    for(int i=0; i<8; i++){
        int xx = x + dirx[i];
        int yy = diry[i] + y;
        if((xx>=0&&xx<n && yy>=0&&yy<m) && grid[xx][yy] == (grid[x][y]+1)){
            tem = 1 + fun(xx,yy);
        }
        else{
            tem = 1 ;
        }
        ret = max(ret,tem);
    }
    return dp[x][y] = ret;
}
int main()
{
    int cs=1;
    while(scanf("%d%d",&n,&m)!=EOF){
        if(n==0 && m==0) break;
        for(int i=0; i<n; i++){
            scanf("%s",grid[i]);
        }
        memset(dp,-1,sizeof dp);
        int ans = 0;
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++)
                if(grid[i][j]=='A')ans = max(ans,fun(i,j));
        }
        printf("Case %d: %d\n",cs++,ans);
    }
    return 0;
}