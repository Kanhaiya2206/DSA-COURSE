 //remove the minimum number of parentheses ( '(' or ')', in any positions
 //so that the resulting parentheses string is valid and return any valid string.LeetCode:1249
 #include<bits/stdc++.h>

using namespace std;

 string minRemoveToMakeValid(string s) {
        int n=s.length();
        string ans="";
        int flag=0;
        for(int i=0;i<n;i++)
        {
            if(s[i]=='(')
                ++flag;
            else if(s[i]==')')
            {
                if(flag==0)
                    s[i]='$';
                else
                    --flag;
            }
        }
        flag=0;
        for(int i=n-1;i>=0;i--)
        {
            if(s[i]==')')
                ++flag;
            else if(s[i]=='(')
            {
                if(flag==0)
                    s[i]='$';
                else
                    --flag;
            }
        }
        for(int i=0;i<n;i++)
        {
            if(s[i]!='$')
                ans.push_back(s[i]);
        }
        return ans;
        
    }
int main()
{
    //int n;
    //cin>>n;
    string s;
    getline(cin,s);
    string res= minRemoveToMakeValid(s);
     cout<<res;
    return 0;
}             