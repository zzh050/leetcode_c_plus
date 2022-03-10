#include<stdio.h>
#include<vector>
#include<iostream>
using namespace std;

/**
 * @brief 
 * 双指针
 * 
 * 注意边界条件 
 * 当m=0 n=1时
 * 以及当m=1 n=0时
 * 
 */
class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
         int j=0;
        int tem =0;
        //先将第二个数组的值赋进去
        if(m==0&&n==1){
            nums1[0]=nums2[0];
        }else if(m==1&&n==0){
        }
        else{
        for(int i=0;i<n;i++){
            nums1[m+i] = nums2[i];
        }
        //然后开始从第二个数组的位置开始往后循环
        for(int i=m;i<nums1.size()||j==nums1.size();){
            if(nums1[i]>=nums1[j]&&j<nums1.size())
            {
                j++;
                if(j>=i){
                    i++;
                }
            }
            else{
                tem = nums1[i];
                move_back(nums1,j,i);
                nums1[j]=tem;
                i++;
                j++;
            }
        }
        }
    }

    void move_back(vector<int>& nums1, int j,int back)
    {
        for(int i=back;i>j;i--){
            nums1[i] = nums1[i-1];
        }
    }
};

int main(){
    vector<int> nums1{-1,0,0,3,3,3,0,0,0};
    int m=6;
    vector<int> nums2{1,2,2};
    int n=3;
    Solution s;
    s.merge(nums1,m,nums2,n);
    int length = nums1.size();
    for(int i=0;i<length;i++){
        cout<<nums1[i]<<endl;
    }
}