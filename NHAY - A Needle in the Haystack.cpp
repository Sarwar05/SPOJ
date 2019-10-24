
#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int pr = 31;
const int mod = 1e9+7;
vector<ll> powers;
vector<ll> val;
ll compute(string& str)
{
    ll hashVal = 0;
    ll pPow = 1;
    for(char ch:str){
        hashVal = ( hashVal + (ch-'a'+1)*pPow )%mod;
        powers.push_back(pPow);
        val.push_back(hashVal);
        pPow = (pPow*pr)%mod;
    }
    return hashVal;
}
ll inverse(ll b, ll p)
{
    if(p==0) return 1;
    ll x = inverse(b,p/2);
    x = (x*x)%mod;
    if(p%2) x = (x*b)%mod;
    return x;
}
int main()
{
    ios_base::sync_with_stdio(0);
    int n, cs = 0;
    while(cin>>n){
        if(cs!=0) printf("\n");cs++;
        string a,b;
        cin>>a>>b;
        ll target = compute(a);
        val.clear();
        powers.clear();
        compute(b);
        for(int i=0, j = a.size()-1; j<b.size(); i++, j++){
            ll Hash = val[j];
            if(i) Hash-=val[i-1];
            if(Hash<0) Hash+=mod;
            Hash = (Hash*inverse(powers[i], mod-2))%mod;
            if(Hash==target) cout<<i<<endl;
        }
    }
}
