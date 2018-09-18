#include<bits/stdc++.h>
using namespace std;
#define mx 50002
int table[mx][16], arr[mx];
void build(int n)
{
    for(int i=1; i<=n; i++)
        table[i][0] = arr[i];
    for(int j=1; (1<<j)<=n; j++){
        for(int i=1; i + (1<<j) -1 <= n ; i++)
            table[i][j] = max(table[i][j-1], table[i+(1<<(j-1))][j-1]);
    }
}
int query(int low, int high)
{
    int len = high-low+1;
    int k = log2(len);
    return max( table[low][k], table[ high - (1<<k) +1][k] );
}
int main()
{
    int n,m,a,b;
    scanf("%d%d",&n,&m);
    for(int i=1; i<=n; i++)
        scanf("%d",&arr[i]);
    build(n);
    int ans = 0;
    while(m--){
        scanf("%d%d",&a,&b);
        if(a>b) swap(a,b);
        if(abs(a-b)<=1) ans++;
        else{
            int mxe = query(a+1,b-1);
            if(mxe<=arr[a]) ans++;
        }
    }
    printf("%d\n",ans);
}
