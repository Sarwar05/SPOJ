#include <bits/stdc++.h>
using namespace std;
#define ll long long
string str;
int len;
ll dp[92][2][2];
ll fun(int pos,  int prev, int isSmall)
{
	if(pos==len){
		return 1;
	}
	ll& ret = dp[pos][prev][isSmall];
	if(ret!=-1  && isSmall) return ret;
	ret = 0;
	if(isSmall){
		if(prev==0){
			ret+=fun(pos+1, 0, 1);
			ret+=fun(pos+1, 1, 1);
		}
		else{
			ret+=fun(pos+1, 0, 1);
		}
	}
	else{
		if(prev==0){
			if(str[pos]=='0'){
				ret+=fun(pos+1, 0, 0);
			}
			else{
				ret+=fun(pos+1, 0, 1);
				ret+=fun(pos+1, 1, 0);
			}
		}
		else{
			ret+=fun(pos+1, 0, str[pos]=='1');
		}
	}
	return ret;
}
int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(NULL);
	int tc;
	cin>>tc;
	for(int cs=1 ; cs<=tc; cs++){
		cin>>str;
		len = str.size();
		memset(dp, -1, sizeof dp);
		ll ans = fun(1,1,0);
		for(int i=1; i<len; i++){
			ans+=fun(i+1, 1, 1);
		}
		cout<<"Case "<<cs<<": "<<ans<<endl;
	}
	return 0;
} 