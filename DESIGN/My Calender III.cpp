//LeetCode:732
#include<bits/stdc++.h>
using namespace std;
class MyCalendarThree {
public:
    map<int,int> mp;
    int maxcount =0;
    MyCalendarThree() {
        
    }
    
    int book(int start, int end) {
        mp[start]++;
        mp[end]--;
        int count =0;
        for(auto i=mp.begin();i != mp.end();i++)
        {
            count += i->second;
            maxcount = max(count,maxcount);
        }
        return maxcount;
    }
};
