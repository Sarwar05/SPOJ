
#include<bits/stdc++.h>
using namespace std;
int in[26],out[26], par[26];
char str[1005];
int findPar(int r)
{
    if(par[r]==r) return r;
    else return par[r] = findPar(par[r]);
}
int main()
{
    int tc,n;
    scanf("%d",&tc);
    while(tc--){
        scanf("%d",&n);
        for(int i=0; i<26; i++){
            in[i] = out[i] = 0;
            par[i] = i;
        }
        while(n--){
            scanf("%s",str);
            int len = strlen(str);
            int u = str[0]-'a';
            int v = str[len-1]-'a';
            in[v]++;
            out[u]++;
            u = findPar(u);
            v = findPar(v);
            if(u!=v) par[u] = v;
        }
        set<int> st;
        for(int i=0; i<26; i++) if(in[i] || out[i]) st.insert(findPar(i));
        int single = (st.size()==1) ? 1 : 0;
        int pos1 = 0, mns1 = 0, other = 0;
        if(single){
            for(int i=0;i<26; i++){
                if(in[i]==0 && out[i]==0) continue;
                if(in[i]-out[i]==1) pos1++;
                else if(in[i]-out[i]==-1) mns1++;
                else if(in[i]-out[i]==0);
                else other++;

            }
        }
        if(single && other==0 && ((pos1==0&&mns1==0)||(pos1==1&&mns1==1))) printf("Ordering is possible.\n");
        else printf("The door cannot be opened.\n");
    }
}
