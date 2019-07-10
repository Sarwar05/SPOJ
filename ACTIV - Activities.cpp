#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define mx 100004
#define mod 100000000
vector< pair<int, int > >arr;
int n;
ll dp[mx];
int binarySearch(int id)
{
	int lo = 0, hi=id-1, mid, ret = 0;;
	while(lo<=hi){
		mid = (lo+hi)/2;
		if(arr[mid].first<=arr[id].second){
			lo = mid+1;
			ret = max(ret, mid);
		}
		else hi = mid-1;
	}
	return ret;
}
int main()
{
	while(scanf("%d",&n)){
        if(n==-1) break;
		memset(dp, 0, sizeof dp);
		arr.clear();
		arr.push_back({0,0});
		int l,r;
		for(int i=0; i<n; i++){
			scanf("%d%d",&l,&r);
			arr.push_back({r,l});
		}
		sort(arr.begin(), arr.end());
        for(int i=1; i<=n; i++){
            int id = binarySearch(i);
            dp[i] = dp[id] + 1;
            dp[i]+=dp[i-1];
            dp[i]%=mod;
		}
		printf("%08lld\n", dp[n]);
	}
}

