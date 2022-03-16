#include<bits/stdc++.h>

using namespace std;

bool validateStackSequences(vector<int> pushed, vector<int> popped) {
        int n=pushed.size();
        stack<int> s; int j=0;
        for(int i=0;i<n;i++)
        {
            s.push(pushed[i]);
            
            while(!s.empty() && s.top()==popped[j])
            {
                s.pop();
                ++j;
            }
        }
        return s.empty();
    }
int main()
{
    int n;
    cin>>n;
    vector<int> pushed(n);
    for(int i=0;i<n;i++)
    {
      cin>>pushed[i];
    }
    vector<int> popped(n);
    for(int j=0;j<n;j++)
    {
        cin>>popped[j];
    }
    bool ans= validateStackSequences(pushed,popped);
    cout<<ans;
    return 0;
}         