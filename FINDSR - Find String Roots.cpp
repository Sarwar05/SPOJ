#include<bits/stdc++.h>
using namespace std;
char strrr[100005];
int main()
{
    char c;
    while(scanf("%s",strrr)){
        if(strcmp(strrr,"*")==0)
            break;
        string s(strrr);
        int len = s.size();
        int ans = len;
        for(int j=1; j<=len && ans == len; j++){
            string str = "";
            if(len%j !=0 ) continue;
            for(int i=0; i<j; i++){
                c = s[i];
                str+=c;
            }
            int count = 0;
            int a = len/j;
            for(int i=0; i<len; i+=j){
                size_t found = s.find(str,i);
                if(found == i){
                    count++;
                }
                else
                    break;
            }
            if(count == a && count != 1)
                ans = j;
        }
        printf("%d\n",len/ans);
    }
 
    return 0;
}