#include<bits/stdc++.h>
using namespace std;
#define mx 100005
#define ll long long
char str[mx];
const ll prime1 = 31;
const ll mod1 = 1e9+7;
const ll prime2 = 37;
const ll mod2 = 1e9+9;
ll inverse(ll b, ll p, ll mod)
{
    ll ret = 1;
    while(p){
        if(p%2)
            ret = (ret*b)%mod;
        b = (b*b)%mod;
        p/=2;
    }
    return ret;
}
int main()
{
    int n,k,tc;
    scanf("%d",&tc);
    while(tc--){
        scanf("%d%d",&n,&k);
        scanf("%s", str);
        ll val1 = 0;
        ll po1 = 1;
        ll val2 = 0;
        ll po2 = 1;
        for(int i=0; i<k; i++){
            val1 = (val1 + str[i]*po1)%mod1;
            po1 = (po1*prime1)%mod1;
            val2 = (val2 + str[i]*po2)%mod2;
            po2 = (po2*prime2)%mod2;
        }
        set<pair<ll,ll> > st;
        st.insert(make_pair(val1, val2));
        ll inv1 = inverse(prime1, mod1-2,  mod1);
        ll inv2 = inverse(prime2, mod2-2, mod2);
        for(int i=0, j = k; j<n; i++, j++){
            val1-=str[i];
            if(val1<0) val1+=mod1;
            val1 = (val1 + str[j]*po1)%mod1;
            val1= (val1*inv1)%mod1;
            val2-=str[i];
            if(val2<0) val2+=mod2;
            val2 = (val2 + str[j]*po2)%mod2;
            val2= (val2*inv2)%mod2;
            st.insert(make_pair(val1, val2));
        }
        printf("%d\n", (int)st.size());
    }
}
