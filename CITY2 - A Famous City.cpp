#include<bits/stdc++.h>
using namespace std;
#define mx 100002
int table[mx][17], arr[mx];
unordered_map<int, vector<int> >mp;
void build(int n)
{
    for(int i=1; i<=n; i++)
        table[i][0] = arr[i];
    for(int j=1; (1<<j)<=n; j++){
        for(int i=1; i + (1<<j) - 1<=n; i++){
            table[i][j] = min(table[i][j-1], table[ i + (1<<(j-1)) ][j-1]);
        }
    }
}
int query(int low, int high)
{
    int k = log2(high-low+1);
    return min(table[low][k], table[high-(1<<k)+1][k]  );
}
int main()
{
    int n, cs =1;
    while(scanf("%d",&n)!=EOF){
        mp.clear();
        for(int i=1; i<=n; i++){
            scanf("%d",&arr[i]);
            if(arr[i])mp[ arr[i] ].push_back(i);
        }
        build(n);
        int ans = 0;
        for(auto it = mp.begin(); it!=mp.end(); it++){
             vector<int> v =  it->second;
             int now = it->first;
             ans++;
             for(int i=1; i<v.size(); i++){
                if(query(v[i-1], v[i])<now)
                    ans++;
             }
        }
        printf("Case %d: %d\n", cs++,ans);
    }
}
