#include<bits/stdc++.h>
using namespace std;
#define ll long long
map<ll, ll> mp;
ll fun(ll x)
{
    if(x==0) return 0;
    if(mp.find(x)!=mp.end()) return mp[x];
    ll ret = max(x,fun(x/2)+fun(x/3)+fun(x/4));
    return mp[x] = ret;
}
int main()
{
    ll num;
    while(scanf("%lld",&num)!=EOF){
        mp.clear();
        printf("%lld\n",fun(num));
    }
    return 0;
}