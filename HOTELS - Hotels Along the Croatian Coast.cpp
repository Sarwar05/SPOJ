#include<bits/stdc++.h>
using namespace std;
#define ll long long
int main()
{
    ll n,m,a;
    scanf("%lld%lld",&n,&m);
    vector<ll> v(n+1);
    v[0] = 0;
    for(int i=1; i<=n; i++){
        scanf("%lld",&a);
        v[i] = v[i-1] + a;
    }
    ll ans = 0;
    for(int i=1; i<=n; i++){
        ll need = m + v[i-1];
        int id = upper_bound(v.begin(), v.end(),  need) - v.begin() -1;
        ans = max(ans, v[id] - v[i-1] );
    }
    printf("%lld\n",ans);
}
