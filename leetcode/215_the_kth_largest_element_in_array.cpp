#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

/**
 * @brief 
 * 排序输出 
 * 库函数排序
 * 其他排序方法 手动排序
 * 选择排序 冒泡排序 插入排序
 * 
 */
class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        //sort(nums.begin(),nums.end());
        //select_sort(nums);
        //bubble_sort(nums);
        insert_sort(nums);
        return nums[nums.size()-k];
    }

    void select_sort(vector<int>& nums){
        //选择排序
        if(nums.size()<2){
            return ;
        }
        for(int i=0;i<nums.size();i++){
            //最小值下标
            int min_index =i;
            //第一层循环 选择i 到n-1范围的最小值 放到第i个位置上
            for(int j=i+1;j<nums.size();j++){
                //第二层循环 找到i到n-1范围的最小值
                min_index = nums[j]<nums[min_index] ? j: min_index;
            }
            swap(nums,i,min_index);
        }
    }

    void bubble_sort(vector<int>& nums){
        if(nums.size()<2)
        return;
        for(int i=nums.size()-1;i>0;i--){
            //每轮最大值冒泡 共size-1轮
            for(int j=0;j<i;j++){
                //从前往后 相邻两个数 大数放右边
                if(nums[j]>nums[j+1]){
                    swap(nums,j,j+1);
                }
                
            }
        }
    }

    void insert_sort(vector<int>& nums){
        
        int length = nums.size();
        if(length<2)
        return;
        for(int i=1;i<length;i++){
            //第一个循环 0-i 有序
            for(int j=i-1;j>=0&&nums[j]>nums[j+1];j--){
                swap(nums, j, j+1);
            }
        }
    }

    void swap(vector<int>&nums,int i,int j){
        int tem=0;
        tem= nums[i];
        nums[i]=nums[j];
        nums[j]=tem;
    }
};

int main(){
    vector<int> v{3,2,1,5,6,4};
    int k=2;
    Solution s;
    cout<<s.findKthLargest(v,k)<<endl;
}
