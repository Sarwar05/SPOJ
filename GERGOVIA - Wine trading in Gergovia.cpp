#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    while(scanf("%d",&n)){
        if(n==0) break;
        int arr[n];
        for(int i=0; i<n; i++) scanf("%d",&arr[i]);
        long long ans = 0,total=0;
        deque<int> dq;
        for(int i=0; i<n; i++){
            ans+=abs(total);
            total+=arr[i];
        }
        printf("%lld\n",ans);
    }
    return 0;
}