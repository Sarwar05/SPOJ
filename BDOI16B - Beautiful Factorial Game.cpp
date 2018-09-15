#include<bits/stdc++.h>
using namespace std;
#define ll long long
int main()
{
    ll n,k,tc,cs=1;
    cin>>tc;
    while(tc--){
        cin>>n>>k;
        ll ans = 1LL<<62;
        ll sq = sqrt(k);
        for(ll a=2; (a*a)<=k; a++){
            if(k%a == 0){
                ll b = 0;
                while(k%a==0){
                    b++;
                    k/=a;
                }
                ll sum=0, po = a;
                while(1){
                    ll add = n/po;
                    if(add==0) break;
                    sum+=add;
                    po*=a;
                }
                ans = min(ans,sum/b);
            }
        }
        if(k>1){
            ll sum=0, po = k;
            while(1){
                ll add = n/po;
                if(add==0) break;
                sum+=add;
                po*=k;
            }
            ans = min(ans,sum);
        }
        cout<<"Case "<<cs++<<": ";
        cout<<ans<<endl;
    }
    return 0;
}
 