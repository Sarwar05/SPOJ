#include<bits/stdc++.h>
using namespace std;
#define mx 200010
struct Node
{
    int cnt;
    int value;
};
Node tree[mx*8];
void init()
{
    for(int i=1; i<mx*8; i++){
        tree[i].cnt = 0;
        tree[i].value = 0;
    }
}
void update(int pos, int b, int e, int i, int j, int val, int put)
{
    if(b>e || b>j|| e<i) return;
    if(b>=i && e<=j){
        tree[pos].cnt+=val;
        tree[pos].value = put;
        return;
    }
    int m = (b+e)/2;
    int l = pos*2;
    int r = l+1;
    update(l,b,m,i,j,val,put);
    update(r,m+1,e,i,j,val,put);
    tree[pos].cnt = tree[l].cnt + tree[r].cnt;
}
int query(int pos, int b, int e, int i, int j)
{
    if(b>e || b>j|| e<i) return 0;
    if(b>=i && e<=j){
        return tree[pos].cnt;
    }
    int m = (b+e)/2;
    int l = pos*2;
    int r = l+1;
    return query(l,b,m,i,j) + query(r,m+1,e,i,j);
}
int findkth(int pos, int b, int e, int k)
{
    if(b==e){
        return tree[pos].value;
    }
    int m = (b+e)/2;
    int l = pos*2;
    int r = l+1;
    if(tree[l].cnt>=k){
        return findkth(l,b,m,k);
    }
    else{
        return findkth(r,m+1,e,k-tree[l].cnt);
    }
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int tc,n,a,b;
    char ch;
    cin>>tc;
    for(int cs=1; cs<=tc; cs++){
        cin>>n;
        init();
        int x=mx,y=mx+1;
        unordered_map<int, int > mp;
        cout<<"Case "<<cs<<":"<<endl;
        for(int cnt=1; cnt<=n; cnt++){
            cin>>a;
            if(a==1){
                cin>>ch>>b;
                if(ch=='B'){
                    update(1,1,400000,y,y,1,b);
                    mp[b] = y;
                    y++;
                }
                if(ch=='F'){
                    update(1,1,400000,x,x,1,b);
                    mp[b] = x;
                    x--;
                }
            }
            if(a==2){
                cin>>ch;
                if(ch=='B'){
                    update(1,1,400000,y-1,y-1,-1,0);
                    y--;
                }
                if(ch=='F'){
                    update(1,1,400000,x+1,x+1,-1,0);
                    x++;
                }
            }
            if(a==3){
                cin>>ch>>b;
                if(ch=='D'){
                    cout<<findkth(1,1,400000,b)<<endl;;
                }
                if(ch=='P'){
                    cout<<query(1,1,400000,1,mp[b])<<endl;
                }
            }
        }
    }
    return 0;
}