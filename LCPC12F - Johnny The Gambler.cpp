#include<bits/stdc++.h>
using namespace std;
int C[1003], arr[100005];
int main()
{
    int t,x,n,a;
    scanf("%d",&t);
    for(int cs=1; cs<=t; cs++){
        scanf("%d%d",&x,&n);
        memset(C, 0, sizeof C);
        for(int i=1; i<=n; i++){
            scanf("%d",&a);
            C[a]++;
            arr[i] = a;
        }
        long long ans = 0;
        for(int i=1; i<=n; i++){
            C[arr[i]]--;
            int need = x - arr[i];
            if(need>=0 && need<=1000){
                ans+=C[need];
            }
        }
        printf("%d. %lld\n", cs, ans);
    }
}
