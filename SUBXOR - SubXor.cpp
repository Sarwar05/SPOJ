#include<bits/stdc++.h>
using namespace std;
#define mx 100005
int arr[mx];
struct Node
{
    int left,right;
    Node* next[2];
    Node()
    {
        left = right = 0;
        next[0] = next[1] = NULL;
    }
}* root;
void del(Node* curr)
{
    if(curr->next[0]!= NULL)
        del(curr->next[0]);
    if(curr->next[1]!= NULL)
        del(curr->next[1]);
    delete(curr);
}
void insert(int val)
{
    Node* curr = root;
    for(int i=22; i>=0; i--){
        bool bit = val &(1<<i);
        if(curr->next[bit]==NULL)
            curr->next[bit] = new Node();
        if(bit==0) curr->left++;
        else curr->right++;
        curr = curr->next[bit];
    }
}
long long query(int pre, int k, Node* curr, int pos)
{
    if(pos<0 || curr == NULL) return 0;
    bool bit1 = pre & (1<<pos);
    bool bit2 = k & (1<<pos);
    long long ret = 0;
    if(bit1==0 && bit2==0){
        ret+=query(pre,k,curr->next[0],pos-1);
    }
    if(bit1==0 && bit2==1){
        ret+=query(pre,k,curr->next[1],pos-1);
        ret+=curr->left;
    }
    if(bit1==1 && bit2==0){
        ret+=query(pre,k,curr->next[1],pos-1);
    }
    if(bit1==1 && bit2==1){
        ret+=curr->right;
        ret+=query(pre,k,curr->next[0],pos-1);
    }
    return ret;
}
int main()
{
    int tc,n,a,k,pre;
    long long ans;
    scanf("%d",&tc);
    while(tc--){
        scanf("%d%d",&n,&k);
        root = new Node();
        ans=0,pre=0;
        for(int i=0; i<n; i++){
            scanf("%d",&arr[i]);
            pre^=arr[i];
            ans+=query(pre,k,root,22);
            insert(pre);
        }
        ans+=query(0,k,root,22);
        printf("%lld\n",ans);
        del(root);
    }
}
 