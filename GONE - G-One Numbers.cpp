#include<bits/stdc++.h>
using namespace std;
#define ll long long
vector<int> v;
int prime[110] = {0};
void sieve()
{
    prime[0] = prime[1] = 1;
    for(int i=2; i<110; i++){
        if(prime[i]==0){
            for(int j=i*i; j<110; j+=i){
                prime[j] = 1;
            }
        }
    }
}
ll dp[12][95][2];
ll fun(int pos, int sum, int isSmall)
{
    if(pos==v.size()){
        return(prime[sum]==0);
    }
    ll& ret = dp[pos][sum][isSmall];
    if(ret!=-1) return ret;
    ret = 0;
    if(isSmall){
        for(int i=0; i<=9; i++){
            ret+=fun(pos+1,sum+i,1);
        }
    }
    else{
        for(int i=0; i<v[pos]; i++){
            ret+=fun(pos+1,sum+i,1);
        }
        ret+=fun(pos+1,sum+v[pos],0);
    }
    return ret;
}
ll solve(ll n)
{
    if(n<=0) return 0;
    v.clear();
    for(int i=1; i<=10; i++){
        v.push_back(n%10);
        n/=10;
    }
    reverse(v.begin(), v.end());
    memset(dp, -1, sizeof dp);
    return fun(0,0,0);
}
int main()
{
    sieve();
    ll a,b;
    int tc;
    scanf("%d",&tc);
    while(tc--){
        scanf("%lld%lld",&a,&b);
        printf("%lld\n",solve(b) - solve(a-1));
    }
    return 0;
}