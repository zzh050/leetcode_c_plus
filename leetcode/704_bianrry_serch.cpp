#include<vector>
using namespace std;
class Solution {
public:
    int search(vector<int>& nums, int target) {
        
        int length = nums.size();
        
        int low=0;
        int high = length-1;
        int index=(low+high)/2;
        while(low<=high){
            if(nums[index]==target)
            return index;
            else if(nums[index]<target){
                low = index+1;
                index=(low+high)/2;
            }
            else{
                high=index-1;
                index=(low+high)/2;
            }
        }
        return -1;
    }
};