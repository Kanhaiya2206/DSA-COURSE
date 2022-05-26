//LeetCode:191
#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int hammingWeight(uint32_t n) {
        int count=0;
        while(n>0)
        {
            n = n & (n-1);
            count++;
        }
        return count;
    }
};
// Making rightmost 1 to 0.
//Find n-1 by making rightmost 1 of n to 0 & after that make all zeroes to 1.
//Do this process until n becomes 0 and increse the count.