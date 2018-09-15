#include<bits/stdc++.h>
using namespace std;
#define mx 100005
int dp[52][mx];
int arr[mx];
vector<int> positon, monster;
int sz,dist;
int query(int b, int e)
{
    if(b==0) return arr[e];
    else return arr[e]-arr[b-1];
}
int fun(int step,int pos)
{
    if(step<=0 || pos>=sz) return 0;
    if(dp[step][pos]!=-1) return dp[step][pos];
    int ret1=0,ret2=0;
    ret1 = fun(step, pos+1);
    int x = upper_bound(positon.begin(), positon.end(),positon[pos]+dist)-positon.begin()-1;
    ret2 = query(pos,x) + fun(step-1, x+1);
    return dp[step][pos] = max(ret1, ret2);
}
int main()
{
    int tc,cs=1,n,r,k,a,b;
    scanf("%d",&tc);
    while(tc--){
        scanf("%d%d%d",&n,&r,&k);
        dist = r*2;
        memset(arr, 0, sizeof arr);
        memset(dp,-1,sizeof dp);
        map<int, int> mp;
        for(int i=1; i<=n; i++){
            scanf("%d%d",&a,&b);
            mp[a]+=b;
        }
        positon.clear(), monster.clear();
        for(auto it = mp.begin(); it!=mp.end(); it++){
            positon.push_back(it->first);
            monster.push_back(it->second);
        }
        sz = positon.size();
        arr[0] = monster[0];
        for(int i=1; i<sz; i++){
            arr[i] = arr[i-1] + monster[i];
        }
        int ans = fun(k,0);
        printf("Case %d: %d\n",cs++,ans);
    }
    return 0;
} 