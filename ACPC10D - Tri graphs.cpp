#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define mx 100005
int cost[mx][5];
int dp[mx][5];
int diry[] = {1,1,0,-1};
int dirx[] = {0,1,1,1};
int fun(int x, int y, int n)
{
    if(x<1 || x>n || y<1 || y>3) return 1000000000;
    if(x==n && y==2) return cost[x][y];
    if(dp[x][y] != 1000000000) return dp[x][y];
    int ret = 1000000000;
    for(int i=0; i<4; i++){
        int xx = x + dirx[i];
        int yy = diry[i] + y;
        ret = min(ret, cost[x][y] + fun(xx,yy,n));
    }
    return dp[x][y] = ret;
}
int main()
{
    int n, cs=1;
    while(scanf("%d",&n),n){
 
        for(int i=1; i<=n; i++){
            scanf("%d%d%d", &cost[i][1], &cost[i][2], &cost[i][3]);
            dp[i][1] = dp[i][2] = dp[i][3] = 1000000000;
        }
        int ans = fun(1,2,n);
        printf("%d. %d\n",cs++,  ans);
    }
    return 0;
} 