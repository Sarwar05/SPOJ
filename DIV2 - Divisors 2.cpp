#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define mx 1000002
int ndiv[mx] = {0};
int ok[mx] = {0};
int main()
{
    for(int i=1; i<=1000000; i++){
        for(int j=i; j<=1000000; j+=i)
            ndiv[j]++;
    }
    for(int i=1; i<=1e6; i++){
        for(int j=i; j<=1e6; j+=i){
            if(ndiv[j]%ndiv[i]!=0){
                ok[j] = 1;
            }
        }
    }
    int cnt = 0;
    for(int i=1; i<=1e6; i++){
        if(ok[i]==0 && ndiv[i]>3){
            cnt++;
            if(cnt%108==0)
                printf("%d\n",i);
        }
    }
}