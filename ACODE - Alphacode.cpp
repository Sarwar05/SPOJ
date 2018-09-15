#include<bits/stdc++.h>
using namespace std;
#define ll long long
char  str[5005];
ll dp[5005];
int len;
ll fun(int x)
{
    if(str[x]=='0') return 0;
    if(x==len) return 1;
    if(x>len) return 0;
    if(dp[x]!=-1) return dp[x];
    ll ret1 = fun(x+1);
    ll ret2=0;
    if(str[x]=='1') ret2 = fun(x+2);
    else if(str[x]=='2' && (x+1)<len && str[x+1]<='6') ret2 = fun(x+2);
 
    return dp[x] = ret1+ret2;
}
int main()
{
    while(scanf("%s",str)){
        if(str[0]=='0') break;
        len = strlen(str);
        memset(dp,-1,sizeof dp);
        printf("%lld\n",fun(0));
    }
    return 0;
}