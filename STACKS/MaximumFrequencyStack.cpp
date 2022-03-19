//Design a stack-like data structure to push elements 
// to the stack and pop the most frequent element from the stack.LeetCode:895
#include<bits/stdc++.h>

using namespace std;

class FreqStack {
public:
    map<int,int> freqmap;
    map<int, stack<int> > freqstack;
    int maxfreq=0;
    FreqStack() {
        
    }
    
    void push(int val) {
        int freq= freqmap[val]+1;
        freqmap[val]=freq;
        
        if(freq>maxfreq)
            maxfreq=freq;
        
        freqstack[freq].push(val);
        
    }
    
    int pop() {
         int top = freqstack[maxfreq].top();
         freqstack[maxfreq].pop();
        
        --freqmap[top];
        
        if(freqstack[maxfreq].size()==0)
            --maxfreq;
        return top;
        
    }
};
