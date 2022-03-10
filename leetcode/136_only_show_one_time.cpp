#include <vector>

using namespace std;

/**
 * @brief 
 * 解法1 
 * 异或
 * 解法2
 * 利用set 集合元素不能重复添加的特性 添加失败就remove set集合中的已添加的这个数 最后剩余的数就是只出现一次的数
 */
class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int length = nums.size();
        int result = 0;
        for(int i=0;i<length;i++){
            result ^=nums[i];
        }
        return result;
    }
};