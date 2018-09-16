
#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define mx 10000002
bitset<mx> bs;
vector<int> primes;
int main()
{
    for(int i=4; i<mx; i+=2)
        bs[i] = 1;
    primes.push_back(2);
    for(ll i=3; i<mx; i+=2){
        if(!bs[i]){
            primes.push_back(i);
            for(ll j = i*i; j<mx; j+=i)
                bs[j] = 1;
        }
    }
    int tc,n,ans;
    scanf("%d",&tc);
    while(tc--){
        scanf("%d",&n);
        int total = upper_bound(primes.begin(), primes.end(), n) - primes.begin();
        n/=2;
        int lsq = upper_bound(primes.begin(), primes.end(), n) - primes.begin();
        int ans = total - lsq;
        printf("%d\n",ans);
    }
}
