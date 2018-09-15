#include<bits/stdc++.h>
using namespace std;
#define mx 200005
int tree[mx*4] = {0},value[mx*4],arr[mx];
struct Query
{
    char ch;
    int val;
}qry[mx];
void update(int pos, int b, int e,int i, int val,int id)
{
    if(b>e || b>i || e<i) return;
    if(b>=i && e<=i){
        tree[pos] = val;
        value[pos] = qry[id].val;
        return;
    }
    int m = (b+e)/2;
    int l = pos*2;
    int r = l+1;
    update(l,b,m,i,val,id);
    update(r,m+1,e,i,val,id);
    tree[pos] = tree[l] + tree[r];
}
int cquery(int pos, int b, int e, int i, int j)
{
    if(b>e || b>j || e<i) return 0;
    if(b>=i && e<=j){
        return tree[pos];
 
    }
    int m = (b+e)/2;
    int l = pos*2;
    int r = l+1;
    return cquery(l,b,m,i,j) + cquery(r,m+1,e,i,j);
}
int kquery(int pos, int b, int e, int k)
{
    if(b==e) return value[pos];
    int m = (b+e)/2;
    int l = pos*2;
    int r = l+1;
    if(tree[l]>=k){
        return kquery(l,b,m,k);
    }
    else{
        return kquery(r,m+1,e,k-tree[l]);
    }
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin>>n;
    for(int i=1; i<=n; i++){
        cin>>qry[i].ch>>qry[i].val;
        arr[i-1] = qry[i].val;
    }
    sort(arr,arr+n);
    unordered_map<int, int> mp;
    int val=0;
    for(int i=0; i<n; i++){
        if(mp.find(arr[i])==mp.end())
            mp[arr[i]] = ++val;
    }
    for(int i=1; i<=n; i++){
        if(qry[i].ch=='I'){
            update(1,1,val,mp[ qry[i].val ],1,i);
        }
        else if(qry[i].ch=='C'){/// count smaller than X
            cout<<cquery(1,1,val,1,mp[qry[i].val]-1)<<endl;
        }
        else if(qry[i].ch=='K'){/// find kth element
            if(qry[i].val>tree[1])
                cout<<"invalid"<<endl;
            else{
                cout<<kquery(1,1,val,qry[i].val)<<endl;
            }
        }
        else{
            update(1,1,val,mp[ qry[i].val ],0,i);
        }
    }
    return 0;
}