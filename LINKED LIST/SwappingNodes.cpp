//LeetCode:1721
 
#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
struct ListNode {
      int val;
      ListNode *next;
      ListNode() : val(0), next(nullptr) {}
      ListNode(int x) : val(x), next(nullptr) {}
      ListNode(int x, ListNode *next) : val(x), next(next) {}
  };
    ListNode* swapNodes(ListNode* head, int k) {
        ListNode* last=head;
        int n=0;
        while(last)
        {
            n++;
            last=last->next;
        }
        if((2*k-1)==n) return head; //Middle Node
        
        ListNode* x=head;
        int cnt=k-1;
        while(cnt--)
        {
            x=x->next;
        }
        ListNode* y=head;
        cnt=n-k;
        while(cnt--)
        {
            y=y->next;
        }
        int temp=y->val;
        y->val=x->val;
        x->val=temp;
        
        return head;
    }
     
};