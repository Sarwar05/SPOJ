#include<bits/stdc++.h>
using namespace std;
#define mx 100000002
#define ll long long
bitset<mx>bs;
vector<int> prime;
int main()
{
    for(ll i=2; i<mx; i++){
        if(bs[i]);
        else{
            prime.push_back(i);
            for(ll j = i*i; j<mx; j+=i){
                bs.set((int)j);
            }
        }
    }
    int x;
    while(scanf("%d",&x),x){
        int pr = upper_bound(prime.begin(), prime.end(), x) - prime.begin();
        double d = pr;
        double dd = x;
        dd = dd/log(dd);
        double res = (d-dd)/d;
        printf("%.1f\n",abs(res*100.0));
    }
}