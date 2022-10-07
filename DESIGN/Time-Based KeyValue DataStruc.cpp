//LeetCode:981
#include<bits/stdc++.h>
using namespace std;
class TimeMap {
public:
    unordered_map<string, unordered_map<int,string>> keyTimeMap;
    TimeMap() {
        
    }
    
    void set(string key, string value, int timestamp) {
        keyTimeMap[key][timestamp] = value;
        
    }
    
    string get(string key, int timestamp) {
        if(keyTimeMap.find(key)==keyTimeMap.end())
            return "";
        
        for(int currtime=timestamp;currtime>=1;currtime--)
        {
            if(keyTimeMap[key].find(currtime)!=keyTimeMap[key].end())
                return keyTimeMap[key][currtime];
        }
        return "";
    }
};
