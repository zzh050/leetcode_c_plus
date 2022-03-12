#include<set>
#include<iostream>
#include<vector>
using namespace std;
/**
 * @brief 
 * 需要注意的是拿set insert函数判断的时候 会插进去元素 所以 拿find（）判断
 * 
 */
class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        int length_1 = nums1.size();
        int length_2 = nums2.size();
        set<int> s;
        for(int i=0;i<length_1;i++){
            s.insert(nums1[i]);
        }
        set<int> v;
        
        for(int j=0;j<length_2;j++){
            if(s.find(nums2[j])!=s.end()){
                v.insert(nums2[j]);
            }
            
        }
        vector<int> r;
        set<int>::iterator it;
        it = v.begin();
        while(it!=v.end()){
            r.push_back(*it);
            it++;
        }
        return r;
    }
};

int main(){
    vector<int> nums1{4,7,9,7,6,7};
    vector<int> nums2{5,0,0,6,1,6,2,2,4};
    Solution s;
    vector<int> result;
    result = s.intersection(nums1,nums2);
    system("pause");
}