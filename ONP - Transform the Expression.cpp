#include<bits/stdc++.h>
using namespace std;
char str[405];
int main()
{
    int tc;
    scanf("%d",&tc);
    while(tc--){
        scanf("%s",str);
        stack<char>st;
        int len = strlen(str);
        for(int i=0; i<len; i++){
            if(str[i]=='(')
                st.push(str[i]);
            else if(str[i]==')'){
                char ch = st.top();
                st.pop();
                st.pop();
                printf("%c",ch);
            }
            else if(isalpha(str[i])) printf("%c",str[i]);
            else st.push(str[i]);
        }
        printf("\n");
    }
    return 0;
}