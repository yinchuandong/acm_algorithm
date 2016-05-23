#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> countBits(int num) {
        vector<int> ret(num + 1, 0);
        int powOf2 = 1;
        int last = 1;
        for (int i = 1; i <= num; i++){
            if (i == powOf2){
                last = ret[i] = 1;
                powOf2 = powOf2 << 1;
            }else{
                ret[i] = ret[last] + 1;
                last ++;
            }
        }
        return ret;      
    }
};


int main(int argNum, char *args[]){
    Solution s;
    vector<int> ret = s.countBits(8);
    for (int i = 0; i < ret.size(); i++){
        cout << ret[i] << ',';
    }
    cout <<endl;
	return 0;
}
