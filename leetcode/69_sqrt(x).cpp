#include <math.h>
#include<iostream>
using namespace std;
/**
 * @brief sf
 * 牛顿迭代法
 * 需注意 判断的时候 不要x*x  当输入较大时候会溢出
 * 循环条件 注意是 大于误差时循环 不是小于
 * 
 */
class Solution {
public:
    int mySqrt(int x) {
        float wucah = 1e-7;
        double a=x;
        double tem_x=a;
        while(fabs(tem_x-a/tem_x)>wucah){
            tem_x=0.5*(a/tem_x+tem_x); //
        }
        int result=tem_x;
        return result;


    }
};

int main(){
    int x=2147395599;
    Solution s;
    cout<<s.mySqrt(x);
}