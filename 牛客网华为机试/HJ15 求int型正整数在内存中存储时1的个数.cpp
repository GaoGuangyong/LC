
// ͬ��ָ Offer 15

#include <iostream>
using namespace std;

int main() {
    // �������� n
    int n;
    cin >> n;

    int res = 0;

    for (int i = 0; i < 32; i ++ ) {
        if ((n >> i & 1) == 1)
            res ++ ;
    }
    cout << res << endl;
    return 0;
}

