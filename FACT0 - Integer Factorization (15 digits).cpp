#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define mx 31622780
    bitset<mx>bs;
int main()
{
    vector<int> prime;
    for(ll i=2; i<mx; i++){
        if(bs[i]);
        else{
            prime.push_back(i);
            for(ll j = i*i; j<mx; j+=i)
                bs.set(j);
        }
    }
    ll num;
    while(scanf("%lld",&num), num){
        int id = 0;
        ll pf = prime[id];
        int pr = 0;
        while(pf*pf<=num){
            if(num%pf==0){
                int po = 0;
                while(num%pf==0){
                    num/=pf;
                    po++;
                }
                if(pr) printf(" ");
                printf("%d^%d",prime[id], po);
                pr = 1;
            }
            ++id;
            if(id==prime.size())break;
            pf = prime[id];
        }
        if(num>1){
            if(pr) printf(" ");
            printf("%lld^1",num);
        }
        printf("\n");
    }
}