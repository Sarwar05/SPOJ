#include<bits/stdc++.h>
using namespace std;
#define ll long long
vector<int> v;
int dp[12][12][2][2];
ll fun(int cnt, int pos, int small, int start)
{
    if(pos==12) return (start ? cnt : 0);
    if(dp[cnt][pos][small][start]!=-1) return dp[cnt][pos][small][start];
    ll ret = 0;
    if(small){
        if(start)
            ret  = fun(cnt+1, pos+1, small, start);
        else ret  =  fun(cnt, pos+1, small, start);
        for(int i=1; i<=9; i++){
            ret  += fun(cnt, pos+1, small, 1);
        }
    }
    else{
        if(start)
            ret  = fun(cnt+1,pos+1, small|| (v[pos]>0), start);
        else ret  = fun(cnt, pos+1, small|| (v[pos]>0), start);
        for(int i=1; i<=v[pos]; i++){
            ret  += fun(cnt, pos+1, small||(v[pos]!=i), 1);
        }
    }
    return dp[cnt][pos][small][start] = ret;
}
void gen(int x)
{
    v.clear();
    for(int i=0; i<=11; i++){
        v.push_back(x%10);
        x/=10;
    }
    reverse(v.begin(), v.end());
}
int main()
{
    int tc,a,b;
    scanf("%d",&tc);
    while(tc--){
        scanf("%d%d",&a,&b);
        if(a>b) swap(a,b);
        gen(b);
        memset(dp, -1, sizeof dp);
        ll resb = fun(0,0,0,0);
        gen(a-1);
        memset(dp, -1, sizeof dp);
        ll resa = fun(0,0,0,0);
        printf("%lld\n", resb - resa);
    }
}
