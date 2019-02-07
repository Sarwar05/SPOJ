#include<bits/stdc++.h>
using namespace std;
int dp[2002][2002];
bool fun(int rem, int prev)
{
    if(rem<=2*prev) return 1;
    int &ret = dp[rem][prev];
    if(ret!=-1) return ret;
    ret = 0;
    for(int i=1; i<=2*prev; i++){
        if(fun(rem-i, i) == 0) ret = 1;
        if(rem-i<=0) break;
    }
    return ret;
}
int main()
{
    /**
    memset(dp, -1, sizeof dp);
    for(int i=2; i<=2000; i++){
        int win = 0;
        for(int j=1; j<i; j++){
            int now = fun(i-j, j);
            if(now==0) win++;
        }
        if(win==0) printf("%d\n", i);
    }
    */
    printf("2\n3\n5\n8\n13\n21\n34\n55\n89\n144\n233\n377\n610\n987\n1597\n");
}
