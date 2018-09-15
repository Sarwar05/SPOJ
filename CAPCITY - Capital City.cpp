#include<bits/stdc++.h>
using namespace std;
#define mx 100005
int vis[mx] = {0};
vector<int> adj[mx],rev[mx];
int scc, comp[mx];
stack<int > st;
void dfs(int s)
{
    vis[s] = 1;
    for(int i=0; i<(int)adj[s].size(); i++){
        int v = adj[s][i];
        if(vis[v]==0){
            dfs(v);
        }
    }
    st.push(s);
}
void dfs2(int s)
{
    vis[s] = 0;
    for(int i=0; i<(int)rev[s].size(); i++){
        int v = rev[s][i];
        if(vis[v]==1){
            dfs2(v);
        }
    }
    comp[s] = scc;
}
int main()
{
    int n,m,a,b;
    scanf("%d%d",&n,&m);
    while(m--){
        scanf("%d%d",&a,&b);
        adj[a].push_back(b);
        rev[b].push_back(a);
    }
    for(int i=1; i<=n; i++){
        if(vis[i]==0){
            dfs(i);
        }
    }
    scc=0;
 
    while(!st.empty()){
        if(vis[st.top()]==1){
            ++scc;
            dfs2(st.top());
        }
        st.pop();
    }
    vector<int> ans;
    for(int i=1; i<=n; i++) if(comp[i]==scc) ans.push_back(i);
    sort(ans.begin(),ans.end());
    printf("%d\n",ans.size());
    printf("%d",ans[0]);
    for(int i=1; i<(int)ans.size(); i++){
        printf(" %d",ans[i]);
    }
    printf("\n");
 
    return 0;
}