#include<vector>

using namespace std;
/**
 * @brief 
 * 先二分查找找到第一个点
 * 然后分别左右两边递归二分 左边一直往左找 右边一直往右找
 * 注意 二分查找别写错了  然后递归返回得判断一下
 * 
 * 
 * 二分查找中，寻找 \textit{leftIdx}leftIdx 即为在数组中寻找第一个大于等于 \textit{target}target 的下标，寻找 \textit{rightIdx}rightIdx 即为在数组中寻找第一个大于 \textit{target}target 的下标，然后将下标减一。

作者：LeetCode-Solution
链接：https://leetcode-cn.com/problems/find-first-and-last-position-of-element-in-sorted-array/solution/zai-pai-xu-shu-zu-zhong-cha-zhao-yuan-su-de-di-3-4/
来源：力扣（LeetCode）
著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。
 */
class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int minindex = -1;
        int maxindex = -1;
        int index = binarrySerach(nums,target,0,nums.size()-1,2);
        if(index==-1)
        return {-1,-1};
        minindex = binarrySerach(nums,target,0,index,0);
        maxindex = binarrySerach(nums,target,index,nums.size()-1,1);
        if(minindex==-1)
            minindex=index;
        if(maxindex==-1)
            maxindex=index;
        return {minindex,maxindex};
        
    }
    int binarrySerach(vector<int>& nums,int target,int left,int right,int flag){
        int index=(left+right)/2;
        while(left<=right){
            if(nums[index]==target){
                if(flag==0){
                int i=binarrySerach(nums,target,left,index-1,0);
                if(i!=-1)
                index=i; 
                return index;
                }else if(flag==1){
                    int j = binarrySerach(nums,target,index+1,right,1);
                    if(j!=-1)
                    index = j;
                    return index;
                }else {
                    return index;
                }
                
            } 
            else if(nums[index]<target){
                left = index+1;
                index=(right+left)/2;
            }else {
                right = index-1;
                index=(right+left)/2;
            }
        }
        return -1;
    }
};

int main(){
    vector<int> nums{5,7,8,8,10};
    int target = 8;
    Solution s;
    vector<int> result=s.searchRange(nums,target);
    system("pause");
}