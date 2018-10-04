#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll dp[102][102], arr[102];
ll sum(int a,int b)
{
    ll s = 0;
    for(int i=a; i<=b; i++)
        s+=arr[i];
    return s%100;
}
ll fun(int b, int e)
{
    if(b>=e) return 0;
    ll& ret = dp[b][e];
    if(ret!=-1) return ret;
    ret = (1LL<<60);
    for(int i=b; i<=e;i++)
        ret = min(ret, fun(b,i) + fun(i+1,e) + sum(b,i)*sum(i+1,e));
    return ret;
}
int main()
{
    int n;
    while(cin>>n){
        for(int i=1; i<=n; i++)
            cin>>arr[i];
        memset(dp, -1, sizeof dp);
        cout<<fun(1,n)<<endl;
    }

}
