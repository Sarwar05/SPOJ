#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin>>n;
    long long ans = 0;
    for(int i=1; i<=n; i++){
        int x = n/i;
        x-=(i-1);
        if(x<=0) break;
        ans+=x;
    }
    cout<<ans<<endl;
}
