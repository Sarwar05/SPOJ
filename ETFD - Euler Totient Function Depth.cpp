#include<bits/stdc++.h>
using namespace std;
#define mx 1000006
vector<int> adj[mx];
int dp[mx];
int phi[mx];
int fun(int n)
{
    if(n==1) return 0;
    if(dp[n]!=-1) return dp[n];
    return dp[n] = 1 + fun(phi[n]);
}
int main()
{
    for(int i=1; i<mx; i++) phi[i] = i;
    for(int i=2; i<mx; i++){
        if(phi[i]==i){
            for(int j = i; j<mx; j+=i)
                phi[j]-=(phi[j]/i);
        }
    }
    memset(dp, -1, sizeof dp);
    for(int i=1; i<mx; i++)
        adj[ fun(i) ].push_back(i);
    int tc, l, r, k;
    scanf("%d",&tc);
    while(tc--){
        scanf("%d%d%d",&l,&r,&k);
        int ans = upper_bound(adj[k].begin(), adj[k].end(), r)-lower_bound(adj[k].begin(), adj[k].end(), l);
        printf("%d\n", ans);
    }
}
