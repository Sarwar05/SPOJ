#include<bits/stdc++.h>
using namespace std;
int arr[100005];
int main()
{
    int tc,n,m;
    scanf("%d",&tc);
    while(tc--){
        scanf("%d%d",&n,&m);
        unordered_map<int, int> mp;
        for(int i=1; i<=n; i++){
            scanf("%d", &arr[i]);
            mp[arr[i]]++;
        }
        long long ans =0;
        for(int i=1; i<=n; i++)
            ans+=mp[ m - arr[i] ];
        printf("%lld\n",ans/2);
    }
}
