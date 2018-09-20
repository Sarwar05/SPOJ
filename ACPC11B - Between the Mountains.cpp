#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n,m,a,tc;
    scanf("%d",&tc);
    while(tc--){
        scanf("%d",&n);
        vector<int> v1(n);
        for(int i=0; i<n; i++) scanf("%d",&v1[i]);
        scanf("%d",&m);
        vector<int> v2(m);
        for(int i=0; i<m; i++) scanf("%d",&v2[i]);
        sort(v1.begin(), v1.end());
        int ans = INT_MAX;
        for(int i=0; i<m; i++){
            int id = lower_bound(v1.begin(), v1.end(), v2[i]) - v1.begin();
            if(id>0) ans= min(ans, abs(v1[id-1] - v2[i]));
            if(id==n) continue;
            ans= min(ans, abs(v1[id] - v2[i]));
        }
        printf("%d\n",ans);
    }
}
