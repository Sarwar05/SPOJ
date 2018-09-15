#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define mx 1000002
int main()
{
    vector<int> prime;
    bitset<mx>bs;
    prime.push_back(2);
    for(int i=2*2; i<mx; i+=2) bs.set(i);
    for(ll i=3; i<mx; i++){
        if(bs[i]);
        else{
            prime.push_back(i);
            for(ll j = i*i; j<mx; j+=i){
                bs.set(j);
            }
        }
    }
    bs.reset();
    int lim = sqrt(mx);
    for(int i=0; prime[i]<=lim; i++){
        ll x = prime[i], y;
        for(int j=i+1; j<prime.size(); j++){
            y = prime[j];
            if((x*y)<mx)
                bs.set(x*y);
            else break;
        }
    }
    int cnt =0;
    for(int i=1; i<=1000000; i++){
        unsigned int num = i;
        int id = 0;
        int res = 1;
        ll pf = prime[id];
        while((pf*pf)<=num && id<prime.size()){
            if(num%pf==0){
                int po = 0;
                while(num%pf==0){
                    po++;
                    num/=pf;
                }
                res*=(po + 1);
            }
            pf = prime[++id];
        }
        if(num>1) res*=2;
        if(bs[res]){
            cnt++;
            if(cnt%9==0)
                printf("%d\n",i);
        }
    }
}