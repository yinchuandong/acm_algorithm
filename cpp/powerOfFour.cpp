#include <iostream>
using namespace std;

class Solution {
public:
    bool isPowerOfFour(int num) {
        return num > 0 && (num & (num - 1)) == 0  && (num & 0x55555555) != 0;
    }
};

int main(int argNum, char *args[]){
    Solution s;
    cout<<s.isPowerOfFour(1)<<endl;
	return 0;
}
