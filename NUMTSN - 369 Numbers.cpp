#include<bits/stdc++.h>
using namespace std;
#define mod 1000000007
#define ll int
string str1,str2;
int len;
ll dp[52][18][18][18][2][2];
ll fun(int pos=0, int three=0, int six=0, int nine=0, int isLarge=0, int isSmall=0)
{
	if(pos==len) return ((three==six) && (six==nine) && (three>0));
	if(three>=17 || six>=17 || nine>=17) return 0;
	ll& ret = dp[pos][three][six][nine][isLarge][isSmall];
	if(ret!=-1 && isLarge && isSmall) return ret;
	ret = 0;
	char low = '0', high = '9';
	if(isLarge==0)
		low = str1[pos];
	if(isSmall==0)
		high = str2[pos];
	for(char i=low; i<=high; i++){
		if(i=='3'){
			ret+=fun(pos+1, three+1, six, nine,isLarge|(i>low) ,isSmall|(i<high) );
		}
		else if(i=='6'){
			ret+=fun(pos+1, three, six+1, nine,isLarge|(i>low) ,isSmall|(i<high) );
		}
		else if(i=='9'){
			ret+=fun(pos+1, three, six, nine+1,isLarge|(i>low) ,isSmall|(i<high) );
		}
		else{
			ret+=fun(pos+1, three, six, nine,isLarge|(i>low) ,isSmall|(i<high) );
		}
		if(ret>=mod) ret%=mod;
	}
	return ret; 
}
int main()
{
    ios_base::sync_with_stdio(0);
	cin.tie(NULL);
	int tc;
	cin>>tc;
	memset(dp, -1, sizeof dp);
	for(int cs=1; cs<=tc; cs++){
        cin>>str1>>str2;
        int len1 = str1.size();
        int len2 = str2.size();
        int add = len1-len2;
        string sss = "";
        for(int i=len1+1; i<=51; i++){
            sss+="0";
        }
        str1 = sss+str1;
        sss = "";
        for(int i=len2+1; i<=51; i++){
            sss+="0";
        }
        str2 = sss+str2;
        len = 51;
	    //memset(dp, -1, sizeof dp);
        cout<<fun()<<endl;
	}
	return 0;
}
/// 100000000000000000000000000000000000000000000000000
 