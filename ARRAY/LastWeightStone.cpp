//LeetCode:1046
#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        priority_queue<int> p(stones.begin(),stones.end());
        while(p.size()>1)
        {
            int y=p.top();
            p.pop();
            int x=p.top();
             p.pop();
            if(y!=x)
                p.push(y-x);
        }
        return p.empty() ? 0 : p.top();
    }
};