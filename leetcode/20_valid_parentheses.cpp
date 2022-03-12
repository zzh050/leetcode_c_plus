#include<stack>
#include<string>
using namespace std;

class Solution {
public:
    bool isValid(string s) {
        stack<char> sta{};
        char c;
        for(int i=0;i<s.size();i++){
            if(sta.empty())
            sta.push(s[i]);
            else if(getreverse(sta.top())==s[i]){
                sta.pop();
            }else sta.push(s[i]);
        }
        if(sta.empty())
        return true;
        else 
        return false;
    }

    char getreverse(char c){
        if(c=='(')
        return ')';
        else if(c=='{')
        return '}';
        else if('[')
        return ']';
    }
};