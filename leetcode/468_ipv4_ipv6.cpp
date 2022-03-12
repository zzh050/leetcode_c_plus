#include<vector>
#include<iostream>
#include<string>
#include<limits>
using namespace std;

/**
 * @brief 
 * 注意中间可能有多个分隔符连在以前 
 * 截出来的字符串为""需要判空
 * 
 */
class Solution {
public:
    string validIPAddress(string queryIP) {
        if(queryIP=="")
        return "Neither";
        string result = "";
        string delimiter_v4 = ".";
        string delimiter_v6 = ":";
        if(queryIP[queryIP.size()-1]==':'||queryIP[queryIP.size()-1]=='.')
            return "Neither";
        size_t size = queryIP.find_first_of(delimiter_v4);
        size_t size_ = queryIP.find_first_of(delimiter_v6);
        if(size!=string::npos){
            int tem = 0;
            vector<string> ipv4 = splitStr(queryIP,delimiter_v4);
            if(ipv4.size()!=4)
            {
                return "Neither";
            }
            for(int i=0;i<ipv4.size();i++){
                for(int j=0;j<ipv4[i].size();j++){
                    if(ipv4[i][j]>='0'&&ipv4[i][j]<='9'){}
                    else {
                        result = "Neither";
                        return result;
                    }
                }
                if(ipv4[i][0]=='0'&&ipv4[i].size()>1){
                result = "Neither";
                break;
                }
                if(ipv4[i].size()>3)
                    return "Neither";
                if(ipv4[i]!="")
                tem = stoi(ipv4[i]);
                else{
                    return "Neither";
                }
                if(tem<0||tem>255){
                    result = "Neither";
                    break;
                }
            }
            if(result!="Neither"){
                result = "IPv4";
            }
        }else if(size_!=string::npos){
            vector<string> ipv6 = splitStr(queryIP,delimiter_v6);
            if(ipv6.size()!=8)
            {
                return "Neither";
            }
            for(int i=0;i<ipv6.size();i++){
                // if(ipv6[i]=="0000"){
                //     result = "Neither";
                //     break;
                // }
                //判16进制
                // if(ipv6[i].size()==1&&ipv6[i][0]=='0'){
                //     if(ipv6[i][0]!='0')
                //     {
                //         result = "Neither";
                //         break;
                //     }
                    
                // }
                if(ipv6[i].size()<=4&&ipv6[i]!=""){
                    for(int j=0;j<ipv6[i].size();j++){
                        if((ipv6[i][j]>='a'&&ipv6[i][j]<='f')||(ipv6[i][j]>='A'&&ipv6[i][j]<='F')||(ipv6[i][j]>='0'&&ipv6[i][j]<='9'))
                        {}
                        else{
                            result = "Neither";
                            break;
                        }
                    }
                }
                else{
                    result = "Neither";
                    return result;
                }
                
            }
            if(result!="Neither"){
                result = "IPv6";
            }
        }

        return result;

    }

    vector<string> splitStr(const string& src, const string& delimiter) {
	std::vector<string> vtStr;
	// 入参检查
	// 1.原字符串为空返回空 vector
	if (src == "") {
		return vtStr;
	}
	// 2.分隔符为空返回单个元素为原字符串的 vector
	if (delimiter == "") {
		vtStr.push_back(src);
		return vtStr;
	}

	string::size_type startPos = 0;
	auto index = src.find_first_of(delimiter);
	while (index != string::npos) {
		auto str = src.substr(startPos, index - startPos);
		// if (str != "") {
		// 	vtStr.push_back(str);
		// }
        vtStr.push_back(str);
		startPos = index + 1;
		index = src.find_first_of(delimiter, startPos);
	}
	// 取最后一个子串
	auto str = src.substr(startPos);
	if (str != "") {
		vtStr.push_back(str);
	}

	return vtStr;
}
};

int main(){
    string t1 = "2001:0db8:85a3:0000:0000:8a2e:0370:7334";
    string t2 = "2001:db8:85a3:0:0:8A2E:0370:7334";
    string t3 = "2001:0db8:85a3::8A2E:037j:7334";
    string t4 = "02001:0db8:85a3:0000:0000:8a2e:0370:7334";
    string t5 = "2001:0db8:85a3:0:0:8A2E:0370:7334:";
    string t6 = "01.01.01.01";
    string t7 = "A.a.aA.2";
    string t8 = "2001:0db8:85a3:0:0:8A2E:0370:7334";
    string t9 = "2001:0db8:85a3:0:0:8A2E:0370:73341";
    string t10 = "2001:db8:85a3:0:0::8a2E:0370:7334";
    string t11 = "12..33.4";
    Solution s;
    string result = s.validIPAddress(t11);
    cout << result << endl;
}