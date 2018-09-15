#include<bits/stdc++.h>
using namespace std;
#define mx 1002
#define pii pair<int, int>
int arr[mx],tree[mx*4],ind[mx*4];
char str[mx*2];
void build(int pos, int b, int e)
{
    if(b>e) return;
    if(b==e){
        tree[pos] =  arr[b];
        ind[pos] = b;
        return;
    }
    int m = (b+e)/2;
    int l = pos*2;
    int r = l+1;
    build(l,b,m);
    build(r,m+1,e);
    if(tree[l]<tree[r]){
        tree[pos] = tree[l];
        ind[pos] = ind[l];
    }
    else{
        tree[pos] = tree[r];
        ind[pos] = ind[r];
    }
}
pii query(int pos, int b, int e, int i, int j)
{
    if(b>e||b>j || e<i) return make_pair(-1, -1);
    if(b>=i && e<=j){
        return make_pair(tree[pos], ind[pos]);
    }
    int m = (b+e)/2;
    int l = pos*2;
    int r = l+1;
    pii p1 = query(l,b,m,i,j);
    pii p2 = query(r,m+1,e,i,j);
    if(p1.first==-1) return p2;
    if(p2.first==-1) return p1;
    if(p1.first<p2.first) return p1;
    else return p2;
}
int solve(int b, int e, int m)
{
    if(b>e) return 0;
    if(b==e) return arr[b];
    else{
        pii r = query(1,1,m,b,e);
        int h = r.first;
        int idx = r.second;
        int r1 = (e-b+1)*h;
        int r2 = solve(b,idx-1,m);
        int r3 = solve(idx+1,e,m);
        return max(r1,max(r2,r3));
    }
}
int histogram(int m)
{
    build(1,1,m);
    return solve(1,m,m);
}
int main()
{
    int tc,n,m,a;
    char ch;
    scanf("%d",&tc);
    while(tc--){
        scanf("%d%d",&n,&m);getchar();
        memset(arr,0,sizeof arr);
        int ans = 0;
        for(int i=1; i<=n; i++){
            gets(str);
            for(int j=0; j<m; j++){
                ch = str[j*2];
                if(ch=='F') a = 1;
                else a = 0;
                if(a==0) arr[j+1] = 0;
                else arr[j+1] += a;
            }
            ans = max(ans,histogram(m));
        }
        printf("%d\n", ans*3);
    }
    return 0;
}