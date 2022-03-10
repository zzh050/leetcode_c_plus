#include <vector>
#include <iostream>
using namespace std;


/**
 * @brief 
 * 注意
 * vector pop_back()会减小 vector size 
 * 不能将vector size 放入循环条件的判断当中 会导致结果异常
 * 剪枝多余的vector元素 
 */
class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> result {};
        int row = matrix.size();
        int list = matrix[0].size();
        if(matrix.size()==0||matrix[0].size()==0)
        return result;
        if(matrix.size()==1||matrix.size()==1){
            for(int i=0;i<row;i++){
                for(int j=0;j<list;j++){
                    result.push_back(matrix[i][j]);
                }
            }
            return result;
        }
        
        
        int time_row = 0;
        int time_list = 0;
        int time =0; //循环次数 即圈数
        if(row%2==0){
            time_row = row/2;
        }else{
            time_row = row/2+1;
        }
        if(list%2==0){
            time_list = list/2;
        }else{
            time_list = list/2+1;
        }
        if(time_row<=time_list){
            time = time_row;

        }else time = time_list;

        for(int i=0;i<time;i++)
        {
            //从外圈到里圈一圈一圈遍历
            //第i行 从左往右
            for(int j=i;j<list-i;j++){
                //第i行 需要输出的个数 列数-2*第几行  第0行全输出 第1行 需要掐头去尾
                //第一个输出的元素 是  第i行 的 第 
                result.push_back(matrix[i][j]);//i是行数 j是第i行的第几个
            }
            //倒数第i列 从上往下
            for(int j=i+1;j<row-i;j++)
            {
                result.push_back(matrix[j][list-i-1]);// 行变换 列不变
            }
            //倒数第i行 从右往左
            for(int j=list-i-1-1;j>i;j--){
                result.push_back(matrix[row-i-1][j]); // 列变换 行不变 //j>=i ==
            }
            //第i列 从下往上
            for(int j=row-i-1;j>i;j--)
            {
                result.push_back(matrix[j][i]); //行变换 列不变
            }
        }
        int num = row*list; //15
        int size = result.size();
        for(int i=0;i<(size-num);i++){
            result.pop_back();
        }
        return result;
    }

};

int main(){

    vector<int> row1{2,3,4};
    vector<int> row2{5,6,7};
    vector<int> row3{8,9,10};
    vector<int> row4{11,12,13};
    vector<int> row5{14,15,16};
    vector<vector<int>> v;
    v.push_back(row1);
    v.push_back(row2);
    v.push_back(row3);
    v.push_back(row4);
    v.push_back(row5);

    Solution s;
    vector<int> result;
    result=s.spiralOrder(v);
    int length = result.size();
    for(int x: result){
        cout<<x<<endl;
    }
    
}