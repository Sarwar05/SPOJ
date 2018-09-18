#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define mx 100001
int height[mx];
ll ans[mx] = {0};
void solve(int start, int end, int h_ok)
{
    int mn = mx;
    for(int i=start; i<=end; i++)
        mn = min(mn, height[i]);
    int Next = start;
    for(int i=start; i<=end; i++){
        ans[i]+=(1LL*(mn-h_ok)*(i-start+1)*(end-i+1));
        if(height[i]==mn){
            solve(Next, i-1, mn);
            Next = i+1;
        }
    }
    if(Next<=end) solve(Next, end, mn);
}
int main()
{
    int n;
    scanf("%d",&n);
    for(int i=1; i<=n; i++)
        scanf("%d",&height[i]);
    solve(1,n,0);
    for(int i = 1; i<=n; i++){
        if(i>1) printf(" ");
        printf("%lld",ans[i]);
    }
    printf("\n");
}
