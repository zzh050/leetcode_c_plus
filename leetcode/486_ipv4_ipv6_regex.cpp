#include <regex>
#include <string>
#include <iostream>
using namespace std;
/**
 * @brief 
 * 注意//d  /需要转义符号
 * https://blog.csdn.net/weixin_44184881/article/details/85113248
 * https://www.cnblogs.com/coolcpp/p/cpp-regex.html
 * 
 * 
 */
class Solution {
public:
    public:
    string validIPAddress(string queryIP) {
        std::regex ipv4("^((25[0-5]|2[0-4]\\d|1\\d\\d|[1-9]\\d|\\d)\\.){3}(25[0-5]|2[0-4]\\d|1\\d\\d|[1-9]\\d|\\d)$");  //0-199  100 - 199  10 - 99 0-9  // 100-199  1\\d\\d  // 10-99
        std::regex ipv6("^([\\da-fA-F]{1,4}:){7}[\\da-fA-F]{1,4}$");
        bool ret = std::regex_match(queryIP,ipv4);
        bool ret_ = std::regex_match(queryIP,ipv6);
        if(ret==true)
            return "IPV4";
        if(ret_==true)
            return "IPV6";
        
        return "Neither";
    }

};

int main(){
    string t1 = "172.16.254.1";
    string t2 = "01.01.01.01";
    Solution s;
    string result = s.validIPAddress(t2);
    cout << result << endl;
}