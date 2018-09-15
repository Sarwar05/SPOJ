#include<bits/stdc++.h>
using namespace std;
#define mx 100005
struct input
{
    int l;
    int r;
    bool operator<(const input &ob)const
    {
        return r<ob.r;
    }
};
 
int main()
{
    int tc,n,cs=1;
    scanf("%d",&tc);
    while(tc--){
        scanf("%d",&n);
        vector<input>in(n);
        for(int i=0; i<n; i++){
            scanf("%d%d",&in[i].l, &in[i].r);
        }
        sort(in.begin(),in.end());
        int ans = 0,now=-1;
        for(int i=0; i<n; i++){
            if(in[i].l>=now){
                ans++;
                now = in[i].r;
            }
        }
        printf("%d\n",ans);
    }
    return 0;
}