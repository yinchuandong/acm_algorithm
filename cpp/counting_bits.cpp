#include <iostream>

using namespace std;

class Solution {
public:
    int hammingWeight(uint32_t n) {
        int count = 0;
        while(n != 0){
            n = n & (n - 1);
            count ++;
        }
        return count; 
    }
};


int main(int argNum, char *args[]){
    Solution s;
    cout<<s.hammingWeight(1)<<endl;
	return 0;
}
