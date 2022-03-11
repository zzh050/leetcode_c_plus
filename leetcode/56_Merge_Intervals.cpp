#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

/**
 * @brief 
 * sort 用法 可以对 vector里面的vector排序 
 * 
 * 
 */
class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        if (intervals.size() == 0) {
            return {};
        }
        //排序 对vector里的vector排序 按左端点
        sort(intervals.begin(), intervals.end());
        vector<vector<int>> merged;
        for (int i = 0; i < intervals.size(); ++i) {
            int L = intervals[i][0], R = intervals[i][1];
            if (!merged.size() || merged.back()[1] < L) {
                //如果merged为空或者当前指向的vector的左端数字大于merged末尾的要合并的vector最右端 说明没有公共部分
                merged.push_back({L, R});
            }
            else {
                //否则合并 此时如果当前vector的右端大于要合并的vector的右端  合并 
                merged.back()[1] = max(merged.back()[1], R);
            }
        }
        return merged;
    }
};

int main(){

    //vector<vector<int>> v{{1,3},{2,6},{8,10},{15,18}};
    vector<vector<int>> v{{1,4},{1,4}};
    Solution s;
    vector<vector<int>> result;
    result=s.merge(v);
    int length = result.size();
    for(int i=0;i<length;i++){
        for(int j=0;j<2;j++){
            cout << result[i][j] << endl;
        }
        //cout<<"***"<<endl;
    }

}