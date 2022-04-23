//LeetCode:705
#include<bits/stdc++.h>
using namespace std;
class MyHashSet {
public:
    bool a[1000001];
    MyHashSet() {
        for(int i=0;i<1000001;i++)
            a[i]=false;
    }
    
    void add(int key) {
        a[key]=true;
    }
    
    void remove(int key) {
        a[key]=false;
    }
    
    bool contains(int key) {
        return a[key]==true;
    }
};

/**
 * Your MyHashSet object will be instantiated and called as such:
 * MyHashSet* obj = new MyHashSet();
 * obj->add(key);
 * obj->remove(key);
 * bool param_3 = obj->contains(key);
 */