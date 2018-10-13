#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define mx 2000002
ll nCr(int n, int k)
{
    ll ans=1;
    k=min(n-k,k);
    for(int j = 1; j<=k; j++,n--)
    {
        if(n%j==0){
            ans*=n/j;
        }
        else if(ans%j==0){
            ans=ans/j*n;
        }
        else{
            ans=(ans*n)/j;
        }
    }
    return ans;
}
int main()
{
    int tc,cs=1,n,k;
    scanf("%d",&tc);
    while(tc--){
        scanf("%d%d",&n,&k);
        n-=k;
        printf("%lld\n",nCr(n+k-1,n));
    }
}
