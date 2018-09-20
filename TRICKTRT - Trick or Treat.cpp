#include<bits/stdc++.h>
using namespace std;
#define mx 50004
double x[mx], y[mx];
double get(int n, double mid)
{
    double mxd = 0;
    for(int i=1; i<=n; i++){
        mxd = max(mxd,  (mid-x[i])*(mid-x[i]) + y[i]);
    }
    return sqrt(mxd);
}
int main()
{
    int n;
    while(scanf("%d",&n),n){
        for(int i=1; i<=n; i++){
            scanf("%lf%lf",&x[i], &y[i]);
            y[i]*=y[i];
        }
        double lo = -200000, hi = 200000, mid1, mid2;
        for(int i=1; i<=100; i++){
            mid1 = (2.0*lo + hi)/3.0;
            mid2 = (lo + 2.0*hi)/3.0;
            double d1 = get(n, mid1);
            double d2 = get(n, mid2);
            if(d1<d2) hi = mid2;
            else lo = mid1;
        }
        printf("%.10f %.10f\n",(mid1+mid2)/2.0, get(n,(mid1+mid2)/2.0));
    }
}
