#include<bits/stdc++.h>
using namespace std;
int dp[90][90][10][2];
vector<int> arr;
int fun(int even, int odd, int pos, int small)
{
    if(pos==10)
        return even>odd;
    int &ret = dp[even][odd][pos][small];
    if(ret!=-1) return ret;
    ret = 0;
    if(small){
        for(int i=0; i<=9; i++){
            if(i%2==0){
                ret+=fun(even+i, odd, pos+1, 1);
            }
            else{
                ret+=fun(even, odd+i, pos+1, 1);
            }
        }
    }
    else{
        for(int i=0; i<=arr[pos]; i++){
            if(i%2==0){
                ret+=fun(even+i, odd, pos+1, i<arr[pos]);
            }
            else{
                ret+=fun(even, odd+i, pos+1, i<arr[pos]);
            }
        }
    }
    return ret;
}
void gen(int n)
{
    arr.clear();
    for(int i=0; i<=9; i++){
        arr.push_back(n%10);
        n/=10;
    }
    reverse(arr.begin(), arr.end());
}
int main()
{
    int tc,a,b;
    scanf("%d",&tc);
    while(tc--){
        scanf("%d%d",&a,&b);
        if(a>b) swap(a,b);
        gen(b);
        memset(dp, -1, sizeof dp);
        int ansb = fun(0,0,0,0);
        gen(a-1);
        memset(dp, -1, sizeof dp);
        int ansa = fun(0,0,0,0);
        printf("%d\n",ansb-ansa);
    }
}
