#include<bits/stdc++.h>
#define mx 1002
using namespace std;
int prefix(string str)
{
    int len = str.size();
    vector<int> pi(len);
    pi[0] = 0;int k = 0;
    for(int i = 1; i<len; i++){
        int j = pi[i-1];
        while(j>0 && str[i]!=str[j])
            j = pi[j-1];
        if(str[i]==str[j]) j++;
        pi[i] = j;
        k = max(k,j);
    }
    return len-k;
}
int main()
{
    int tc;
    scanf("%d",&tc);
    while(tc--){
        string str, tem = "";
        cin>>str;
        int len = str.size();
        int ans = 0;
        for(int i = len-1; i>=0; i--){
            tem = str[i] + tem;
            ans+=prefix(tem);
        }
        printf("%d\n", ans);
    }
}
