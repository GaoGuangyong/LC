

#include <iostream>
#include <string>
#include <vector>
#include <sstream>
using namespace std;
 
int main() {
    vector<pair<string, string>> sin = {{"reset",""}, {"reset","board"}, {"board","add"}, {"board","delete"}, {"reboot","backplane"}, {"backplane","abort"}};
    vector<string> sout = {"reset what", "board fault", "where to add", "no board at all", "impossible", "install first"};

    string str;
    while (getline(cin, str)) {
        // 读取字符串 str 中空格分开的单词到 ssin 字符串流
        stringstream ssin(str);
        // 将 ssin 字符串流的字符串读入 s1 和 s2
        string s1 , s2;
        ssin >> s1 >> s2;

		int count1 = 0, count2 = 0;

		string res;

		for (auto it = sin.begin(); it != sin.end(); it ++ ) {
            // 判断第一个关键字是否匹配
            int flag1;
            if (it->first.find(s1) == 0) flag1 = 1;
            else flag1 = 0;
            
			int flag2;
			if (s2 != "") {
                // 判断第二个关键字是否匹配
				if (it->second.find(s2) == 0) flag2 = 1;
                else flag2 = 0;
			}

            // 如果没有第二个关键字，默认匹配成功
            else if (s2 == "" && it->second == "") flag2 = 1;
			
            else flag2 = 0;
            
			if (flag1 == 1 && flag2 == 1) { // 两个关键字都匹配上了
				count1 ++ ;
				count2 ++ ;
				res = sout[it - sin.begin()];
			}
		}
        // 如果两个关键字都匹配成功，且只有一组匹配，则匹配成功
		if (count1 == 1 && count2 == 1) { 
			cout << res << endl;
		}
        // 如果匹配失败或有多组匹配，则匹配失败
        else {
			cout << "unknown command" << endl;
		}
	}
	return 0;
}


