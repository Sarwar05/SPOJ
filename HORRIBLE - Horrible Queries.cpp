#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define mx 100005
ll tree[mx*4], lazy[mx*4];
void update(int pos, int b, int e, int i, int j, ll val)
{
    //cout<<"call for "<<b<<" "<<e<<endl;
    if(b>e) return;
    int mid = (b+e)/2;
    int left = pos*2;
    int right = left + 1;
    if(lazy[pos] !=0){
        tree[pos]+=(lazy[pos] * (e-b+1));
        if(b!=e){
            lazy[left] += lazy[pos];
            lazy[right] += lazy[pos];
        }
        lazy[pos] = 0;
    }
    if(i>e || j<b) return;
    if(b>=i && e<=j){
        tree[pos]+=(val * (e-b+1));
        if(b!= e){
            lazy[left] += val;
            lazy[right] += val;
        }
        return;
    }
    update(left,b, mid, i, j, val);
    update(right, mid+1, e, i, j, val);
    tree[pos] = tree[left] + tree[right];
    //cout<<"at pos "<<pos<<" "<<tree[pos]<<endl;
 
}
ll query(int pos, int b, int e, int i, int j)
{
    if(b>e) return 0;
    int mid = (b+e)/2;
    int left = pos*2;
    int right = left + 1;
    if(lazy[pos] != 0){
        tree[pos] += (lazy[pos] * (e-b+1));
        if(b!= e){
            lazy[left] += lazy[pos];
            lazy[right]+=lazy[pos];
        }
        lazy[pos] = 0;
    }
    if(i>e || j<b) return 0;
    if(b>=i && e<=j) return tree[pos];
    ll q1 = query(left, b, mid, i, j);
    ll q2 = query(right, mid+1,e,  i, j);
    return q1 + q2;
}
int main()
{
    int tc,n,c,p,q,v,a;
    scanf("%d",&tc);
    while(tc--){
        scanf("%d%d", &n,&c);
        memset(tree, 0, sizeof tree);
        memset(lazy, 0, sizeof lazy);
        while(c--){
            scanf("%d", &a);
            if(a==0){
                scanf("%d%d%d", &p, &q, &v);
                update(1, 1, n, p, q, v);
            }
            else{
                scanf("%d%d", &p, &q);
                printf("%lld\n",query(1, 1, n, p, q) );
            }
            //for(int i=1; i<=30; i++) cout<<" "<<tree[i]; cout<<endl;
            //cout<<"top = "<<query(1,1,n,1,n)<<endl;
        }
    }
 
    return 0;
}