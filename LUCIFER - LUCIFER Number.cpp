#include<bits/stdc++.h>
using namespace std;
#define ll long long
#include<bits/stdc++.h>
using namespace std;
#define ll long long
vector<int> v;
int prime[110] = {0};
void sieve()
{
    prime[0] = prime[1] = 1;
    for(int i=2; i<110; i++){
        if(prime[i]==0){
            for(int j=i*i; j<110; j+=i){
                prime[j] = 1;
            }
        }
    }
}
ll dp[12][50][50][2];
ll fun(int pos, int even, int odd, int isSmall)
{
    if(pos==v.size()){
        int x = even-odd;
        if(x<0) return 0;
        return(prime[x]==0);
    }
    ll& ret = dp[pos][even][odd][isSmall];
    if(ret!=-1) return ret;
    ret = 0;
    if(isSmall){
        int ev = 0,od = 0;
        for(int i=0; i<=9; i++){
            if(pos%2==0)
                ev = i;
            else od = i;
            ret+=fun(pos+1,even+ev, odd+od,1);
        }
    }
    else{
        int ev=0,od=0;
        for(int i=0; i<v[pos]; i++){
            if(pos%2==0)
                ev = i;
            else od = i;
            ret+=fun(pos+1,even+ev, odd+od,1);
        }
        if(pos%2==0)ret+=fun(pos+1,even+v[pos], odd,0);
        else ret+=fun(pos+1,even, odd+v[pos],0);
    }
    return ret;
}
ll solve(ll n)
{
    if(n<=0) return 0;
    v.clear();
    for(int i=1; i<=10; i++){
        v.push_back(n%10);
        n/=10;
    }
    reverse(v.begin(), v.end());
//    for(int i=0; i<v.size(); i++){
//        cout<<v[i]<<" ";
//    }
//    cout<<endl;
    memset(dp, -1, sizeof dp);
    return fun(0,0,0,0);
}
int main()
{
    sieve();
    ll a,b;
    int tc;
    scanf("%d",&tc);
    while(tc--){
        scanf("%lld%lld",&a,&b);
        if(a>b) swap(a,b);
        printf("%lld\n",solve(b) - solve(a-1));
    }
    return 0;
}
 