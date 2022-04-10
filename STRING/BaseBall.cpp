//LeetCode:682
#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int calPoints(vector<string>& ops) {
        vector<int> record;
        int size=0;
        for(auto i:ops)
        {
            if(i=="+")
            {
                record.push_back(record[size-1]+record[size-2]);
                size++;
            }
            else if(i=="D")
            {
                record.push_back(2*record[size-1]);
                size++;
            }
            else if(i=="C")
            {
                size--;
                record.pop_back();
            }
            else
            {
                size++;
                record.push_back(stoi(i));
            }
            
        }
          int sum=0;
            for(int i=0;i<size;i++)
            {
                sum=sum+record[i];
            }
        return sum;

        
    }
};