//LeetCode:17
#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<string> ans;
    void printKeypad(int num, string output, string options[]){
    if(num==0){
    ans.push_back(output);
        return;
    }
    int n1=num%10;  //last digit
    string s1=options[n1];
    for(int i=0;i<s1.length();i++){
        printKeypad(num/10, s1[i]+output, options);
    }
}
    vector<string> letterCombinations(string digits) {
        // vector<string> temp;
        // if(digits.size()==0)
        // {
        //     return temp;
        // }
    string output="";
    string options[]={"","","abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
        int num;
        if(digits=="")
            {
            // num=0;
            return ans;
        }
        else
         num=stoi(digits);
        
          printKeypad(num, output, options);
      return ans;
    }
};