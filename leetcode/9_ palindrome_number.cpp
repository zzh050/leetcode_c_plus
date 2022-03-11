#include<queue>
using namespace std;
// ### 解题思路
//     通过队列存储每一位数字 然后重组 判等
//     注意 负数 和 个位为0 false （0除外）
// ### 代码

class Solution {
public:
    bool isPalindrome(int x) {
        if(x==0) 
        return true;
        if(x<0||x%10==0)
            return false;

        long long return_x = 0;
        queue<int> q;
        int tem = x;
        while(tem){
            q.push(tem%10);
            tem /=10;
        }
        int size = q.size();
        for(int i=size;i>0;i--){
            return_x += q.front()*pow(10,i-1);
            q.pop();
        }
        if(return_x==x)
            return true;
        else return false;
    }
};