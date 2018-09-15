#include<bits/stdc++.h>
using namespace std;
#define ll long long
vector<int> v;
ll dp[12][55][55][2];
ll fun(int pos, int even, int odd, int isSmall)
{
 
    if(pos==v.size()){
        //cout<<((even-odd)==1)<<"-----"<<even<<" "<<odd<<endl;
        return ((even-odd)==1);
    }
    ll& ret = dp[pos][even][odd][isSmall];
    if(ret!=-1) return ret;
    ret=0;
    if(isSmall){
        int ev=0,od=0;
        for(int i=0; i<=9; i++){
            if(pos%2==0) ev = i;
            else od = i;
            ret+=fun(pos+1, even+ev, odd+od, 1);
        }
    }
    else{
        int ev=0,od=0;
        for(int i=0; i<v[pos]; i++){
            if(pos%2==0) ev = i;
            else od = i;
            ret+=fun(pos+1, even+ev, odd+od, 1);
        }
        if(pos%2==0)
            ret+=fun(pos+1, even+v[pos], odd, 0);
        else ret+=fun(pos+1, even, odd+v[pos], 0);
    }
    //cout<<"ret "<<ret<<endl;
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
    memset(dp, -1, sizeof dp);
    return fun(0,0,0,0);
}
int main()
{
    ll a,b;
    int tc;
    scanf("%d",&tc);
    while(tc--){
        scanf("%lld%lld",&a,&b);
        printf("%lld\n",solve(b) - solve(a-1));
    }
    return 0;
}