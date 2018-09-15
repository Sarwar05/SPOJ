#include<bits/stdc++.h>
using namespace std;
#define mx 30005
char str[mx];
struct node
{
    int match;
    int unopen;
    int unclose;
}tree[mx*4];
node zero;
node merge(node l, node r)
{
    if(l.match == -1) return r;
    if(r.match == -1) return l;
    node ret;
    int add = min(l.unopen, r.unclose);
    ret.match = l.match + r.match + add*2;
    ret.unclose = l.unclose + r.unclose - add;
    ret.unopen = l.unopen + r.unopen - add;
    return ret;
}
void build(int pos, int b, int e)
{
    if(b>e) return;
    if(b==e){
        if(str[b]=='('){
            tree[pos].match = 0;
            tree[pos].unopen = 1;
            tree[pos].unclose = 0;
        }
        else{
            tree[pos].match = 0;
            tree[pos].unopen = 0;
            tree[pos].unclose = 1;
        }
        return;
    }
    int l = pos*2 +1;
    int r = l+1;
    int mid =(b+e)/2;
    build(l,b,mid);
    build(r,mid+1,e);
    tree[pos] = merge(tree[l], tree[r]);
}
node query(int pos, int b, int e, int i, int j)
{
    if(b>j || e<i) return zero;
    if(b>=i && e<=j) return tree[pos];
    int l = pos*2 +1;
    int r = l+1;
    int mid =(b+e)/2;
    node n1 = query(l,b,mid,i,j);
    node n2 = query(r,mid+1,e,i,j);
    return merge(n1,n2);
}
void update(int pos, int b, int e, int i, int j)
{
    if(b>e || b>j || e<i) return;
    if(b>=i && e<=j){
        if(str[b]==')'){
            tree[pos].match = 0;
            tree[pos].unopen = 1;
            tree[pos].unclose = 0;
            str[i] = '(';
        }
        else{
            tree[pos].match = 0;
            tree[pos].unopen = 0;
            tree[pos].unclose = 1;
            str[i] = ')';
        }
 
        return;
    }
    int l = pos*2 +1;
    int r = l+1;
    int mid =(b+e)/2;
    update(l,b,mid,i,j);
    update(r,mid+1,e,i,j);
    tree[pos] = merge(tree[l], tree[r]);
}
int main()
{
    zero.match = zero.unclose = zero.unopen = -1;
    int len;
    int n,a,cs=1;
    while(scanf("%d",&len)!=EOF){
        scanf("%s",str);
        build(0,0,len-1);
        scanf("%d",&n);
        printf("Test %d:\n",cs++);
        while(n--){
            scanf("%d",&a);
            if(a==0){
                printf("%s\n",tree[0].match == len ? "YES" : "NO");
            }
            else{
                update(0,0,len-1,a-1,a-1);
            }
        }
    }
    return 0;
}