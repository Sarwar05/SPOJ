#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    while(scanf("%d", &n), n){
        vector<int> v(n);
        for(int i=0; i<n; i++)
            scanf("%d",&v[i]);
        int ans = 0;
        sort(v.begin(), v.end());
        for(int i=0; i<n; i++){
            for(int j=i+1; j<n; j++){
                ans+=(n - (upper_bound(v.begin(), v.end(), v[i]+v[j]) - v.begin()));
            }
        }
        printf("%d\n",ans);
    }
}
