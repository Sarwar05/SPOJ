#include<bits/stdc++.h>
using namespace std;
#define mx 6105
char str[mx];
int dp[mx][mx];
int len;
int fun(int i=0, int j=len-1)
{
    if(i==len || j==-1) return 0;
    if(dp[i][j]!=-1) return dp[i][j];
    int ret1=0,ret2=0;
    if(str[i]==str[j]) ret1 =1 + fun(i+1,j-1);
    else{
        ret1 = fun(i+1,j);
        ret2 = fun(i,j-1);
    }
    return dp[i][j] = max(ret1,ret2);
}
int main()
{
    int tc;
    scanf("%d",&tc);
    while(tc--){
        memset(dp,-1,sizeof dp);
        scanf("%s",str);
        len = strlen(str);
        printf("%d\n",len-fun());
    }
    return 0;
}