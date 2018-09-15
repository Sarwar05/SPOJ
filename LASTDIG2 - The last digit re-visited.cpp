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
	string s;
	cin>>t;
	while(t--){
		cin>>s>>b;
		a = s[s.size()-1]-'0';
		cout<<bigmod(a,b)<<endl;
	}
	return 0;
} 