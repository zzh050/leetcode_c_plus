#include <vector>
#include <algorithm>
using namespace std;
class Solution {
public:
    int maximumProduct(vector<int>& nums) {
        //先排序
        sort(nums.begin(),nums.end());
        int length = nums.size();
        if(length==3)
        return nums[0]*nums[1]*nums[2];
        //4个以上的数  三个最大正数乘积    1个最大正数两个最小负数    两个正数1个负数<0 三个负数<0 
        if(nums[length-3]>0||nums[1]<0){
            return max(nums[length-1]*nums[length-2]*nums[length-3],nums[0]*nums[1]*nums[length-1]);
        }else if(nums[length-3]==0){
            return nums[0]*nums[1]*nums[length-1]; //2个- 1个+
        }else{
            return nums[0]*nums[1]*nums[length-1];
        }
    }
};