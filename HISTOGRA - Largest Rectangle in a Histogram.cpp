#include<bits/stdc++.h>
using namespace std;
#define mx 100005
long long int arr[mx];
int table[mx][18];
void preprocess(int n)
{
    for(int i=0; i<n; i++) table[i][0] = i;
    for(int j=1; (1<<j)<=n; j++){
        for(int i=0; i+(1<<j)-1 < n; i++){
            if(arr[ table[i][j-1] ] < arr[ table[i+(1<<(j-1))][j-1] ]){
                table[i][j] = table[i][j-1];
            }
            else{
                table[i][j] = table[i+(1<<(j-1))][j-1];
            }
        }
    }
}
int query(int b, int e)
{
    int l = e-b+1;
    int k = log2(l);
    if(arr[table[b][k]]<arr[table[b+l-(1<<k)][k]])
        return table[b][k];
    return table[b+l-(1<<k)][k];
}
long long solve(int b, int e)
{
 
    if(b>e) return 0;
    if(b==e){
        return arr[b];
    }
    int ind = query(b,e);
    long long r1 = arr[ind] * (e-b+1);
    long long r2 = solve(b,ind-1);
    long long r3 = solve(ind+1,e);
    return max(r1, max(r2,r3));
}
int main()
{
    int n,tc;
    while(scanf("%d",&n),n){
        for(int i=0; i<n; i++) scanf("%lld",&arr[i]);
        preprocess(n);
        printf("%lld\n",solve(0,n-1));
    }
    return 0;
}