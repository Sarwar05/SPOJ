#include<bits/stdc++.h>
using namespace std;
#define mx 2000005
int tree[mx][21], arr[mx];
int main()
{
    int n;
    while(scanf("%d",&n),n){
        tree[0][0] = 0;
        for(int i=1; i<=n; i++){
            scanf("%d",&arr[i]);
            tree[i][0] = arr[i] + tree[i-1][0];
        }
        for(int i=n+1, j = 1; j<=n; j++, i++){
            arr[i] = arr[j];
            tree[i][0] = arr[i] + tree[i-1][0];
        }
        for(int j=1; (1<<j) <2*n; j++)
            for(int i=1; i + (1<<j) - 1 < 2*n  ; i++)
                tree[i][j] = min(tree[i][j-1], tree[i+(1<<(j-1))][j-1] );
        int xtra = 0,ans = 0;
        int k = log2(n);
        for(int i=1; i<=n; i++){
            int mn = min( tree[i][k] , tree[(i+n-1) - (1<<k) + 1 ][k] );
            if(mn-xtra >= 0)ans++;
            xtra=tree[i][0];
        }
        printf("%d\n",ans);
    }
}
