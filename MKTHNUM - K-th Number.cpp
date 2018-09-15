#include<bits/stdc++.h>
using namespace std;
#define mx 100005
int arr[mx];
vector<int> tree[mx*4],zero;
void build(int pos, int b, int e)
{
    if(b>e) return;
    if(b==e){
        tree[pos].push_back(arr[b]);
        return;
    }
    int m = (b+e)/2;
    int l = pos*2;
    int r = l+1;
    build(l,b,m);
    build(r,m+1,e);
    int n1 = tree[l].size();
    int n2 = tree[r].size();
    int i=0,j=0;
    while(i<n1 || j<n2){
        if(i>=n1){
            tree[pos].push_back(tree[r][j]);
            i++;
            j++;
        }
        else if(j>=n2){
            tree[pos].push_back(tree[l][i]);
            i++;
            j++;
        }
        else{
            if(tree[l][i]<tree[r][j]){
                tree[pos].push_back(tree[l][i]);
                i++;
            }
            else{
                tree[pos].push_back(tree[r][j]);
                j++;
            }
        }
    }
}
int query(int pos, int b, int e, int i, int j, int idx)
{
    if(b>e || b>j || e<i) return 0;
    if(b>=i && e<=j){
        int ret = (upper_bound(tree[pos].begin(),tree[pos].end(),idx)-tree[pos].begin());
        return ret;
    }
    int m = (b+e)/2;
    int l = pos*2;
    int r = l+1;
    return query(l,b,m,i,j,idx) + query(r,m+1,e,i,j,idx);
}
int main()
{
    int n,q,a,b,c;
    scanf("%d%d",&n,&q);
    int mxx = INT_MIN;
    int mnn = INT_MAX;
    for(int i=1; i<=n; i++){
        scanf("%d",&arr[i]);
        mxx = max(mxx, arr[i]);
        mnn = min(mnn,arr[i]);
    }
    arr[0] = -1;
 
    build(1,1,n);sort(arr,arr+n+1);
    //for(int i=0; i<tree[1].size(); i++) cout<<" "<<tree[1][i];
   // cout<<endl;
    while(q--){
        scanf("%d%d%d",&a,&b,&c);
        int low = mnn, high = mxx , mid, ans ;
        while(low <= high) {
            mid = (low + high)/2;
            int k = query(1,1,n,a,b,mid);
            if(k >= c) {
                if(binary_search(arr,arr+n+1,mid))
                    ans = mid;
                high = mid-1;
                //cout<<"ans: "<<ans<<endl;
            }
            else low = mid+1;
        }
        printf("%d\n",ans);
    }
    return 0;
}