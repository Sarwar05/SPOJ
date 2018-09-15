#include<bits/stdc++.h>
using namespace std;
 
long long int sieve_size;
bitset<10000010> bs;
vector<long long int> primes;
 
void sieve(long long int upperbound)
{
    sieve_size = upperbound + 1;
    bs.set();
    int x = sqrt((double)sieve_size);
    bs[0] = bs[1] = 0;
    primes.push_back((int)2);
    for (long long int j = 4; j <= sieve_size; j += 2)
        bs[j] = 0;
    for (long long int i = 3; i <= x; i+=2) {
            if (bs[i]){
            for (long long int j = i * i; j <= sieve_size; j += i)
                bs[j] = 0;
            primes.push_back((int)i);
        }
    }
    if(x%2==1)
        x++;
    for (long long int i = x+1; i <= sieve_size; i+=2){
        if (bs[i])
            primes.push_back((int)i);
    }
}
long long int numDiffPF(long long int N)
{
    long long int PF_idx = 0, PF = primes[PF_idx], ans = 0;
    while (N != 1 && (PF * PF <= N)){
        if (N % PF == 0)
            ans++;
        while (N % PF == 0)
            N /= PF;
        PF = primes[++PF_idx];
    }
    if (N != 1)
        ans++;
    return ans;
}
vector<int> mp[11];
int main()
{
 
    sieve(1000006);
    mp[0].push_back(1);
//    for(int i=2; i<=10; i++){
//        cout<<i<<" "<<numDiffPF(i)<<endl;
//    }
    for(int i=2; i<=1000000; i++){
        int xxx = numDiffPF(i);
        if(xxx<=10) mp[xxx].push_back(i);
    }
    int tc,a,b,n;
    scanf("%d",&tc);
    while(tc--){
        scanf("%d%d%d",&a,&b,&n);
        int pos_a = lower_bound(mp[n].begin(), mp[n].end(),a) - mp[n].begin();
        int pos_b = upper_bound(mp[n].begin(), mp[n].end(),b) - mp[n].begin() - 1;
        //cout<<pos_a<<" "<<pos_b<<endl;
        printf("%d\n",pos_b-pos_a+1);
    }
    return 0;
}