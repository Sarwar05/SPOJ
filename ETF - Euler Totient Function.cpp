#include<bits/stdc++.h>
using namespace std;
int phi[1000006];
int main()
{
    for(int i=1; i<=1e6; i++) phi[i]=i;
    for(int i=2; i<=1e6; i++){
        if(phi[i]==i){
            for(int j = i; j<=1e6; j+=i)
                phi[j] -=(phi[j]/i);
        }
    }
    int tc,a;
    scanf("%d",&tc);
    while(tc--){
        scanf("%d",&a);
        printf("%d\n",phi[a]);
    }
} 