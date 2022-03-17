//Score of Parentheses...LeetCode:856 
#include<bits/stdc++.h>

using namespace std;

int scoreOfParentheses(string s) {
        stack<int> st;
        for(auto i: s)
        {
            int val=0;
            if(i=='(') st.push(0);
            else
            {
                while(st.top()!= 0) 
                {
                    val+=st.top();
                    st.pop();
                }
                val=max(2*val,1);
                st.pop();
                st.push(val);
            }
        }
        int sum=0;
        while(!st.empty())
        {
            sum+=st.top();
            st.pop();
        }
        return sum;
        
        
    }
int main()
{
    //int n;
    //cin>>n;
    string s;
    getline(cin,s);
    int res= scoreOfParentheses(s);
     cout<<res;
    return 0;
}                