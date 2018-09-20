#include<bits/stdc++.h>
using namespace std;
double getArea(double a, double b, double c)
{
    double s = (a+b+c)/2.0;
    return sqrt(s*(s-a)*(s-b)*(s-c));
}
int main()
{
    int tc;
    scanf("%d",&tc);
    double r1,r2,r3;
    while(tc--){
        scanf("%lf%lf%lf",&r1,&r2,&r3);
        double total = getArea(r1+r3, r3+r2, r1+r2);
        double lo = 0, hi = 1e9, mid;
        for(int i=1; i<=100; i++){
            mid = (lo+hi)/2.0;
            double tri1 = getArea(r1+mid, r3+mid, r1+r3);
            double tri2 = getArea(r1+mid, r2+mid, r1+r2);
            double tri3 = getArea(r2+mid, r3+mid, r2+r3);
            if((tri1 + tri2 + tri3) >= total)
                hi = mid;
            else lo = mid;
        }
        printf("%.10f\n",mid);
    }
}
