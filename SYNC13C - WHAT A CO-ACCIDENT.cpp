#include<bits/stdc++.h>
using namespace std;
int main()
{
    int a,b,c;
    scanf("%d",&c);
    while(c--){
        scanf("%d%d",&a,&b);
        if(a%2==0 || b%2==0)
            printf("Suresh\n");
        else printf("Ramesh\n");
    }
}
 