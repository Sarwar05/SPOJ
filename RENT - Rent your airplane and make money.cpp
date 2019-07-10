#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define mx 10004
vector< pair<int, pair<int, int> > >arr;
int n;
ll dp[mx];
int binarySearch(int id)
{
	int lo = 0, hi=id-1, mid, ret = 0;;
	while(lo<=hi){
		mid = (lo+hi)/2;
		if(arr[mid].first<=arr[id].second.first){
			lo = mid+1;
			ret = max(ret, mid);
		}
		else hi = mid-1;
	}
	return ret;
}
int main()
{
	int tc;
	scanf("%d",&tc);
	while(tc--){
		memset(dp, 0, sizeof dp);
		arr.clear();
		arr.push_back({0, {0,0}});
		scanf("%d",&n);
		int l,r,p;
		for(int i=0; i<n; i++){
			scanf("%d%d%d",&l,&r,&p);
			r+=l;
			arr.push_back({r, {l, p}});
		}
		sort(arr.begin(), arr.end());
		for(int i=1; i<=n; i++)
			dp[i] = max(dp[i-1], dp[binarySearch(i)] + arr[i].second.second);
		printf("%lld\n", dp[n]);
	}
	return 0;
}
