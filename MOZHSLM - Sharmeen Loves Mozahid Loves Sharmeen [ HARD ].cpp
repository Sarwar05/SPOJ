#include<bits/stdc++.h>
using namespace std;
char str[100005];
int fsum[100005], bsum[100005];
#define ll long long
int main()
{
    int tc;
    scanf("%d",&tc);
    while(tc--){
        scanf("%s",str+1);
        str[0] = '*';
        int len = strlen(str);
        fsum[0] = 0;
        for(int i=1; i<=len; i++){
            fsum[i] = fsum[i-1];
            if(str[i]=='s')fsum[i]++;
        }
        bsum[len+1] = 0;
        for(int i=len; i>=1; i--){
            bsum[i] = bsum[i+1];
            if(str[i]=='s') bsum[i]++;
        }
        ll ans = 0;
        for(int i=1; i<=len; i++){
            if(str[i]=='m'){
                ll a = fsum[i-1];
                ll b = bsum[i+1];
                ans+=(a*b);
            }
        }
        printf("%lld\n",ans);
    }
    return 0;
}