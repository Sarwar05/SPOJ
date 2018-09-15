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
    int a;
    while(scanf("%d",&a)!=EOF){
        vector<int> ans;
        int id = 0;
        int pf = prime[id];
        while(pf*pf<=a && id<prime.size()){
            while(a%pf==0){
                ans.push_back(pf);
                a/=pf;
            }
            pf = prime[++id];
        }
        if(a>1) ans.push_back(a);
        printf("1");
        for(int i=0; i<ans.size(); i++) printf(" x %d",ans[i]);
        printf("\n");
    }
} 