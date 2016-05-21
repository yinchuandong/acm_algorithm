#include <iostream>
#include <cmath>
#include <string>
using namespace std;

class Solution {
public:
    int integerBreak(int n) {
        int *D = new int[n];
        for (int i = 0; i <= n; i ++){
            D[i] = 0;
        }
        for (int i = 1; i <= n; i ++){
            string line = "";
            for (int j = 1; j <= n; j ++){
                if (i + j <= n){
                    int a = fmax(D[i], i);
                    int b = fmax(D[j], j);
                    D[i + j] = fmax(a * b, D[i + j]);
                    line  += to_string(D[i + j]) + "\t";
                }else{
                    line = "0\t" + line;
                }
            }
            cout << line << endl;
        }
        int r = D[n];
        delete[] D;
        return r;
    }
};

int main(int argNums, char *args[]){
    Solution s;
    cout << "product: " << endl<< s.integerBreak(10);
    cout<<endl;
    return 0;
}