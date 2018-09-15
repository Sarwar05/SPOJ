#include <iostream>
using namespace std;
#define ll long long
int bigmod(ll a, ll b)
{
	if(b==0) return 1;
	else{
		int x = bigmod(a, b/2);
		x = (x*x)%10;
		if(b%2==1) x = (x*a)%10;
		return x;
	}
}
int main() {
	ll t,a,b;
	cin>>t;
	while(t--){
		cin>>a>>b;
		cout<<bigmod(a,b)<<endl;
	}
	return 0;
} 