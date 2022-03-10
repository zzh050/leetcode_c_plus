#include <vector>
using namespace std;
/**
 * @brief 
 * 使用异或的方法
 * 第一次全部异或得到 c=a^b
 * 然后再遍历一次 单独和c 异或 结果如果存在在数组nums中 说明nums[i] 与 nums[i]^c 为要找的两个数
 * 
 */
class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        int length = nums.size();
        int ab = 0;
        vector<int> v;
        for(int i=0;i<length;i++){
            ab ^= nums[i];
        }
        int num=0;
        for(int i=0;i<length;i++){
            num = ab^nums[i];
            if(getnum(nums,num)==true){
                v.push_back(num);
                v.push_back(nums[i]);
                break;
            }
        }

        return v;

    }
    bool getnum(vector<int>& nums,int num){
        bool flag=false;
        for(int i=0;i<nums.size();i++){
            if(num==nums[i]){
                flag=true;
                break;
            }
        }
        return flag;
    }
};