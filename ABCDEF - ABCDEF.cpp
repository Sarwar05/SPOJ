#include<bits/stdc++.h>
using namespace std;
#define ll long long
int main()
{
    int n;
    scanf("%d",&n);
    vector<ll> arr(n);
    for(int i=0; i<n; i++) scanf("%lld",&arr[i]);
    unordered_map<ll, ll> mpl,mpr;
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            ll x = (arr[i] + arr[j]);
            for(int k=0; k<n; k++){
                if(arr[k]!=0){
                    ll tmp = x*arr[k];
                    mpr[tmp]++;
                }
            }
        }
    }
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            ll x = (arr[i] * arr[j]);
            for(int k=0; k<n; k++){
                ll tmp = x+arr[k];
                mpl[tmp]++;
            }
        }
    }
    ll ans = 0;
    auto it = mpl.begin();
    while(it!=mpl.end()){
        ll a = it->first;
        ll x = it->second;
        if(mpr.find(a)!=mpr.end()){
            ll y = mpr[a];
            ans= ans + x*y;
        }
        it++;
    }
    printf("%lld\n",ans);
    return 0;
} 