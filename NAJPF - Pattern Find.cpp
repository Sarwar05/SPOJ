#include<bits/stdc++.h>
using namespace std;
const int mx = 1e6+6;
char text[mx], pattern[mx];
#define ll long long
const ll prime = 31;
const ll mod = 1e9+7;
ll Pow[mx], Hash[mx];
int main()
{
    Pow[0] = 1;
    for(int i=1; i<mx; i++)
        Pow[i] = (Pow[i-1]*prime)%mod;
    int tc;
    scanf("%d",&tc);
    while(tc--){
        scanf("%s%s",text, pattern);
        int len1 = strlen(text);
        int len2 = strlen(pattern);
        ll val = 0;
        for(int i=0; i<len1; i++){
            val = (val + text[i]*Pow[i])%mod;
            Hash[i] = val;
        }
        val = 0;
        for(int i=0; i<len2; i++)
            val = (val + pattern[i]*Pow[i])%mod;

        vector<int> ans;
        for(int i = 0, j = len2-1; j<len1; i++, j++){
            ll now = Hash[j];
            if(i) now-=Hash[i-1];
            if(now<0) now+=mod;
            if((val*Pow[i])%mod == now)
                ans.push_back(i+1);
        }
        int sz = ans.size();
        if(sz==0)printf("Not Found\n");
        else{
            printf("%d\n", sz);
            for(int i=0; i<sz; i++){
                printf("%d",ans[i]);
                if(i==sz-1) printf("\n");
                else printf(" ");
            }
        }
        if(tc) printf("\n");
    }
}
