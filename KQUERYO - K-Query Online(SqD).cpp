

#include<bits/stdc++.h>
using namespace std;
#define mx 30004
int arr[mx];
vector<int> block[180];
int sz;
int main()
{
    int n,a;
    scanf("%d",&n);
    sz = sqrt(n)+1;
    for(int i=0; i<n; i++){
        scanf("%d",&a);
        arr[i] = a;
        block[i/sz].push_back(a);
    }
    for(int i=0; i<=sz; i++)
        sort(block[i].begin(), block[i].end());
    int q;
    scanf("%d",&q);
    int ans = 0;
    while(q--){
        int l,r,k;
        scanf("%d%d%d",&l,&r,&k);
        l^=ans;
        r^=ans;
        k^=ans;
        if(l<1) l = 1;
        if(r>n) r = n;
        if(l>r){
            printf("0\n");
            ans = 0;
            continue;
        }
        l--;r--;
        ans = 0;
        /**
        int L = l/sz, R = r/sz;
        if(L==R){
            for(int i=l; i<=r; i++)
                if(arr[i]>k) ans++;
        }
        else{
            for(int i = (L+1)*sz-1; i>=l; i--)
                if(arr[i]>k) ans++;
            for(int i = L+1; i<=R-1; i++)
                ans+=( sz - (upper_bound(block[i].begin(), block[i].end(), k)- block[i].begin()));
            for(int i = R*sz; i<=r; i++)
                if(arr[i]>k) ans++;
        }
        */
        for(int i=l; i<=r; ){
            if(i%sz==0 && i+sz-1 <=r){
                int id = i/sz;
                ans+=( sz - (upper_bound(block[id].begin(), block[id].end(), k)- block[id].begin()));
                i+=sz;
            }
            else{
                if(arr[i] > k) ans++;
                i++;
            }
        }
        printf("%d\n", ans);
    }
}
