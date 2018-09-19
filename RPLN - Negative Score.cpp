#include<bits/stdc++.h>
using namespace std;
#define mx 100002
int table[mx][17];
int main()
{
    int tc,cs=1,a,b,n,q;
    scanf("%d",&tc);
    while(tc--){
        scanf("%d%d",&n,&q);
        for(int i=1; i<=n; i++)
            scanf("%d",&table[i][0]);
        for(int j=1; (1<<j)<=n; j++)
            for(int i=1; i + (1<<j) - 1 <=n; i++)
                table[i][j] = min(table[i][j-1], table[i+(1<<(j-1))][j-1]);
        printf("Scenario #%d:\n",cs++);
        while(q--){
            scanf("%d%d",&a,&b);
            if(a>b) swap(a,b);
            int k = log2(b-a+1);
            printf("%d\n", min(table[a][k], table[b-(1<<k)+1][k]));
        }
    }
}
