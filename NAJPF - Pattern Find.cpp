#include<bits/stdc++.h>
using namespace std;
vector<int> prefix(string& str)
{
    int n = str.size();
    vector<int> pi(n,0);
    for(int i=1; i<n; i++){
        int j = pi[i-1];
        while(j>0 && str[i]!=str[j])
            j = pi[j-1];
        if(str[i]==str[j]) j++;
        pi[i] = j;
    }
    return pi;
}
int main()
{
    int tc;
    scanf("%d",&tc);
    string s,t;
    while(tc--){
        cin>>s>>t;
        int n = t.size();
        s = (t+"#"+s);
        vector<int> pref = prefix(s);
        vector<int> ans;
        for(int i=n+1; i<s.size(); i++){
            if(pref[i]==t.size())
                ans.push_back(i-2*n+1);
        }
        int sz = ans.size();
        if(sz==0)printf("Not Found\n");
        else{
            printf("%d\n", sz);
            for(int i=0; i<sz; i++){
                printf("%d",ans[i]);
                if(i==sz-1) printf("\n");
                else printf(" ");
            }
        }
        if(tc) printf("\n");
    }
}
