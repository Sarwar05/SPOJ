#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define mx 47000
int main()
{
    bitset<mx>bs;
    vector<int> prime;
    for(ll i=2; i<mx; i++){
        if(bs[i]);
        else{
            prime.push_back(i);
            if(i>46341) break;
            for(ll j = i*i; j<mx; j+=i)
                bs.set(j);
        }
    }
    int t,a,b;
    scanf("%d",&t);
    while(t--){
        scanf("%d%d",&a,&b);
        if(a==1) a++;
        vector<int> arr(b-a+1, 0);
        int sq = sqrt(b);
        for(int i=0; prime[i]<=sq; i++){
            ll pr = prime[i]*2;
            if(pr<a){
                ll x = a/prime[i];
                if(a%prime[i]!=0)x++;
                    pr=x*prime[i];
            }
            for( ; pr<=b; pr+=prime[i]){
                arr[pr-a] = 1;
            }
        }
        for(int i=0; i<arr.size(); i++)
            if(arr[i]==0)
                printf("%d\n",a+i);
    }
}