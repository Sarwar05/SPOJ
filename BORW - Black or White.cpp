#include<bits/stdc++.h>
using namespace std;
#define mx 202
int arr[mx], n;
int dp[mx][mx][mx];
int fun(int pos, int prevlis, int prevlds)
{
    if(pos>n) return 0 ;
    int& ret = dp[pos][prevlis][prevlds];
    if(ret!=-1) return ret;
    ret = 500;
    if(arr[pos] > prevlis) ret = min(ret, fun(pos+1, arr[pos], prevlds));
    if(arr[pos] < prevlds) ret = min(ret, fun(pos+1, prevlis, arr[pos]));
    ret = min(ret, 1 + fun(pos+1, prevlis, prevlds));
    return ret;
}
int main()
{
    while(scanf("%d",&n)){
        if(n==-1) break;
        memset(dp, -1, sizeof dp);
        set<int> st;
        for(int i=1; i<=n; i++){
            scanf("%d",&arr[i]);
            st.insert(arr[i]);
        }
        unordered_map<int, int> mp;
        int id = 1;
        for(auto x:st)
            mp[x] = id++;
        for(int i=1; i<=n; i++)
            arr[i] = mp[ arr[i] ];
        printf("%d\n",fun(1,0,201));
    }
}
