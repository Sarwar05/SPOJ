#include<bits/stdc++.h>
using namespace std;
#define ll long long
long long moduloMultiplication(ll a,ll b,ll mod)
{
    long long res = 0;
    a %= mod;
    while (b)
    {
        if (b & 1)
            res = (res + a) % mod;
        a = (2 * a) % mod;
        b/=2;
    }
 
    return res;
}
unsigned ll bigMod(unsigned ll b,unsigned  ll p,unsigned ll m)
{
	if(p==0) return 1%m;
	ll x = bigMod(b,p/2,m);
	x = moduloMultiplication(x,x,m);
	if(p%2) x = moduloMultiplication(x,b,m);
	return x;
}
int main()
{
	int tc;
	scanf("%d",&tc);
	ll num;
	while(tc--){
		scanf("%lld",&num);
		int ok = 0;
		if(num%2==0){
			ok = (num==2);
		}
		else if(num==3) ok = 1;
		else{
			ok = 1;
			for(int i=1; i<=100; i++){
				ll a = 2 + rand()%(num-4);
				if(bigMod(a,num-1,num)!=1){
					ok = 0;
					break;
				}
			}
		}
		printf("%s\n", (ok) ? "YES" : "NO");
	}
}  