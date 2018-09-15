#include<bits/stdc++.h>
using namespace std;
#define mx 100002
int tree[mx*16] = {0}, lazy[mx*16] = {0},arr[mx*4];
struct str
{
    int x;
    int y;
}in[mx], qr[mx];
void update(int pos, int b, int e, int i, int j)
{
    int m = (b+e)/2;
    int l = pos*2;
    int r = l+1;
    if(lazy[pos]!=0){
        tree[pos]+=lazy[pos];
        if(b!=e){
            lazy[l]+=lazy[pos];
            lazy[r]+=lazy[pos];
        }
        lazy[pos] = 0;
    }
    if(b>e || b>j || e<i) return;
    if(b>=i && e<=j){
        tree[pos]++;
        if(b!=e){
            lazy[l]+=1;
            lazy[r]+=1;
        }
        return;
    }
    update(l,b,m,i,j);
    update(r,m+1,e,i,j);
    tree[pos] = max(tree[l],tree[r]);
}
int query(int pos, int b, int e, int i, int j)
{
    int m = (b+e)/2;
    int l = pos*2;
    int r = l+1;
    if(lazy[pos]!=0){
        tree[pos]+=lazy[pos];
        if(b!=e){
            lazy[l]+=lazy[pos];
            lazy[r]+=lazy[pos];
        }
        lazy[pos] = 0;
    }
    if(b>e || b>j || e<i) return 0;
    if(b>=i && e<=j){
        return tree[pos];
    }
    return max(query(l,b,m,i,j),query(r,m+1,e,i,j));
}
int main()
{
    int n,q,a,b;
    scanf("%d", &n);
    int ind = 0,val=0;
    for(int i=1; i<=n; i++){
        scanf("%d%d", &a, &b);
        arr[ind++]  = a;
        arr[ind++] = b;
        in[i].x = a;
        in[i].y = b;
    }
    scanf("%d", &q);
    for(int i=1; i<=q; i++){
        scanf("%d%d", &a, &b);
        arr[ind++]  = a;
        arr[ind++] = b;
        qr[i].x = a;
        qr[i].y = b;
    }
    sort(arr,arr+ind);
    unordered_map<int, int> mp;
    for(int i=0; i<ind; i++) if(mp.find(arr[i])==mp.end()) mp[arr[i]] = ++val;
    for(int i=1; i<=n; i++){
        a = mp[in[i].x];
        b = mp[in[i].y];
        update(1,1,val,a,b);
    }
    for(int i=1; i<=q; i++){
        a = mp[qr[i].x];
        b = mp[qr[i].y];
        printf("%d\n",query(1,1,val,a,b));
    }
    return 0;
}