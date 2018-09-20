#include<bits/stdc++.h>
using namespace std;
#define PI acos(-1.0)
double pie[10004];
int check(int n, double lim)
{
    int cnt = 0;
    for(int i=1; i<=n; i++){
        double area = PI*pie[i]*pie[i];
        cnt+=int(area/lim);
    }
    return cnt;
}
int main()
{
    int n,f;
    int tc;
    scanf("%d",&tc);
    while(tc--){
        scanf("%d%d",&n,&f);
        for(int i=1; i<=n; i++)
            scanf("%lf", &pie[i]);
        double lo = 0, hi = PI*10000.0*10000.0, mid;
        for(int i=1; i<=100; i++){
            mid = (lo+hi)/2.0;
            if(check(n,mid) >= (f+1))
                lo = mid;
            else hi = mid;
        }
        printf("%.5f\n",mid);
    }
}
