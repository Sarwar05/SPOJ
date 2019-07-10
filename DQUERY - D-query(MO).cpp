
#include<bits/stdc++.h>
using namespace std;
int block_size;
int arr[30004];
struct Query
{
    int l;
    int r;
    int idx;
    bool operator<(const Query& ob) const
    {
        if(l/block_size != ob.l/block_size)
            return l/block_size < ob.l/block_size;
        return r<ob.r;
    }
};
Query query[200005];int ans[200005];
int cnt[1000006];
int answer;
void add(int pos)
{
    int val = arr[pos];
    cnt[val]++;
    if(cnt[val]==1) answer++;
}
void remove(int pos)
{
    int val = arr[pos];
    cnt[val]--;
    if(cnt[val]==0) answer--;
}
void solve(int n, int q)
{
    block_size = sqrt(n)+1;
    answer = 0;
    memset(cnt, 0, sizeof cnt);
    sort(query, query+q);
    int currL = 0, currR = -1;
    for(int i=0; i<q; i++){
        int L = query[i].l;
        int R = query[i].r;
        while(currL > L){
            currL--;
            add(currL);
        }
        while(currR < R){
            currR++;
            add(currR);
        }
        while(currL < L){
            remove(currL);
            currL++;
        }
        while(currR > R){
            remove(currR);
            currR--;
        }
        ans[ query[i].idx ] = answer;
    }
}
int main()
{
    int n,q;
    scanf("%d",&n);
    for(int i=0; i<n; i++) scanf("%d",&arr[i]);
    scanf("%d",&q);
    for(int i=0; i<q; i++){
        scanf("%d%d",&query[i].l, &query[i].r);
        query[i].l--;
        query[i].r--;
        query[i].idx = i;
    }
    solve(n,q);
    for(int i=0; i<q; i++)
        printf("%d\n", ans[i]);
}
