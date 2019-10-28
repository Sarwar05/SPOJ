#include<bits/stdc++.h>
using namespace std;
#define mx 5000006
#define ll long long
const ll prime = 31;
const ll mod = 1e9+7;
char str[mx];
int len;
ll val[mx], inv[mx];
ll inverse(ll b, ll p)
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
void calculate()
{
    ll power = 1;
    ll Hash = 0;
    for(int i=0; i<len; i++){
        Hash = (Hash + str[i]*power )%mod;
        val[i] = Hash;
        inv[i]= inverse(power, mod-2);
        power = (power*prime)%mod;
    }
}
ll subHash(int i, int j)
{
    ll ret = val[j];
    if(i) ret-=val[i-1];
    if(ret<0) ret+=mod;
    ret = (ret*inv[i])%mod;
    return ret;
}
int solve(int p)
{
    if(p<=22){
        int ret = 0;
        for(int i=0, j=p; i<p && j<len; i++, j++){
            if(str[i]==str[j]) ret++;
            else break;
        }
        return ret;
    }
    int lim = min(p, len-p);
    int lo = 0, hi = lim, mid, ans = 0;
    while(lo<=hi){
        int mid = (lo+hi)/2;
        ll h1 = subHash(0,mid-1);
        ll h2 = subHash(p, p+mid-1);
        if(h1==h2){
            ans = max(ans, mid);
            lo = mid+1;
        }
        else{
            hi = mid-1;
        }
    }
    return ans;
}
int main()
{
    scanf("%s",str);
    len = strlen(str);
    calculate();
    int q,p;
    scanf("%d",&q);
    while(q--){
        scanf("%d",&p);
        printf("%d\n", solve(p));
    }
}
