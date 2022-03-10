#include<stdio.h>
#include<vector>
#include<iostream>
using namespace std;
/***
 * 滑动窗口？ 动态规划
 * 右边界  左边界 
 * f(i) 代表以第 ii 个数结尾的「连续子数组的最大和」
 * f(i) = max{f(i-1)+nums[i],nums[i]}
 * 用一个pre维护f(i-1)的值 
 * pre = max(pre+nums[i],nums[i])
 * 这里状态的定义不是题目中的问题的定义，不能直接将最后一个状态返回回去；

这里状态的定义不是题目中的问题的定义，不能直接将最后一个状态返回回去；

这里状态的定义不是题目中的问题的定义，不能直接将最后一个状态返回回去。

作者：liweiwei1419
链接：https://leetcode-cn.com/problems/maximum-subarray/solution/dong-tai-gui-hua-fen-zhi-fa-python-dai-ma-java-dai/
来源：力扣（LeetCode）
著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。
 * */
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int length = nums.size();
        int result = nums[0];
        int pre = 0;
        for(int i=0;i<length;i++)
        {   
            pre = getMAX(pre+nums[i],nums[i]);//这里返回的是f(i)
            result = getMAX(result,pre); //题目中要求的最大的f(i)
        }
        return result;
    }
    int getMAX(int a1,int a2){
        int max = a1;
        if(a1>a2)
        return a1;
        else return a2;
    }
};
int main(){
    vector<int> v{1,2,5,-2,6,7}; // 19
    vector<int> k{1,-1,2,-3,5}; //5
    vector<int> t{-2,1,-3,4,-1,2,1,-5,4};
    Solution s;
    int result = s.maxSubArray(t);
    cout<<result<<endl;
}

