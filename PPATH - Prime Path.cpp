#include<bits/stdc++.h>
using namespace std;
#define mx 10005
int arr[mx] = {0};
void sieve()
{
    arr[0] = 1;
    arr[1] = 1;
    for(int i=4; i<mx; i+=2) arr[i] = 1;
    for(int i=3; i<mx; i+=2){
        if(arr[i] == 0){
            for(int j = i*i; j<mx; j+=i){
                arr[j] = 1;
            }
        }
    }
}
int toInt(int* num)
{
    int ret = 0;
    for(int i=0; i<4; i++){
        ret = ret*10 + num[i];
    }
    return ret;
}
vector<int> gen(int s)
{
    int a[5];
    a[0] = s/1000;s%=1000;
    a[1] = s/100;s%=100;
    a[2] = s/10;s%=10;
    a[3] = s;
    int x = a[0],y;
    vector<int> ret;
    for(int i=1; i<=9; i++){
        if(i==x) continue;
        a[0] = i;
        y = toInt(a);
        if(arr[y]==0)
            ret.push_back(y);
    }
    a[0] = x;
    x = a[1];
    for(int i=0; i<=9; i++){
        if(i==x) continue;
        a[1] = i;
        y = toInt(a);
        if(arr[y]==0)
            ret.push_back(y);
    }
    a[1] = x;
    x = a[2];
    for(int i=0; i<=9; i++){
        if(i==x) continue;
        a[2] = i;
        y = toInt(a);
        if(arr[y]==0)
            ret.push_back(y);
    }
    a[2] = x;
    x = a[3];
    for(int i=0; i<=9; i++){
        if(i==x) continue;
        a[3] = i;
        y = toInt(a);
        if(arr[y]==0)
            ret.push_back(y);
    }
    return ret;
}
int bfs(int s, int t)
{
    if(s==t) return 0;
    map<int, int> vis;
    vis[s] = 1;
    queue<pair<int, int> >q;
    q.push(make_pair(s,0));
    while(!q.empty()){
        int a = q.front().first;
        int b = q.front().second;
        q.pop();
        vector<int> v = gen(a);
        for(int i=0; i<v.size(); i++){
            if(vis.find(v[i])==vis.end()){
                if(v[i]==t) return b+1;
                vis[v[i]] = 1;
                q.push(make_pair(v[i],b+1));
            }
        }
    }
    return -1;
}
int main()
{
    sieve();
    int n,a,b;
    scanf("%d",&n);
    while(n--){
        scanf("%d%d",&a,&b);
        int ans = bfs(a,b);
        if(ans==-1) printf("Impossible\n");
        else printf("%d\n",ans);
    }
    return 0;
}