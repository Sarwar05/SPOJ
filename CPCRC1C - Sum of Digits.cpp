#include<bits/stdc++.h>
using namespace std;
#define ll long long
vector<int> v;
ll dp[12][85][2];
ll fun(int pos=0, int isSmall=0,int sum=0)
{
    if(pos==v.size()) return sum;
    ll& ret = dp[pos][sum][isSmall];
    if(ret!=-1) return ret;
    ret = 0;
    if(isSmall){
        for(int i=0; i<=9; i++){
            ret+=fun(pos+1, 1,sum+i);
        }
    }
    else{
        for(int i=0; i<=v[pos]-1; i++){
            ret+= fun(pos+1,1,i+sum);
        }
        ret+= fun(pos+1, 0,sum+v[pos]);
    }
    return ret;
}
ll solve(ll x)
{
    if(x<=0) return 0;
    v.clear();
    for(int i=0; i<=10; i++){
        v.push_back(x%10);
        x/=10;
    }
    reverse(v.begin(), v.end());
    memset(dp, -1, sizeof dp);
    return fun(0,0);
}
int main()
{
    ll a,b;
    while(scanf("%lld%lld",&a,&b))
    {
        if(a==-1 && b==-1) return 0;
        if(a>b) swap(a,b);
        printf("%lld\n",solve(b)-solve(a-1));
    }
}