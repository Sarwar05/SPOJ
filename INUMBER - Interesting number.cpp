#include<bits/stdc++.h>
using namespace std;
bool vis[1002][1002];
struct Node
{
    int mod;
    int sod;
    string num;
    Node(int _mod, int _sod, string _num)
    {
        mod = _mod;
        sod = _sod;
        num = _num;
    }
};
int main()
{
    ios_base::sync_with_stdio(0);
    int n,tc;
    cin>>tc;
    while(tc--){
        memset(vis,false,sizeof vis);
        cin>>n;
        queue<Node>q;
        q.push(Node(0,0,""));
        vis[0][0] = true;
        while(1){
            int mod = q.front().mod;
            int sod = q.front().sod;
            string num = q.front().num;
            q.pop();
            if(mod==0 && sod==n){
                cout<<num<<endl;
                break;
            }
            int st = (sod==0)? 1 : 0;
            char ch;
            if(st==0) ch = '0';
            else ch = '1';
            for(int i=st; i<=9; i++, ch++){
                int xmod = ((mod*10) + i)%n;
                int xsod = sod+i;
                if(xsod<=n && !vis[xmod][xsod]){
                    vis[xmod][xsod] = true;
                    q.push(Node(xmod, xsod, num+ch));
                }
            }
        }
    }
}
