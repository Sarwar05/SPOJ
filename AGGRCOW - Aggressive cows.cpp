#include<bits/stdc++.h>
using namespace std;
#define mx 100005
int arr[mx];
int fun(int n, int m, int lim)
{
    m--;
    int now = arr[1];
    while(m){
        int id = lower_bound(arr+1, arr+n+1,now+lim) - arr;
        if(arr[id]==1000000009) return 0;
        now = arr[id];
        m--;
    }
    return m==0;
}
int main()
{
	int tc,n,m;
	scanf("%d",&tc);
	while(tc--){
        scanf("%d%d",&n,&m);
        for(int i=1; i<=n; i++)
            scanf("%d", &arr[i]);
        arr[n+1] = 1000000009;
        sort(arr+1, arr+n+1);
        int lo = 0, hi = 1000000000, mid,ans = -1;
        while(lo<=hi){
            mid = (lo+hi)/2;
            if(fun(n,m,mid)){
                lo = mid+1;
                ans = max(ans, mid);
            }
            else
                hi = mid-1;
        }
        printf("%d\n",ans);
	}

}
