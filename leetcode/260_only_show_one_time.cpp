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

    /**
 * @brief 
 * 法二
 * 先得到c=a^b
 * a不等于b 且 c不等于0
 * 所以看c中为为1的位有哪些
 * 然后将数组中与c中为1的位的数异或 得到 a或者b
 * 
 */
vector<int> singleNumber_2(vector<int>& nums) {
    int length = nums.size();
        int ab = 0;
        vector<int> v;
        for(int i=0;i<length;i++){
            ab ^= nums[i];
        }
        int rightone=0;
        if(ab==INT_MIN){
            rightone = INT_MIN; //防止溢出
        }else{
            rightone = ab&(~ab+1);//提取最右的1
        }
        int onlyOne = 0;
        for(int i=0;i<length;i++){
            if((rightone&nums[i])==0)
                onlyOne ^= nums[i];
        }
        v.push_back(onlyOne);
        v.push_back(ab^onlyOne);
        return v;
        }

    }
};

