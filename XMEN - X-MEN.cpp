#include<bits/stdc++.h>
using namespace std;
#define mx 100005
int dummy[mx];
int main()
{
    int tc,n,a;
    scanf("%d",&tc);
    while(tc--){
        scanf("%d",&n);
        for(int i=1; i<=n; i++){
            scanf("%d",&a);
            dummy[a] = i;
        }
        set<int> lis;
        for(int i=1; i<=n; i++){
            scanf("%d",&a);
            lis.insert(dummy[a]);
            auto it = lis.upper_bound(dummy[a]);
            if(it!=lis.end())
                lis.erase(it);
        }
        printf("%d\n",(int)lis.size());
    }
}
