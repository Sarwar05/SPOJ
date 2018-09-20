#include<bits/stdc++.h>
using namespace std;
int arr[100002];
int main()
{
    int n,k;
    scanf("%d%d",&n,&k);
    for(int i=1; i<=n; i++) scanf("%d",&arr[i]);
    sort(arr+1, arr+1+n);
    int ans = 0;
    for(int i=1; i<=n; i++)
        if(binary_search(arr+1, arr+1+n, arr[i]+k))
            ans++;
    printf("%d\n",ans);
}
