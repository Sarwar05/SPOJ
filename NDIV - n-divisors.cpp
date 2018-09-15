#include<bits/stdc++.h>
using namespace std;
 
 int sieve_size;
bitset<10000010> bs;
vector< int> primes;
void sieve( int upperbound)
{
    sieve_size = upperbound + 1;
    bs.set();
    int x = sqrt((double)sieve_size);
    bs[0] = bs[1] = 0;
    primes.push_back((int)2);
    for ( int j = 4; j <= sieve_size; j += 2)
        bs[j] = 0;
    for ( int i = 3; i <= x; i+=2) {
            if (bs[i]){
            for ( int j = i * i; j <= sieve_size; j += i)
                bs[j] = 0;
            primes.push_back((int)i);
        }
    }
    if(x%2==1)
        x++;
    for ( int i = x+1; i <= sieve_size; i+=2){
        if (bs[i])
            primes.push_back((int)i);
    }
}
 int numDiv(unsigned int N)
{
    int PF_idx = 0;
    unsigned int PF = primes[PF_idx];
    int  ans = 1;
    while (N != 1 && (PF * PF <= N)){
         int power = 0;
        while (N % PF == 0){
            N /= PF;
            power++;
        }
        ans *= (power + 1);
        PF = primes[++PF_idx];
    }
    if (N != 1)
        ans *= 2;
    return ans;
}
int main()
{
 
    sieve(100000);
    int a,b,n,ans=0;
    scanf("%d%d%d",&a,&b,&n);
    for(int i=a; i<=b; i++)
        if(numDiv(i)==n) ans++;
        printf("%d\n",ans);
    return 0;
}