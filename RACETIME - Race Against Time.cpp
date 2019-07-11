#include<bits/stdc++.h>
using namespace std;
#define mx 100005
vector<int> block[320];
int len;
int arr[mx];
void Update(int id, int val)
{
    int b = id/len;
    int idx = lower_bound(block[b].begin(), block[b].end(),arr[id]) - block[b].begin();
    block[b][idx] = arr[id] = val;
    sort(block[b].begin(), block[b].end());
}
void Query(int l, int r, int x)
{
    int ans = 0;
    int L = l/len, R = r/len;
    if(L==R){
        for(int i=l; i<=r; i++)
            if(arr[i]<=x) ans++;
    }
    else{
        for(int i = L*len + len-1; i>=l; i--)
            if(arr[i]<=x)ans++;
        for(int i = L+1; i<R; i++)
            ans+=( upper_bound(block[i].begin(), block[i].end(),x) - block[i].begin() );
        for(int i = R*len; i<=r; i++)
            if(arr[i]<=x)ans++;
    }
    printf("%d\n", ans);
}
int main()
{
    int n,q;
    scanf("%d%d",&n,&q);
    len = sqrt(n)+1;
    for(int i=0; i<n; i++){
        scanf("%d",&arr[i]);
        block[ i/len ].push_back(arr[i]);
    }
    for(int i=0; i<=len; i++)
        sort(block[i].begin(), block[i].end());
    char typ[5];
    while(q--){
        scanf("%s",typ);
        if(typ[0]=='C'){
            int l,r,x;
            scanf("%d%d%d",&l,&r,&x);
            Query(l-1, r-1,x);
        }
        else{
            int l, v;
            scanf("%d%d",&l,&v);
            Update(l-1,v);
        }
    }
}
