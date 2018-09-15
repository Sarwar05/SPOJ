#include<bits/stdc++.h>
using namespace std;
#define mx 1003
int arr[mx];
int main()
{
    int n;
    while(scanf("%d",&n),n){
        for(int i=1; i<=n; i++) scanf("%d",&arr[i]);
        int now = 1;
        stack<int> st,tem;
        bool ans = true;
        for(int i=n; i>=1; i--) st.push(arr[i]);
        while((!st.empty() || !tem.empty()) && ans ){
            if(!st.empty() && st.top()==now){
                now++;
                st.pop();
            }
            else if(!tem.empty()&& tem.top()==now){
                now++;
                tem.pop();
            }
            else{
                if(!st.empty()) {
                    tem.push(st.top());
                    st.pop();
                }
                else{
                    ans = false;
                }
            }
        }
 
        printf("%s\n",ans ? "yes" : "no");
    }
    return 0;
}
 