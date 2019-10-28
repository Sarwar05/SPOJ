#include<bits/stdc++.h>
#define mx 1002
using namespace std;
char str[mx];
int pi[mx];
int main()
{
    int tc;
    scanf("%d",&tc);
    while(tc--){
        scanf("%s",str);
        int len = strlen(str);
        int ans = 0, k;
        for(int start = 0; start<len; start++){
            pi[start] = 0, k = 0;
            for(int i = 1; i<len-start; i++){
                int j = pi[i+start-1];
                while(j>0 && str[i+start]!=str[j+start])
                    j = pi[j+start-1];
                if(str[i+start]==str[j+start]) j++;
                pi[i+start] = j;
                k = max(k,j);
            }
            ans+=( len-start-k );
        }
        printf("%d\n", ans);
    }
}
