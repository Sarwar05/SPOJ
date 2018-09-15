#include<bits/stdc++.h>
using namespace std;
#define mx 3165
int main()
{
    vector<int> prime;
    bitset<mx+2>bs;
    for(int i=2; i<=mx; i++){
        if(bs[i]);
        else{
            prime.push_back(i);
            for(int j = i*i; j<=mx; j+=i)
                bs.set(j);
        }
    }
    int tc,a;
    scanf("%d",&tc);
    while(tc--){
        scanf("%d",&a);
        int even=0,odd=0;
        int id = 0;
        int pf = prime[id];
        while(pf*pf<=a && id<prime.size()){
            if(a%pf==0){
                int po = 0;
                while(a%pf==0){
                    po++;
                    a/=pf;
                }
                if(po%2==0) even++;
                else odd++;
            }
            pf = prime[++id];
        }
        if(a>1) odd++;
        if(even>odd) printf("Psycho Number\n");
        else printf("Ordinary Number\n");
    }
} 