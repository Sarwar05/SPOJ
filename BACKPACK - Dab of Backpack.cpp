#include<bits/stdc++.h>
using namespace std;
#define pii pair<int,int>
#define mx 62
#define ff first
#define ss second
vector<pii> item[mx];
vector<int> add[mx];
void process()
{
    for(int i=0; i<mx; i++){
        if(item[i].empty()) continue;
        vector<pii> v = item[i];
        item[i].clear();
        add[i].clear();
        if(v.size()==1){
            item[i].push_back(v[0]);
            add[i].push_back(v[0].ff*v[0].ss);
        }
        else if(v.size()==2){
            item[i].push_back(v[0]);
            add[i].push_back(v[0].ff*v[0].ss);
            item[i].push_back({v[0].ff+v[1].ff, v[0].ss+v[1].ss});
            add[i].push_back(v[0].ff*v[0].ss + v[1].ff*v[1].ss);
        }
        else{
            item[i].push_back(v[0]);
            add[i].push_back(v[0].ff*v[0].ss);
            item[i].push_back({v[0].ff+v[1].ff, v[0].ss+v[1].ss});
            add[i].push_back(v[0].ff*v[0].ss + v[1].ff*v[1].ss);
            item[i].push_back({v[0].ff+v[2].ff, v[0].ss+v[2].ss});
            add[i].push_back(v[0].ff*v[0].ss + v[2].ff*v[2].ss);
            item[i].push_back({v[0].ff+v[1].ff+v[2].ff, v[0].ss+v[1].ss+v[2].ss});
            add[i].push_back(v[0].ff*v[0].ss + v[1].ff*v[1].ss + v[2].ff*v[2].ss);
        }
    }
}
int dp[mx][3205][302];
int lim;
int fun(int pos, int cost, int imp)
{
    if(pos>60){
        return 0;
    }
    if(dp[pos][cost][imp]!=-1) return dp[pos][cost][imp];
    int ret = 0;
    for(int i=0; i<item[pos].size(); i++)
        if(cost+item[pos][i].ff <= lim)
            ret = max(ret, (10*add[pos][i]) + fun(pos+1, cost+item[pos][i].ff, imp+item[pos][i].ss));
    ret = max(ret, fun(pos+1, cost, imp));
    return dp[pos][cost][imp] = ret;
}
int main()
{
    int tc;
    scanf("%d",&tc);
    while(tc--){
        for(int i=0; i<mx; i++){
            item[i].clear();
            add[i].clear();
        }
        int n,a,b,c;
        scanf("%d%d",&lim,&n);
        lim/=10;
        for(int i=1; i<=n; i++){
            scanf("%d%d%d",&a,&b,&c);
            a/=10;
            if(c){
                item[c].push_back({a,b});
            }
            else{
                if(item[i].empty())
                    item[i].push_back({a,b});
                else{
                    pii xx = item[i][0];
                    item[i][0] = {a,b};
                    item[i].push_back(xx);
                }
            }
        }
        process();
        memset(dp, -1, sizeof dp);
        printf("%d\n",fun(1,0,0));
    }
}
