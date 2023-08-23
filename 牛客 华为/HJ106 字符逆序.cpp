


#include <iostream>
#include <string>
using namespace std;
 
int main(){
    string s;
    getline(cin, s);

    int l = 0;
    int r = s.size() - 1;

    while (l < r) {
        swap(s[l], s[r]); // 交换位置
        l ++ ;
        r -- ;
    }
    
    cout << s << endl;
    
    return 0;
}

