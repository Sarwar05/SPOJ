#include<bits/stdc++.h>
using namespace std;
#define mx 100005
#define ll long long
#define neg -1666666
ll tree[mx*4];
int arr[mx],lazup[mx*4],lazad[mx*4],lupid[mx*4],ladid[mx*4],sum[mx*4];
void build(int pos, int b, int e)
{
    if(b>e) return;
    if(b==e){
        tree[pos] = arr[b]*arr[e];
        sum[pos] = arr[b];
        return;
    }
    int m = (b+e)/2;
    int l = pos*2;
    int r = l+1;
    build(l,b,m);
    build(r,m+1,e);
    tree[pos] = tree[l] + tree[r];
    sum[pos] = sum[l] + sum[r];
}
void relaxadd(int pos, int b, int e)
{
    if(lazad[pos]==neg) return;
    ll val = lazad[pos];
    tree[pos] = (e-b+1)*val*val + 2*val*sum[pos] + tree[pos];
    sum[pos] = sum[pos] + val*(e-b+1);
    if(b!=e){
        if(lazad[pos*2]==neg) lazad[pos*2] = 0;
        if(lazad[pos*2+1]==neg) lazad[pos*2+1] = 0;
        lazad[pos*2] += lazad[pos];
        ladid[pos*2] = ladid[pos];
        lazad[pos*2+1] += lazad[pos];
        ladid[pos*2+1] = ladid[pos];
    }
    lazad[pos] = neg;
}
void relaxup(int pos, int b, int e)
{
    if(lazup[pos]==neg) return;
    ll val = lazup[pos];
    tree[pos] = (e-b+1)*val*val;
    sum[pos] = val*(e-b+1);
    if(b!=e){
        lazup[pos*2] = lazup[pos];
        lupid[pos*2] = lupid[pos];
        lazup[pos*2+1] = lazup[pos];
        lupid[pos*2+1] = lupid[pos];
        lazad[pos*2] = neg;
        lazad[pos*2+1] = neg;
    }
    lazup[pos] = neg;
}
void upadd(int pos, int b, int e, int i, int j, ll val, int idx)
{
 
    if(lupid[pos]<ladid[pos]){
        relaxup(pos,b,e);
        relaxadd(pos,b,e);
    }
    else{
        relaxadd(pos,b,e);
        relaxup(pos,b,e);
    }
    if(b>e || b>j || e<i) return;
    int m = (b+e)/2;
    int l = pos*2;
    int r = l+1;
    if(b>=i && e<=j){
        tree[pos] = (e-b+1)*val*val + 2*val*sum[pos] + tree[pos];
        sum[pos] = sum[pos] + val*(e-b+1);
        if(b!=e){
            if(lazad[l]==neg) lazad[l] = 0;
            if(lazad[r]==neg) lazad[r] = 0;
            lazad[l] += val;
            ladid[l] = idx;
            lazad[r] += val;
            ladid[r] = idx;
        }
        return;
    }
    upadd(l,b,m,i,j,val,idx);
    upadd(r,m+1,e,i,j,val,idx);
    tree[pos] = tree[l] + tree[r];
    sum[pos] = sum[l] + sum[r];
}
void upset(int pos, int b, int e, int i, int j, ll val, int idx)
{
    if(lupid[pos]<ladid[pos]){
        relaxup(pos,b,e);
        relaxadd(pos,b,e);
    }
    else{
        relaxadd(pos,b,e);
        relaxup(pos,b,e);
    }
    if(b>e || b>j || e<i) return;
    int m = (b+e)/2;
    int l = pos*2;
    int r = l+1;
    if(b>=i && e<=j){
        tree[pos] = (e-b+1)*val*val;
        sum[pos] = val*(e-b+1);
        if(b!=e){
            lazup[l] = val;
            lupid[l] = idx;
            lazup[r] = val;
            lupid[r] = idx;
            lazad[l] = neg;
            lazad[r] = neg;
        }
        return;
    }
    upset(l,b,m,i,j,val,idx);
    upset(r,m+1,e,i,j,val,idx);
    tree[pos] = tree[l] + tree[r];
    sum[pos] = sum[l] + sum[r];
}
ll query(int pos, int b, int e, int i, int j)
{
    if(lupid[pos]<ladid[pos]){
        relaxup(pos,b,e);
        relaxadd(pos,b,e);
    }
    else{
        relaxadd(pos,b,e);
        relaxup(pos,b,e);
    }
    if(b>e || b>j || e<i) return 0;
    int m = (b+e)/2;
    int l = pos*2;
    int r = l+1;
    if(b>=i && e<=j){
        return tree[pos];
    }
    return query(l,b,m,i,j) + query(r,m+1,e,i,j);
}
int main()
{
    int tc,cs=1;int n,q,a,b,c;
    scanf("%d",&tc);
    while(tc--){
        for(int i=0; i<mx*4; i++){
            sum[i] = tree[i] = 0;
            lazup[i] = lazad[i] = neg;
            lupid[i] = ladid[i] = -1;
        }
        scanf("%d%d",&n,&q);
        for(int i=1; i<=n; i++) scanf("%d",&arr[i]);
        build(1,1,n);
        printf("Case %d:\n",cs++);
        for(int id=1; id<=q; id++){
            scanf("%d",&a);
            if(a==2){
                scanf("%d%d",&b,&c);
                printf("%lld\n",query(1,1,n,b,c));
            }
            else if(a==1){
                scanf("%d%d%d",&a,&b,&c);
                upadd(1,1,n,a,b,c,id);
            }
            else{
                scanf("%d%d%d",&a,&b,&c);
                upset(1,1,n,a,b,c,id);
            }
        }
    }
    return 0;
}